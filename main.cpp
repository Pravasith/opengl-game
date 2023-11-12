// clang-format off
#include <glad/glad.h>
// clang-format on
#include <cmath>
#include <cstdint>

#include <GLFW/glfw3.h>

#include "Experience/Window.h"
#include "Headers/Input.h"
#include <cstdlib>
#include <iostream>

const char *vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

int main(int argc, char **argv) {

  /*  */
  /* gladLoadGL(); */
  /* unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER); */
  /* glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); */
  /* glCompileShader(vertexShader); */
  /*  */
  /* unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); */
  /* glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL); */
  /* glCompileShader(fragmentShader); */
  /*  */
  /* unsigned int shaderProgram = glCreateProgram(); */
  /* glAttachShader(shaderProgram, vertexShader); */
  /* glAttachShader(shaderProgram, fragmentShader); */
  /* glLinkProgram(shaderProgram); */
  /*  */
  /* glDeleteShader(vertexShader); */
  /* glDeleteShader(fragmentShader); */
  /*  */
  /* // clang-format off */
  /* GLfloat vertices[] = { */
  /*   -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, */
  /*    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, */
  /*    0.0f,  0.5f * float(sqrt(3)) * 2 / 3, 0.0f */
  /* }; */
  /* // clang-format on */
  /*  */
  /* unsigned int VBO, VAO; */
  /* glGenVertexArrays(1, &VAO); */
  /* glGenBuffers(1, &VBO); */
  /*  */
  /* glBindVertexArray(VAO); */
  /*  */
  /* glBindBuffer(GL_ARRAY_BUFFER, VBO); */
  /* glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
   */
  /*  */
  /* glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void
   * *)0); */
  /* glEnableVertexAttribArray(0); */
  /*  */
  /* glBindBuffer(GL_ARRAY_BUFFER, 0); */
  /* glBindVertexArray(0); */
  /*  */
  /*  */
  /* // optional: de-allocate all resources once they've outlived their purpose:
   */
  /* // ------------------------------------------------------------------------
   */
  /* glDeleteVertexArrays(1, &VAO); */
  /* glDeleteBuffers(1, &VBO); */
  /* glDeleteProgram(shaderProgram); */
  /*  */

  Window *window = nullptr;
  window = Window::Get("/Andra");

  /* while (!glfwWindowShouldClose(window)) { */
  /* ProcessInput(window); */
  /*    */
  /* glClearColor(0.2f, 0.3f, 0.3f, 1.0f); */
  /* glClear(GL_COLOR_BUFFER_BIT); */
  /*  */
  /* glUseProgram(shaderProgram); */
  /* glBindVertexArray(VAO); */
  /* glDrawArrays(GL_TRIANGLES, 0, 3); */
  /*    */
  /* glfwSwapBuffers(window); */
  /* glfwPollEvents(); */
  /* } */

  return EXIT_SUCCESS;
}
