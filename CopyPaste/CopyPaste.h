#pragma once

#include <string>

class Clipboard {
public:
  void PasteStringFromClipboard(std::string &clipboardStr);
  void CopyStringToClipboard(std::string clipboardStr);
};
