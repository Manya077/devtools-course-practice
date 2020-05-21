// Copyright 2020 Savin Dmitry

#include <iostream>
#include <string>

#include "include/mortgage-calculator.h"

int main(int argc, const char** argv) {
    MortgageCalculator app;
    std::string output = app(argc, argv);
    std::cout << output.c_str() << std::endl;
    return 0;
}
