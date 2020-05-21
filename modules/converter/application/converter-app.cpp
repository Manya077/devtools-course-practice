// Copyright 2020 Egorov Danil

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/converter_app.h"

int main(int argc, const char** argv) {
    Converter_impl app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
