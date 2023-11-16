#pragma once

#include "../Headers/BufferObjects.h"
#include "../Headers/Window.h"
#include "../Shaders/Shaders.h"
#include <iostream>
#include <string>

class Experience {
public:
  static Experience *Get(char *dir);

private:
  Experience();
  ~Experience();

  void GameLoop();
  void Update();
  void LoadOpenGL();
  void CleanUp();

  static Window *window;
  static Shaders *shaders;
  static VBO *vbo;
  static EBO *ebo;
  static VAO *vao;

  static char *__pwd;
  static GLFWwindow *__glfwWindow;
};
