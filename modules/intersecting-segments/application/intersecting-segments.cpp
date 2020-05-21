// Copyright 2020 Maximova Irina

#include <iostream>
#include <string>

#include "include/segments_app.h"

int main(int argc, const char** argv) {
    Segment_app app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
