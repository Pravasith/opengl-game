#pragma once

#include "Window.h"

class Experience {
public:
  static Experience *Get() {
    static Experience *instance = nullptr;

    if (!instance) {
      instance = new Experience();
    }

    return instance;
  }

private:
  Experience() {
    Window *window = Window::Get();
    window->Create("/_ANDRA_PRAV_");
    window->GameLoop();
    window->Destroy();
  }
};
