// Copyright 2020 Sinitsina Maria
#ifndef MODULES_TREES_INCLUDE_TREES_APPLICATION_H_
#define MODULES_TREES_INCLUDE_TREES_APPLICATION_H_
#include <sstream>
#include <string>
#include "include/trees.h"

class TreesApplication {
 public:
  TreesApplication() = default;
  std::string operator()(int argc, const char** argv);

 private:
  std::string Help(const char* appname);
  int ParseOperation(const char** argv);
  int ParseValue(const char* s);
  Tree tree_;
  std::stringstream _sstream;
};

#endif  // MODULES_TREES_INCLUDE_TREES_APPLICATION_H_
