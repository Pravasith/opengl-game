
// clang-format off
#include <glad/glad.h>
// clang-format on

#include <GLFW/glfw3.h>

#include "Callbacks/Callbacks.h"
#include <cstdlib>

int main() {
  glfwSetErrorCallback(glfw_error_callback);
  glfwInit();

  GLFWwindow *window =
      glfwCreateWindow(1200, 800, "DSA Game!!", nullptr, nullptr);

  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  glfwSetWindowCloseCallback(window, glfw_window_close_callback);

  while (!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return EXIT_SUCCESS;
}
