// Copyright 2020 Kudryashov Nikita

#include <iostream>
#include <string>
#include "../include/triangle_param_calculator.h"

int main(int argc, const char** argv) {
    TriangleParamCalculator calc;
    std::string ans = calc.calculate(argc, argv);
    std::cout << ans;
    return 0;
}
