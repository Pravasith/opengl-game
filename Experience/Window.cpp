
// clang-format off
#include "../Headers/Callbacks.h"
// clang-format on
#include "../Headers/Window.h"
#include "../Headers/Utilities.h"
#include <cstdint>
#include <iostream>

Window::Window() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

Window *Window::Get() {
  static Window *instance = nullptr;

  if (!instance) {
    instance = new Window();
  }

  return new Window();
}

GLFWwindow *Window::getGLFWWindow() { return __glfwWindow; }

void Window::Create(const char *name, const uint32_t &width,
                    const uint32_t &height) {
  __glfwWindow = glfwCreateWindow(800, 800, extract_version(name), NULL, NULL);

  if (__glfwWindow == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    Destroy();
  }

  glfwMakeContextCurrent(__glfwWindow);
  glfwSetErrorCallback(glfw_error_callback);
  glfwSetWindowCloseCallback(__glfwWindow, glfw_window_close_callback);
  glfwSetFramebufferSizeCallback(__glfwWindow, glfw_framebuffer_size_callback);
}

void Window::Destroy() {
  glfwDestroyWindow(__glfwWindow);
  glfwTerminate();
}

void Window::BgClearColor() {
  glClearColor(.3f, .2f, .3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

GLFWwindow *Window::__glfwWindow = nullptr;
