// Copyright 2020 Kuzhelev Anton

#include <iostream>
#include <string>

#include "include/complex_number_calculator.h"

int main(int argc, const char** argv) {
    ComplexCalculator app;
    std::string output = app(argc, argv);
    std::cout << std::endl << output << std::endl;
    return 0;
}
