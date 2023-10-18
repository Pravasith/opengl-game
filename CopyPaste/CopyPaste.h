#pragma once

#include <string>

class Clipboard {
public:
  static void PasteStringFromClipboard(std::string &clipboardStr);
  static void CopyStringToClipboard(std::string clipboardStr);
};
