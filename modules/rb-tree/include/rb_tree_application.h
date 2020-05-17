// Copyright 2020 Isaev Ilya

#ifndef MODULES_RB_TREE_INCLUDE_RB_TREE_APPLICATION_H_
#define MODULES_RB_TREE_INCLUDE_RB_TREE_APPLICATION_H_

#include <string>
#include <sstream>
#include "include/rb_tree.h"

class RBTreeApp {
 public:
    RBTreeApp() = default;
    std::string operator()(int argc, const char** argv);
 private:
    std::string help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    int parseToValue(std::string strval);
    int isNIL(Node* node);
    RBTree _rb;
    std::stringstream _sstream;
};

#endif  // MODULES_RB_TREE_INCLUDE_RB_TREE_APPLICATION_H_
