// Copyright 2020 Suchkov Makar

#include <iostream>
#include <string>

#include "include/bitfield-app.h"

int main(int argc, const char** argv) {
    Bitfieldapp app;
    std::string output = app(argc, argv);
    std::cout << output;
    return 0;
}
