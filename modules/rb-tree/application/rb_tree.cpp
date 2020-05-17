// Copyright 2020 Isaev Ilya

#include "include/rb_tree_application.h"
#include <iostream>

int main(int argc, const char** argv) {
    RBTreeApp app;

    std::cout << app(argc, argv) << std::endl;

    return 0;
}
