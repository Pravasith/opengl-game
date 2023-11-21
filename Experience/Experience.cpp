#include "Experience.h"
#include "../Headers/Utilities.h"
#include "../Headers/Window.h"
#include "../Shaders/Shaders.h"

#include <GLFW/glfw3.h>
#include <cstdint>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <math.h>
#include <ostream>
#include <vector>

const uint32_t n = 24;

Experience *Experience::Get(char *dir) {
  __pwd = dir;
  static Experience *instance = nullptr;

  if (!instance) {
    instance = new Experience();
  }

  return instance;
}

Experience::Experience() {
  /* Create a GLFW Window and use it for GameLoop */
  window = Window::Get();
  window->Create(__pwd, 800, 800);
  __glfwWindow = window->getGLFWWindow();

  LoadOpenGL();
  const char *VERTEX_SHADER_PATH = "../../assets/vertex.glsl";
  const char *FRAGMENT_SHADER_PATH = "../../assets/fragment.glsl";

  shaders = new Shaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

  std::vector<GLfloat> vertices;
  std::vector<GLuint> elements;

  generate_n_gon(n, elements, vertices);

  // Generates Vertex Array Object and binds it
  vao = new VAO;
  vao->Bind();

  // Generates Vertex Buffer Object and links it to vertices
  vbo = new VBO(vertices.data(), (vertices.size() * sizeof(GLfloat)));
  // Generates Element Buffer Object and links it to indices
  ebo = new EBO(elements.data(), (elements.size() * sizeof(GLuint)));
  ebo->Bind();

  // Links VBO attributes such as coordinates and colors to VAO
  vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *)0);
  vao->LinkAttrib(*vbo, 1, 3, GL_FLOAT, 8 * sizeof(float),
                  (void *)(3 * sizeof(float)));
  vao->LinkAttrib(*vbo, 2, 2, GL_FLOAT, 8 * sizeof(float),
                  (void *)(6 * sizeof(float)));

  // Unbind all to prevent accidentally modifying them
  vao->Unbind();
  vbo->Unbind();
  ebo->Unbind();

  // Initiate textures
  texture =
      new Texture("../../assets/textures/sam_altman_hd.png", GL_TEXTURE_2D);

  // Game loop
  GameLoop();

  CleanUp();
  window->Destroy();
}

void Experience::GameLoop() {
  while (!glfwWindowShouldClose(__glfwWindow)) {
    Update();

    /* Swap front and back buffers */
    glfwSwapBuffers(__glfwWindow);
    /* Poll for and process events */
    glfwPollEvents();
  }
}

void Experience::Update() {
  window->BgClearColor();
  // create transformations

  shaders->UseShaderProgram();

  // Bind texture
  texture->Bind();

  // create transformations
  glm::mat4 model = glm::mat4(
      1.0f); // make sure to initialize matrix to identity matrix first
  glm::mat4 view = glm::mat4(1.0f);
  glm::mat4 projection = glm::mat4(1.0f);
  model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
  view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
  projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)800,
                                0.1f, 100.0f);
  // retrieve the matrix uniform locations
  unsigned int modelLoc =
      glGetUniformLocation(shaders->GetShaderProgram(), "model");
  unsigned int viewLoc =
      glGetUniformLocation(shaders->GetShaderProgram(), "view");
  // pass them to the shaders (3 different ways)
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
  glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
  // note: currently we set the projection matrix each frame, but since the
  // projection matrix rarely changes it's often best practice to set it outside
  // the main loop only once.
  glUniformMatrix4fv(
      glGetUniformLocation(shaders->GetShaderProgram(), "projection"), 1,
      GL_FALSE, &projection[0][0]);

  // Bind the VAO so OpenGL knows to use it
  vao->Bind();
  // Draw primitives, number of indices, datatype of indices, index of indices
  glDrawElements(GL_TRIANGLES, 3 * n, GL_UNSIGNED_INT, 0);
}

void Experience::CleanUp() {
  // Delete all the objects we've created
  vao->Delete();
  vbo->Delete();
  ebo->Delete();
  shaders->DeleteShaderProgram();
}

void Experience::LoadOpenGL() {
  if (!gladLoadGL()) {
    std::cout << "Failed to initialize GLAD" << std::endl;
  }
}

Experience::~Experience() {
  delete vao;
  delete vbo;
  delete ebo;
  delete window;
  delete shaders;
  delete texture;
}

Window *Experience::window = nullptr;
Shaders *Experience::shaders = nullptr;

VBO *Experience::vbo = nullptr;
EBO *Experience::ebo = nullptr;
VAO *Experience::vao = nullptr;

Texture *Experience::texture = nullptr;

char *Experience::__pwd = nullptr;
GLFWwindow *Experience::__glfwWindow = nullptr;
