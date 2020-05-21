// Copyright 2020 Kriukov Dmitry

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/game-of-life-app.h"

int main(int argc, const char** argv) {
    GameOfLifeApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
