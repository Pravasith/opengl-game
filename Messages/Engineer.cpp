#include "Engineer.h"
#include <filesystem> // C++17 and later
#include <fstream>
#include <iostream>
#include <set>
#include <string>

using std::string;
namespace fs = std::filesystem;

Engineer::Engineer() { Init(); }
Engineer::~Engineer() {}

void Engineer::Init() {
  string choice;

  while (choice.compare("Q") != 0) {
    std::cout << "First name?\n";
    std::getline(std::cin, __fName);

    std::cout << "Discovery?\n";
    std::getline(std::cin, __discovery);

    std::cout << "Likes?\n";
    std::getline(std::cin, __likes);

    std::cout << "Page Link?\n";
    std::getline(std::cin, __pageLink);

    std::cout << "No Exp?\n";
    std::getline(std::cin, __noExp);

    std::cout << "No Exp Like?\n";
    std::getline(std::cin, __noExpLike);

    ReplaceTemplateStrings();

    std::cout << "Press Q to quit.\nOr any other key to continue...\n";
    std::getline(std::cin, choice);
  }
}

void Engineer::ReplaceTemplateStrings() {
  std::set<string> template_strings = {"<F_NAME>", "<DISCOVERY>",
                                       "<LIKES>",  "<PAGE_LINK>",
                                       "<NO_EXP>", "<NO_EXP_LIKE>"};

  string output;

  std::ifstream ifs;
  ifs.open(__dirPath);

  if (!fs::exists(__dirPath))
    std::cout << "ERROR: The file " << __dirPath << " doesn't exist!\n";

  if (!ifs.is_open())
    std::cout << "ERROR: File Not Open" << '\n';
  else {
    string value;
    bool delimiterStart = 0;

    while (ifs.good()) {
      if (delimiterStart) {
        std::getline(ifs, value, '>');

        if (value == "F_NAME") {
          value = __fName;
        } else if (value == "DISCOVERY") {
          value = __discovery;
        } else if (value == "LIKES") {
          value = __likes;
        } else if (value == "PAGE_LINK") {
          value = __pageLink;
        } else if (value == "NO_EXP") {
          value = __noExp;
        } else if (value == "NO_EXP_LIKE") {
          value = __noExpLike;
        }

        delimiterStart = 0;
      } else {
        std::getline(ifs, value, '<');
        delimiterStart = 1;
      }

      output += value;
    }

    std::cout << output << std::endl;
  }
}
