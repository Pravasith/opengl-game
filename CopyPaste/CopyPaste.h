#pragma once

#include <string>

class Clipboard {
public:
  void GetString(std::string &clipboardStr);
  void SetString(std::string copyString);
};
