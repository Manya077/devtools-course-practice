// Copyright 2020 Baldin Alexey

#include <string>
#include <iostream>

#include "include/vector3D_application.h"

int main(int argc, const char** argv) {
    Vector3DApplication app;
    std::string output = app(argc, argv);
    std::cout << output.c_str();
    return 0;
}
