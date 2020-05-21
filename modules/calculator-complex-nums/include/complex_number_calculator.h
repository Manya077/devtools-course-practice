// Copyright 2020 Kuzhelev Anton

#ifndef MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_COMPLEX_NUMBER_CALCULATOR_H_
#define MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_COMPLEX_NUMBER_CALCULATOR_H_

#include <string>
#include "include/complex_number.h"

class ComplexCalculator {
 public:
    ComplexCalculator();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    ComplexNumber n1, n2, res;
    char operation;
};

#endif  // MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_COMPLEX_NUMBER_CALCULATOR_H_
