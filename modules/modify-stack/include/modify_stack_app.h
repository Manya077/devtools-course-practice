// Copyright 2020 Okmyanskiy Andrey

#ifndef MODULES_MODIFY_STACK_INCLUDE_MODIFY_STACK_APP_H_
#define MODULES_MODIFY_STACK_INCLUDE_MODIFY_STACK_APP_H_

#include <string>
#include "include/modify_stack.h"

class StackApp {
 public:
    StackApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    Stack stack;
};

#endif  // MODULES_MODIFY_STACK_INCLUDE_MODIFY_STACK_APP_H_
