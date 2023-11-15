#pragma once

#include "../Shaders/Shaders.h"
#include "VertexGroup.h"
#include "Window.h"
#include <iostream>
#include <string>

class Experience {
public:
  Experience();

  // Singleton
  static Experience *Get(char *dir);

  void GameLoop();
  void Update();

private:
  static Window *window;
  static VertexGroup *vertexGroup;
  static Shaders *shaders;

  static char *__pwd;
  static GLFWwindow *__glfwWindow;
  static GLuint __shaderProgram;
};
