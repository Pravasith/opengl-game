#pragma once

#include <GLFW/glfw3.h>

class Window {
public:
  static Window *Get();

  GLFWwindow *getGLFWWindow();
  void Create(const char *name);
  void Destroy();
  void BgClearColor();

private:
  Window();

  static GLFWwindow *__glfwWindow;
};
