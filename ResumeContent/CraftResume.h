#pragma once

#include <string>
#include <vector>

class CraftResume {
public:
  void Init();

private:
  inline static const std::string __dirPath = "../../Database/Summaries.csv";
  std::vector<std::string> __summaries;

  void EditSummary();
  void LoadSummary();
};
