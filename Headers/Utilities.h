#pragma once

#include <iostream>
#include <string>
#include <vector>

static const char *extract_version(const char *full) {
  char curr = *full;

  while (!(curr == 0 || curr == '/')) {
    curr = *full++;
  };

  return full;
}
