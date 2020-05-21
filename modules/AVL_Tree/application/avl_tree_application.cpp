// Copyright 2020 Pauzin Leonid

#include <iostream>
#include <string>

#include "include/avl_tree_app.h"

int main(int argc, const char** argv) {
    AvlApp app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
