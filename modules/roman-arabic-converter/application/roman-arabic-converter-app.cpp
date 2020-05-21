// Copyright 2020 Arisova Anastasiia

#include <iostream>
#include <string>

#include "../include/roman-arabic-converter-calculator.h"

int main(int argc, const char** argv) {
    RomanArabicConvertCalculator app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
