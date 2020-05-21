// Copyright 2020 Baldin Alexey

#ifndef MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATORFORTWOVECTORS_H_
#define MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATORFORTWOVECTORS_H_

#include <vector>
#include <string>

#include "include/vector3D_calculator.h"

class Vector3DCalculatorForTwoVectors : public Vector3DCalculator {
 public:
    Vector3DCalculatorForTwoVectors() : Vector3DCalculator() {}
    std::string calculate(const std::string* argv);

 protected:
    bool validateArguments(const std::string* argv);
    void parseArguments(const std::string* argv);

 private:
    std::vector<double> v1;
    std::vector<double> v2;
};

#endif  // MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATORFORTWOVECTORS_H_
