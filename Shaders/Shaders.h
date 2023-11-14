#pragma once

#include "../Headers/Utilities.h"
/* clang-format off */
#include <glad/glad.h>
/* clang-format on */
/* #include <GLFW/glfw3.h> */

#include <iostream>
#include <string>

class Shaders {
public:
  Shaders() { Init(); }

private:
  void Init() {
    if (!gladLoadGL()) {
      std::cout << "Failed to initialize GLAD" << std::endl;
    }

    /* Load Vertex Shader */
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    std::string vertexShaderSrc = load_shader("../../Shaders/vertex.glsl");

    const GLchar *vertexShaderSource = vertexShaderSrc.c_str();
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];

    // check for shader compile errors
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                << infoLog << std::endl;
    }

    /* Load Fragment Shader  */
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    std::string fragmentShaderSrc = load_shader("../../Shaders/fragment.glsl");

    const GLchar *fragmentShaderSource = fragmentShaderSrc.c_str();
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                << infoLog << std::endl;
    }

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
  }
};
