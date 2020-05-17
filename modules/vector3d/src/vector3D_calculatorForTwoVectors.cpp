// Copyright 2020 Baldin Alexey

#include <string>
#include <sstream>
#include <stdexcept>

#include "include/vector3D.h"
#include "include/vector3D_calculator.h"
#include "include/vector3D_calculatorForTwoVectors.h"

using std::stod;

bool Vector3DCalculatorForTwoVectors::validateArguments(
    const std::string * argv) {
    try {
        stod(argv[1]);
        stod(argv[2]);
        stod(argv[3]);
        stod(argv[4]);
        stod(argv[5]);
        stod(argv[6]);
    }
    catch (std::invalid_argument& arg) {
        message_ = "Wrong number format!";
        return false;
    }

    switch (tolower(argv[7][0])) {
    case '+':
        return true;
    case '-':
        return true;
    case 's':
        return true;
    case 'v':
        return true;
    default:
        message_ = "Wrong operation format!";
        return false;
    }
}

void Vector3DCalculatorForTwoVectors::parseArguments(const std::string* argv) {
    v1.resize(3);
    v2.resize(3);
    v1[0] = stod(argv[1]);
    v1[1] = stod(argv[2]);
    v1[2] = stod(argv[3]);
    v2[0] = stod(argv[4]);
    v2[1] = stod(argv[5]);
    v2[2] = stod(argv[6]);
    operation = tolower(argv[7][0]);
}

std::string Vector3DCalculatorForTwoVectors::calculate(
    const std::string* argv) {
    if (!validateArguments(argv)) {
        return message_;
    }

    parseArguments(argv);

    Vector3D vec1(v1[0], v1[1], v1[2]);
    Vector3D vec2(v2[0], v2[1], v2[2]);
    Vector3D resVec;
    double resDouble;
    std::ostringstream stream;

    switch (operation) {
    case '+':
        resVec = vec1 + vec2;
        stream << "X = " << resVec.getX() << " "
            << "Y = " << resVec.getY() << " "
            << "Z = " << resVec.getZ();
        break;
    case '-':
        resVec = vec1 - vec2;
        stream << "X = " << resVec.getX() << " "
            << "Y = " << resVec.getY() << " "
            << "Z = " << resVec.getZ();
        break;
    case 's':
        resDouble = ScalarProduct(vec1, vec2);
        stream << "Scalar product = " << resDouble;
        break;
    case 'v':
        resVec = VectorProduct(vec1, vec2);
        stream << "X = " << resVec.getX() << " "
            << "Y = " << resVec.getY() << " "
            << "Z = " << resVec.getZ();
        break;
    }

    message_ = stream.str();

    return message_;
}
