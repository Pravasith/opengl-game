#pragma once

#include <cmath>
#include <cstdint>
#include <fstream>
#include <glad/glad.h>
#include <iostream>
#include <math.h>
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

const float TAU = 2 * 3.14159265358979323846f;

static void generate_n_gon(const uint32_t n, std::vector<GLuint> &elements,
                           std::vector<GLfloat> &vertices) {

  const float theta = TAU / static_cast<float>(n);

  // Clear the vectors (assuming you want to start fresh)
  elements.clear();
  vertices.clear();

  // Generate vertices and elements for the n-gon
  for (uint32_t i = 0; i < n + 1; i++) {
    GLfloat x = std::cos(theta * i) * .5f;
    GLfloat y = std::sin(theta * i) * .5f;

    // Position Coordinates
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(0.f);

    /* Color Coordinates */
    GLfloat r = x + .5f;
    GLfloat g = y + .5f;
    GLfloat b = .5f;

    vertices.push_back(r);
    vertices.push_back(g);
    vertices.push_back(b);

    /* Texture Coordinates */
    GLfloat s = x + .5f;
    GLfloat t = y + .5f;

    vertices.push_back(s);
    vertices.push_back(t);

    if (i < n) {
      /* Indices or "Elements" */
      elements.push_back(i);           // Center vertex
      elements.push_back((i + 1) % n); // Next vertex
      elements.push_back(n);           // Wrap around to the first vertex
    }
  }
}
