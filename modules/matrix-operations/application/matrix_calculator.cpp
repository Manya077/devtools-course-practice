// Copyright 2020 Golubev Vladislav

#include <string>
#include <iostream>

#include "include/matrix_calculator.h"

int main(int argc, const char** argv) {
    MatrixCalculator app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
