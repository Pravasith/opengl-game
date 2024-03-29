#include "Experience/Experience.h"
#include <cstdio>

int main(int argc, char **argv) {
  Experience::Get(argv[0]);
  getchar();
  return EXIT_SUCCESS;
}
