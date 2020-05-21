// Copyright 2020 Boganov Sergei

#include <iostream>
#include <string>

#include "include/segment_tree_app.h"

int main(int argc, const char** argv) {
    SegmentTreeApp app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
