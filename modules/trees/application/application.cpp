// Copyright 2020 Sinitsina Maria

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/trees_application.h"

int main(int argc, const char** argv) {
    trees_application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
