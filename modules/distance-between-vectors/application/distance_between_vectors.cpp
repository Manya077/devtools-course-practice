// Copyright 2020 Sokolov Andrey

#include <string>
#include <iostream>

#include "include/distance_calculator.h"

int main(int argc, const char** argv) {
    DistanceCalculator app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
