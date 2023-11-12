#pragma once

#include "../Headers/Callbacks.h"
#include "../Headers/Utilities.h"
#include <GLFW/glfw3.h>
#include <iostream>

struct Window {
  static Window *Get(const char *name) {
    static Window *instance = nullptr;
    if (!instance) {
      instance = new Window(name);
    }

    return instance;
  }

private:
  GLFWwindow *window = nullptr;

  Window(const char *name) {
    Init();
    Create(name);
    GameLoop();
    Destroy();
  }

  void Init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
  }

  void Create(const char *name) {
    window = glfwCreateWindow(800, 800, extract_version(name), NULL, NULL);

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(glfw_error_callback);
    glfwSetWindowCloseCallback(window, glfw_window_close_callback);
    glfwSetFramebufferSizeCallback(window, glfw_framebuffer_size_callback);
  }

  void Destroy() { glfwTerminate(); }

  void GameLoop() {
    while (!glfwWindowShouldClose(window)) {

      /* Swap front and back buffers */
      glfwSwapBuffers(window);

      /* Poll for and process events */
      glfwPollEvents();
    }
  }
};
