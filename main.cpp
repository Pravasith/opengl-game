#include "CopyPaste/CopyPaste.h"
#include <cstdlib>
#include <iostream>
#include <string>

int main() {
  Clipboard clipboard;

  std::string currentString;
  clipboard.GetString(currentString);

  std::cout << currentString << '\n';

  return EXIT_SUCCESS;
}
