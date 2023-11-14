#pragma once

#include "../Shaders/Shaders.h"
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
  static char *pwd;
  static Shaders *shaders;
};
