// Copyright 2020 Baldin Alexey

#include <string>
#include <sstream>
#include <stdexcept>

#include "include/vector3D.h"
#include "include/vector3D_calculator.h"
#include "include/vector3D_calculatorForOneVector.h"

using std::stod;

bool Vector3DCalculatorForOneVector::validateArguments(const
    std::string * argv) {
    try {
        stod(argv[1]);
        stod(argv[2]);
        stod(argv[3]);
    }
    catch (std::invalid_argument& arg) {
        message_ = "Wrong number format!";
        return false;
    }

    switch (tolower(argv[4][0])) {
    case 'l':
        return true;
    case 'n':
        return true;
    default:
        message_ = "Wrong operation format!";
        return false;
    }
}

void Vector3DCalculatorForOneVector::parseArguments(const std::string* argv) {
    v.resize(3);
    v[0] = stod(argv[1]);
    v[1] = stod(argv[2]);
    v[2] = stod(argv[3]);
    operation = tolower(argv[4][0]);
}

std::string Vector3DCalculatorForOneVector::calculate(const std::string* argv) {
    if (!validateArguments(argv)) {
        return message_;
    }

    parseArguments(argv);

    Vector3D resVec(v[0], v[1], v[2]);
    double resDouble;
    std::ostringstream stream;

    switch (operation) {
    case 'n':
        try {
            resVec.normalization();
            stream << "X = " << resVec.getX() << " "
                << "Y = " << resVec.getY() << " "
                << "Z = " << resVec.getZ();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    case 'l':
        resDouble = resVec.norm();
        stream << "Vector length = " << resDouble;
        break;
    }

    message_ = stream.str();

    return message_;
}
