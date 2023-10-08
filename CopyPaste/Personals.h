#pragma once

#include <string>
using std::string;

class CopyToClipboard {
public:
  CopyToClipboard();
  void GetClipboard();
  void SetClipboard(string);

private:
  string __firstName;
  string __clipboard;
};
