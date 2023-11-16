#include "Experience.h"
#include "../Headers/Window.h"
#include "../Shaders/Shaders.h"

#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <ostream>

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
  window->Create(__pwd);
  __glfwWindow = window->getGLFWWindow();

  LoadOpenGL();
  const char *VERTEX_SHADER_PATH = "../../assets/vertex.glsl";
  const char *FRAGMENT_SHADER_PATH = "../../assets/fragment.glsl";

  shaders = new Shaders(VERTEX_SHADER_PATH, FRAGMENT_SHADER_PATH);

  /* Starting Game Loop, loading Shaders and generating a */
  /* ShaderProgram */

  // clang-format off
  GLfloat vertices[] = {
      /* CO-ORDINATES                          | COLORS          */
      -.5f, -.5f * float(sqrt(3)) / 3, .0f,      .8f, .8f, .0f, // lower left corner
       .5f, -.5f * float(sqrt(3)) / 3, .0f,      .8f, .0f, .8f, // lower right corner
       .0f,  .5f * float(sqrt(3)) * 2 / 3, .0f,  .0f, .8f, .8f, // upper corner
      /* CO-ORDINATES                          | COLORS          */
      -.5f / 2, .5f * float(sqrt(3)) / 6, .0f,   .8f, .8f, .8f, // inner left
       .5f / 2, .5f * float(sqrt(3)) / 6, .0f,   .8f, .8f, .8f, // inner right
       .0f,  -.5f * float(sqrt(3)) / 3, .0f,     .8f, .8f, .8f, // inner down
      /* CO-ORDINATES                          | COLORS          */
  };

  GLuint elements[] = {
    0, 3, 5,
    3, 2, 4,
    5, 4, 1
  };
  // clang-format on

  // Generates Vertex Array Object and binds it
  vao = new VAO;
  vao->Bind();

  // Generates Vertex Buffer Object and links it to vertices
  vbo = new VBO(vertices, sizeof(vertices));
  // Generates Element Buffer Object and links it to indices
  ebo = new EBO(elements, sizeof(elements));
  ebo->Bind();

  // Links VBO attributes such as coordinates and colors to VAO
  vao->LinkAttrib(*vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void *)0);
  vao->LinkAttrib(*vbo, 1, 3, GL_FLOAT, 6 * sizeof(float),
                  (void *)(3 * sizeof(float)));

  // Unbind all to prevent accidentally modifying them
  vao->Unbind();
  vbo->Unbind();
  ebo->Unbind();

  /* Starting GameLoop
   *  ------------------------------------------------------------------------
   */
  GameLoop();

  // Delete all the objects we've created
  vao->Delete();
  vbo->Delete();
  ebo->Delete();
  shaders->DeleteShaderProgram();

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
  shaders->UseShaderProgram();

  // Bind the VAO so OpenGL knows to use it
  vao->Bind();
  // Draw primitives, number of indices, datatype of indices, index of indices
  glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
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
}

Window *Experience::window = nullptr;
Shaders *Experience::shaders = nullptr;

VBO *Experience::vbo = nullptr;
EBO *Experience::ebo = nullptr;
VAO *Experience::vao = nullptr;

char *Experience::__pwd = nullptr;
GLFWwindow *Experience::__glfwWindow = nullptr;
