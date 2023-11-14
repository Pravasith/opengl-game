#pragma once

#include "Window.h"
#include <iostream>

class Experience {
public:
  Experience();

  // Singleton
  static Experience *Get() {
    static Experience *instance = nullptr;

    if (!instance) {
      instance = new Experience();
    }

    return instance;
  }

  void GameLoop();
  void Update();

private:
  static Window *window;
};
