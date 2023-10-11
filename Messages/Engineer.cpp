#include "Engineer.h"
#include <filesystem> // C++17 and later
#include <fstream>
#include <iostream>
#include <set>
#include <string>

using std::string;
namespace fs = std::filesystem;

Engineer::Engineer() {
  std::set<string> template_strings = {"<F_NAME>", "<DISCOVERY>",
                                       "<LIKES>",  "<PAGE_LINK>",
                                       "<NO_EXP>", "<NO_EXP_LIKE>"};

  string fName;
  string discovery;
  string likes;
  string pageLink;
  string noExp;
  string noExpLike;

  const string dirPath = "../../Database/FriendlyMessage.csv";

  string output = "NADA";

  std::ifstream ifs;
  ifs.open(dirPath);

  if (!fs::exists(dirPath))
    std::cout << "ERROR: The file " << dirPath << " doesn't exist!\n";

  if (!ifs.is_open())
    std::cout << "ERROR: File Not Open" << '\n';
  else {
    string value;

    while (ifs.good()) {
      std::getline(ifs, value, ' ');
      std::cout << value << '\n';

      const bool hasTemplate =
          template_strings.find(value) != template_strings.end();

      if (hasTemplate) {
        if (value == "<F_NAME>") {
          value = fName;
        } else if (value == "<DISCOVERY>") {
          value = discovery;
        } else if (value == "<LIKES>") {
          value = likes;
        } else if (value == "<PAGE_LINK>") {
          value = pageLink;
        } else if (value == "<NO_EXP>") {
          value = noExp;
        } else if (value == "<NO_EXP_LIKE>") {
          value = noExpLike;
        }
      }

      output += value;
    }

    std::cout << output << std::endl;
  }
}

Engineer::~Engineer() {}
