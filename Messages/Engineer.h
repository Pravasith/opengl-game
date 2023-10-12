#pragma once

#include <iostream>
using std::string;

class Engineer {
public:
  Engineer();
  ~Engineer();

private:
  string __fName = "";
  string __discovery = "";
  string __likes = "";
  string __pageLink = "";
  string __noExp = "";
  string __noExpLike = "";

  const string __dirPath = "../../Database/FriendlyMessage.csv";

  void PromptQuestions();
  void Init();
  void ReplaceTemplateStrings();
};
