#include "CopyPaste.h"
#include "../include/glfw3.h"

#include <iostream>
#include <string>
using std::string;

void Clipboard::GetString(string &clipBoardString) {
  string copiedValue;
  int a = glfwInit();

  const char *textPtr = glfwGetClipboardString(NULL);

  string text;

  int c = 0;

  while (textPtr) {
    char currChar = *(textPtr + c);
    char endChar = '\0';

    if (currChar == endChar)
      break;

    copiedValue += currChar;
    c++;
  };

  clipBoardString = copiedValue;
}

void Clipboard::SetString(string clipBoardString) {}
