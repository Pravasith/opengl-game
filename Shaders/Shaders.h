#pragma once

#include "../Headers/Utilities.h"
/* clang-format off */
#include <glad/glad.h>
/* clang-format on */

#include <iostream>
#include <string>

class Shaders {
public:
  Shaders() { Init(); }

  GLuint GetShaderProgram() { return __shaderProgram; }
  void DeleteShaderProgram() { glDeleteProgram(__shaderProgram); }
  void UseShaderProgram() {
    /* std::cout << __shaderProgram << '\n'; */
    glUseProgram(__shaderProgram);
  }

private:
  void Init() {
    if (!gladLoadGL()) {
      std::cout << "Failed to initialize GLAD" << std::endl;
    }

    /* Load Vertex Shader */
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
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
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
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

    __shaderProgram = glCreateProgram();
    glAttachShader(__shaderProgram, vertexShader);
    glAttachShader(__shaderProgram, fragmentShader);
    glLinkProgram(__shaderProgram);

    // check for linking errors
    glGetProgramiv(__shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(__shaderProgram, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
  }

  GLuint __shaderProgram = 0;
};
