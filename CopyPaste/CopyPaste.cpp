#include "CopyPaste.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
using std::string;

void Clipboard::PasteStringFromClipboard(string &clipBoardString) {
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

/* @only-windows
 * @windows only function
 */
void Clipboard::CopyStringToClipboard(const string clipBoardString) {
  // Use system() to run the clip.exe command
  std::string command = "echo \"" + clipBoardString + "\" | clip.exe";
  int result = std::system(command.c_str());

  if (result == 0) {
    // Successfully set clipboard text
    /* std::cout << 1; */
  } else {
    // There was an error
    /* std::cout << 0; */
  }
}
