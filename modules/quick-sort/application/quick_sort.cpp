// Copyright 2020 Poletueva Anastasia

#include <iostream>
#include <string>

#include "include/quick_sort_app.h"

int main(int argc, const char** argv) {
    QuickSortApp app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
