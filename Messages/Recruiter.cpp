#include "Recruiter.h"
#include "../include/glfw3.h"
#include <iostream>
#include <string>
#include <vector>

Recruiter::Recruiter() {}
Recruiter::~Recruiter() {}

void Recruiter::SetRecruiter(int data) {
  /* GLFWwindow *window; */

  int a = glfwInit();

  const char *text = glfwGetClipboardString(NULL);
  std::string copiedValue;

  int c = 0;

  if (text) {
    while (text) {

      char currChar = *(text + c);
      char endChar = '\0';

      if (currChar == endChar)
        break;

      copiedValue += currChar;
      c++;
    }
  }

  std::cout << copiedValue << "\n";

  __recruiter = data + a;
}

void Recruiter::GetRecruiter(int &data) { data = __recruiter; }

int Recruiter::GetRecruiter() { return __recruiter; }
