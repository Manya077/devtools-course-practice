// Copyright 2020 Baldin Alexey

#ifndef MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATORFORONEVECTOR_H_
#define MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATORFORONEVECTOR_H_

#include <vector>
#include <string>

#include "include/vector3D_calculator.h"

class Vector3DCalculatorForOneVector : public Vector3DCalculator {
 public:
    Vector3DCalculatorForOneVector() : Vector3DCalculator() {}
    std::string calculate(const std::string* argv);

 protected:
    bool validateArguments(const std::string* argv);
    void parseArguments(const std::string* argv);

 private:
    std::vector<double> v;
};


#endif  // MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATORFORONEVECTOR_H_
