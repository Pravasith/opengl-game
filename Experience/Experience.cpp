#include "Experience.h"
#include "../Headers/Utilities.h"
#include "../Headers/Window.h"
#include "../Shaders/Shaders.h"
#include "../vendor/stb_image/stb_image.cpp"

#include <GLFW/glfw3.h>
#include <cstdint>
#include <iostream>
#include <math.h>
#include <ostream>
#include <vector>

const uint32_t n = 7;
unsigned int texture;

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

  // TEXTURES TEXTURES TEXTURES TEXTURES TEXTURES TEXTURES
  // TEXTURES TEXTURES TEXTURES TEXTURES TEXTURES TEXTURES

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  // set the texture wrapping/filtering options (on the currently bound texture
  // object)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  // load and generate the texture
  int width, height, nrChannels;
  unsigned char *data = stbi_load("../../assets/textures/sukuna_hd.png", &width,
                                  &height, &nrChannels, 0);

  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture" << std::endl;
  }
  stbi_image_free(data);

  // TEXTURES TEXTURES TEXTURES TEXTURES TEXTURES TEXTURES
  // TEXTURES TEXTURES TEXTURES TEXTURES TEXTURES TEXTURES

  /* Starting GameLoop
   *  ------------------------------------------------------------------------
   */
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
  shaders->UseShaderProgram();

  glBindTexture(GL_TEXTURE_2D, texture);
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
}

Window *Experience::window = nullptr;
Shaders *Experience::shaders = nullptr;

VBO *Experience::vbo = nullptr;
EBO *Experience::ebo = nullptr;
VAO *Experience::vao = nullptr;

char *Experience::__pwd = nullptr;
GLFWwindow *Experience::__glfwWindow = nullptr;
