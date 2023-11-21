#pragma once

#include <GLFW/glfw3.h>

class Window {
public:
  static Window *Get();

  GLFWwindow *getGLFWWindow();
  void Create(const char *name, const uint32_t &width, const uint32_t &height);
  void Destroy();
  void BgClearColor();

private:
  Window();

  static GLFWwindow *__glfwWindow;
};
