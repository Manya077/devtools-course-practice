// Copyright 2020 Golubeva Anna

#include <iostream>
#include <string>
#include "include/graph_diameter_search_app.h"

int main(int argc, const char** argv) {
  GraphApp app;
  std::string output = app(argc, argv);
  std::cout << output << std::endl;

  return 0;
}
