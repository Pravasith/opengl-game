// clang-format off
#include <glad/glad.h>
//
// clang-format on
#include "Algorithms/QuickSort.h"
#include "CopyPaste/CopyPaste.h"
#include "Messages/Engineer.h"
#include "ResumeContent/CraftResume.h"

#include <GLFW/glfw3.h>

#include <cstdlib>
#include <iostream>
#include <string>

int main() {
  /* Clipboard clipboard; */
  /* std::string currentString; */
  /* clipboard.PasteStringFromClipboard(currentString); */
  /* clipboard.CopyStringToClipboard(currentString); */
  /* std::cout << currentString << '\n'; */
  /* Engineer engineer; */
  /* CraftResume craftResume; */
  /* craftResume.Init(); */

  /* glfwInit(); */
  /* glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); */
  /* glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); */
  /* glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); */
  /* // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); */
  /*  */
  /* GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
   */
  /* if (window == NULL) { */
  /*   std::cout << "Failed to create GLFW window" << std::endl; */
  /*   glfwTerminate(); */
  /*   return -1; */
  /* } */
  /* glfwMakeContextCurrent(window); */
  /*  */
  /* if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { */
  /*   std::cout << "Failed to initialize GLAD" << std::endl; */
  /*   return -1; */
  /* } */
  /*  */
  /* glViewport(0, 0, 800, 600); */
  QuickSort qs;
  qs.sort();

  return EXIT_SUCCESS;
}
