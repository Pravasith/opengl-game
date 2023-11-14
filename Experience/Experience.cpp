#include "Experience.h"

Experience *Experience::Get(char *dir) {
  pwd = dir;
  static Experience *instance = nullptr;

  if (!instance) {
    instance = new Experience();
  }

  return instance;
}

Experience::Experience() {
  /* Create a GLFW Window and use it for GameLoop */
  window = Window::Get();
  window->Create(pwd);
  GameLoop();
  shaders = new Shaders();
  window->Destroy();
}

void Experience::GameLoop() {

  while (!glfwWindowShouldClose(window->getGLTFWindow())) {
    /* Update(); */

    /* Swap front and back buffers */
    glfwSwapBuffers(window->getGLTFWindow());
    /* Poll for and process events */
    glfwPollEvents();
  }
}

void Experience::Update() {}

Window *Experience::window = nullptr;
char *Experience::pwd = nullptr;
Shaders *Experience::shaders = nullptr;
