#include "CraftResume.h"
#include <filesystem> // C++17 and later
#include <fstream>
#include <iostream>
#include <string>

using std::string;
namespace fs = std::filesystem;

void CraftResume::Init() {
  string choice;

  /* string __summary, __work_exp, __skills, __hobbies; */

  while (choice.compare("Q") != 0) {
    std::cout << "0. Summary\n";
    std::cout << "1. Work Exp\n";
    std::cout << "2. Skills\n";
    std::cout << "3. Hobbies\n";
    std::getline(std::cin, choice);
    std::cout << choice << '\n';

    if (choice.compare("0") == 0) {
      EditSummary();
    } else if (choice.compare("1") == 0) {
    } else if (choice.compare("2") == 0) {
    } else if (choice.compare("3") == 0) {
    }

    std::cout << "\nQ to quit\n";
    std::cout << "Any to continue\n";
    std::getline(std::cin, choice);
  }
}

void CraftResume::EditSummary() {
  string choice;

  std::cout << "\n0. Choose Summary\n";
  std::cout << "1. Edit Summary\n";
  std::cout << "2. Next Summary\n";
  std::cout << "3. Prev Summary\n";
  std::getline(std::cin, choice);

  LoadSummary();

  if (choice.compare("0") == 0) {
    /* GetSummary(); */
  } else if (choice.compare("1") == 0) {
  } else if (choice.compare("2") == 0) {
  } else if (choice.compare("3") == 0) {
  }
}

void CraftResume::LoadSummary() {
  string output;

  std::ifstream ifs;
  ifs.open(__dirPath);

  if (!fs::exists(__dirPath))
    std::cout << "ERROR: The file " << __dirPath << " doesn't exist!\n";

  if (!ifs.is_open())
    std::cout << "ERROR: File Not Open" << '\n';
  else {
    string value;

    while (ifs.good()) {
      std::getline(ifs, value, '\n');
      __summaries.push_back(value);
    }

    output += value;
  }

  std::cout << __summaries[0] << std::endl;
}
