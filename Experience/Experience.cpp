#include "Experience.h"

Experience::Experience() {
  /* Create a GLFW Window and use it for GameLoop */
  window = Window::Get();
  GameLoop();
}

void Experience::GameLoop() {
  window->Create("/_ARDNA_");

  // Actual GameLoop
  while (!glfwWindowShouldClose(window->getGLTFWindow())) {
    Update();

    /* Swap front and back buffers */
    glfwSwapBuffers(window->getGLTFWindow());
    /* Poll for and process events */
    glfwPollEvents();
  }

  window->Destroy();
}

Window *Experience::window = nullptr;
