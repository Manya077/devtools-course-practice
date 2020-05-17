// Copyright 2020 Baldin Alexey

#include <string>

#include "include/vector3D_calculator.h"
#include "include/vector3D_calculatorForOneVector.h"
#include "include/vector3D_calculatorForTwoVectors.h"

Vector3DCalculator::Vector3DCalculator() : message_("") {}

Vector3DCalculator * Vector3DCalculator::createCalculator(const int argc) {
    Vector3DCalculator* newCalc;
    switch (argc) {
    case 5:
        newCalc = new Vector3DCalculatorForOneVector();
        break;
    case 8:
        newCalc = new Vector3DCalculatorForTwoVectors();
        break;
    }
    return newCalc;
}
