#include "../Headers/Utilities.h"
/* clang-format off */
#include <glad/glad.h>
/* clang-format on */
#include "Shaders.h"

#include <iostream>
#include <string>

Shaders::Shaders(const GLchar *vertexShaderPath,
                 const GLchar *fragmentShaderPath) {
  LoadVertexShader(vertexShaderPath);
  LoadFragmentShader(fragmentShaderPath);
  CreateShaderProgram();
};

void Shaders::CreateShaderProgram() {
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
}

GLuint Shaders::GetShaderProgram() { return __shaderProgram; }

void Shaders::UseShaderProgram() { glUseProgram(__shaderProgram); }

void Shaders::DeleteShaderProgram() { glDeleteProgram(__shaderProgram); }

void Shaders::DeleteShaders() {
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shaders::LoadVertexShader(const GLchar *vertexShaderPath) {
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  /* Load Vertex Shader */
  std::string vertexShaderSrcCode = load_shader(vertexShaderPath);

  const GLchar *vertexShaderSource = vertexShaderSrcCode.c_str();
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  // check for shader compile errors
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
};

void Shaders::LoadFragmentShader(const GLchar *fragmentShaderPath) {
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  /* Load Vertex Shader */
  std::string fragmentShaderSrcCode = load_shader(fragmentShaderPath);

  const GLchar *fragmentShaderSource = fragmentShaderSrcCode.c_str();
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  // check for shader compile errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
};
