#pragma once
/* clang-format off */
#include <glad/glad.h>
/* clang-format on */

class Shaders {
public:
  Shaders(const GLchar *vertexShaderSrc, const GLchar *fragmentShaderSrc);

  GLuint GetShaderProgram();
  void DeleteShaderProgram();
  void UseShaderProgram();

private:
  GLuint __shaderProgram = 0;
  GLuint vertexShader = 0;
  GLuint fragmentShader = 0;

  // For debugging
  int success;
  char infoLog[512];

  void LoadVertexShader(const GLchar *vertexShaderPath);
  void LoadFragmentShader(const GLchar *vertexShaderPath);

  void CreateShaderProgram();
  void DeleteShaders();
};
