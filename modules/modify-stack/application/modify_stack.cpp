// Copyright 2020 Okmyanskiy Andrey

#include <iostream>
#include <string>
#include <sstream>
#include "include/modify_stack_app.h"

int main(int argc, const char** argv) {
    StackApp app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
