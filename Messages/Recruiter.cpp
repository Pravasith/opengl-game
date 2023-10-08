#include "Recruiter.h"
#include "../include/glfw3.h"
#include <iostream>

Recruiter::Recruiter() {}
Recruiter::~Recruiter() {}

void Recruiter::SetRecruiter(int data) {
  /* GLFWwindow *window; */

  int a = glfwInit();

  const char *text = glfwGetClipboardString(NULL);

  if (text) {
    std::cout << *(text + 1);
  }

  __recruiter = a;
}

void Recruiter::GetRecruiter(int &data) { data = __recruiter; }

int Recruiter::GetRecruiter() { return __recruiter; }
