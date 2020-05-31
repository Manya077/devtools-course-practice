// Copyright 2020 Tihomirova Mariya

#include <string>
#include <iostream>

#include "include/leftist_heap_application.h"

int main(int argc, const char** argv) {
  LeftHeapApp app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;
  return 0;
}
