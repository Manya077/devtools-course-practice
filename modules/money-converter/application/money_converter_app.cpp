// Copyright 2020 Sokova Anastasia

#include <string>
#include <iostream>
#include "include/money_converter_app.h"

int main(int argc, const char** argv) {
    MoneyCalculator app;
    std::string output = app(argc, argv);
    std::cout << "\n" << output;
    return 0;
}
