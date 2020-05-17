// Copyright 2020 Sokolov Nikolay

#include <string>
#include <iostream>

#include "include/fraction_calculator.h"

int main(int argc, const char** argv) {
    FractionCalculator app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
