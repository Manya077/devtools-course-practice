// Copyright 2020 Baldin Alexey

#ifndef MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATOR_H_
#define MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATOR_H_

#include <string>

class Vector3DCalculator {
 public:
    Vector3DCalculator();
    virtual ~Vector3DCalculator() {}
    virtual std::string calculate(const std::string* argv) = 0;
    static Vector3DCalculator* createCalculator(const int argc);

 protected:
    virtual bool validateArguments(const std::string* argv) = 0;
    virtual void parseArguments(const std::string* argv) = 0;

    std::string message_;
    char operation;
};

#endif  // MODULES_VECTOR3D_INCLUDE_VECTOR3D_CALCULATOR_H_
