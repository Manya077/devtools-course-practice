// Copyright 2020 Pauzin Leonid

#ifndef MODULES_AVL_TREE_INCLUDE_AVL_TREE_APP_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_TREE_APP_H_

#include <string>
#include <sstream>
#include "include/AVL_Tree.h"

class AvlApp {
 public:
    AvlApp() = default;
    std::string operator()(int argc, const char** argv);
 private:
    std::string help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    int parseToValue(std::string strval);
    AVL_Tree tree;
    std::stringstream _sstream;
};

#endif  // MODULES_AVL_TREE_INCLUDE_AVL_TREE_APP_H_
