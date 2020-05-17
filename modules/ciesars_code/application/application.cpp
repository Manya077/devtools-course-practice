// Copyright 2020 Mazur Daniil
#include <iostream>
#include "include/ciesars_code_application.h"

int main(int argc, char const **argv) {
  CiesarsCodeApplication application;
  std::cout << application(argc, argv);
  return 0;
}
