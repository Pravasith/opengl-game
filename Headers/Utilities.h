#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static const char *extract_version(const char *full) {

  char curr = *full;
  const char *end;

  while (curr != 0) {
    curr = *full++;
    if (curr == '/') {
      end = full;
    }
  };

  return end;
}

static void write_log(const char *msg) {
  std::ofstream logs;
  logs.open("our_logs.txt", std::ofstream::app | std::ofstream::out);
  logs << msg;
  logs.close();
}

static std::string load_shader(const char *filename) {
  std::ifstream file;
  std::stringstream buf;
  std::string ret = "";

  file.open(filename);

  if (!file.is_open()) {
    std::cout << "Error: Couldn't load Shader file " << filename << std::endl;
  }

  else {
    buf << file.rdbuf();
    ret = buf.str();
    file.close();
  }

  return ret;
}
