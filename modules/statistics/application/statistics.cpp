// Copyright 2020 Kukushkina Ksenia

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "include/statistics_app.h"

int main(int argc, const char** argv) {
  Statistics_app app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
