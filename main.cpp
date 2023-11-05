// clang-format off
#include <glad/glad.h>
// clang-format on

#include <GLFW/glfw3.h>

#include "Headers/Callbacks.h"
#include "Headers/Utilities.h"
#include <cstdlib>

int main(int argc, char **argv) {
  glfwSetErrorCallback(glfw_error_callback);
  glfwInit();

  /* glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); */
  /* glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6); */

  GLFWwindow *window =
      glfwCreateWindow(1200, 800, extract_version(argv[0]), nullptr, nullptr);

  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  glfwSetWindowCloseCallback(window, glfw_window_close_callback);
  /* glfwSetFramebufferSizeCallback(window, glfw_frame_buffer_callback); */

  while (!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return EXIT_SUCCESS;
}
