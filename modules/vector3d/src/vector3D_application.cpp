// Copyright 2020 Baldin Alexey

#include <string>

#include "include/vector3D_application.h"
#include "include/vector3D_calculator.h"

Vector3DApplication::Vector3DApplication() : message_("") {}

void Vector3DApplication::help(const std::string appname,
                               const char * message) {
    message_ =
        std::string(message) +
        "This is a 3d vector calculator application.\n\n" +
        "If you want use normalization, please " +
        "provide arguments in the following format:\n\n" +
        "  $ " + appname + " <v_x> <v_y> <v_z> <operation> \n\n" +
        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of 'n' or 'N', " +
        "'l' or 'L' (Vector length).\n\n" +
        "If you want use another operations, please " +
        "provide arguments in the following format:\n\n" +
        "  $ " + appname + " <v1_x> <v1_y> <v1_z> " +
        "<v2_x> <v2_y> <v2_z> <operation>\n\n" +
        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', " +
        "'s' or 'S' (Scalar product), 'v' or 'V' (Vector product). \n";
}

bool Vector3DApplication::validateNumberOfArguments(int argc,
    const std::string appName) {
    if (argc == 1) {
        help(appName);
        return false;
    } else if (argc != 8 && argc != 5) {
        help(appName, "Should be 4 or 7 arguments.\n\n");
        return false;
    }
    return true;
}

std::string Vector3DApplication::operator()(int argc, const char ** argv) {
    std::string *arguments = new std::string[argc];
    for (int i = 0; i < argc; ++i) {
        arguments[i] = argv[i];
    }

    if (!validateNumberOfArguments(argc, arguments[0])) {
        return message_;
    }

    Vector3DCalculator* calc = Vector3DCalculator::createCalculator(argc);

    message_ = calc->calculate(arguments);

    delete calc;
    delete[] arguments;

    return message_;
}
