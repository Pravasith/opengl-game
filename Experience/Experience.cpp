#include "Experience.h"
#include "VertexGroup.h"
#include <GLFW/glfw3.h>
#include <iostream>
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

  /* Starting Game Loop, loading Shaders and generating a */
  /* ShaderProgram */
  shaders = new Shaders();
  __shaderProgram = shaders->GetShaderProgram();

  // clang-format off
  GLfloat vertices[] = {
      -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
      0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
      0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f
  };

  /* std::cout << sizeof(vertices) << std::endl; */

  // clang-format on

  vertexGroup = new VertexGroup(vertices, sizeof(vertices));

  /* Starting GameLoop
   *  ------------------------------------------------------------------------
   */
  GameLoop();

  /*  Optional: de-allocate all resources once they've outlived their purpose:
   *  ------------------------------------------------------------------------
   */
  /* vertexGroup->ClearBuffers(); */
  /* shaders->DeleteShaderProgram(); */

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

  vertexGroup->BindVAO();
  vertexGroup->DrawArrays();
}

Window *Experience::window = nullptr;
Shaders *Experience::shaders = nullptr;
VertexGroup *Experience::vertexGroup = nullptr;

char *Experience::__pwd = nullptr;
GLFWwindow *Experience::__glfwWindow = nullptr;
GLuint Experience::__shaderProgram = 0;