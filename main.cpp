#include "Messages/Recruiter.h"
#include <cstdlib>
#include <iostream>

int main() {
  Recruiter recruiter;
  recruiter.SetRecruiter(50);

  int whatIs;
  recruiter.GetRecruiter(whatIs);

  std::cout << "Hello World!\n" << whatIs << '\n';

  return EXIT_SUCCESS;
}
