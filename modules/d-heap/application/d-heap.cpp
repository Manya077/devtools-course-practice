// Copyright 2020 Guschin Alexandr

#include <stdlib.h>
#include <stdio.h>
#include <string>


#include "include/d-heap-sort.h"

int main(int argc, const char** argv) {
  d_heap_sort app;

  std::cout << app(argc, argv) << std::endl;

  return 0;
}
