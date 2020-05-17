// Copyright 2020 Guschin Alexandr

#ifndef MODULES_D_HEAP_INCLUDE_D_HEAP_SORT_H_
#define MODULES_D_HEAP_INCLUDE_D_HEAP_SORT_H_

#include <string>
#include "include/d-heap.h"

class d_heap_sort {
 private:
  d_heap heap;
  std::string ret_str;
  bool validateNumberOfArguments(int argc, const char** argv);
  int ParseOp(const char** op);
  int ParseArg(const char** arg);
  std::string Help(const char** appName);
 public:
  d_heap_sort();
  std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_D_HEAP_INCLUDE_D_HEAP_SORT_H_
