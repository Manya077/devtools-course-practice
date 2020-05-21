// Copyright 2020 Zakharov Mikhail

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/converter_and_calculator.h"

int main(int argc, const char** argv) {
    Converter_and_Calculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
