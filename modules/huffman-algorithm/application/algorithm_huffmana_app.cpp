// Copyright 2020 Golovanova Elena

#include <iostream>
#include <string>

#include <include/algorithm_huffmana_app.h>

int main(int argc, const char** argv) {
  AlgorithmHuffmanaApp app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
return 0;
}
