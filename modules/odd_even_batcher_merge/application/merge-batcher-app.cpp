// Copyright 2020 Zinkov Artem

#include <iostream>
#include <string>

#include "include/merge_batcher_app.h"

int main(int argc, const char** argv) {
    Merge_Batcher_App app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
