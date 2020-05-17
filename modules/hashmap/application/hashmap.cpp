// Copyright 2020 Nazarov Vladislav

#include "include/hashmap_application.h"
#include <iostream>

int main(int argc, const char** argv) {
    hashmapApp app;

    std::cout << app(argc, argv) << std::endl;

    return 0;
}
