// Copyright 2020 Devlikamov Vladislav

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/numerical_integration_app.h"

int main(int argc, const char** argv) {
    NumericalIntegrationApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
