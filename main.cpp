// clang-format off
#include <glad/glad.h>
// clang-format on
#include <cstdint>

#include <GLFW/glfw3.h>

#include "Experience/Experience.h"
#include "Headers/Input.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  Experience::Get(argv[0]);

  return EXIT_SUCCESS;
}
