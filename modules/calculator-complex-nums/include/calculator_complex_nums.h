// Copyright 2020 Dobrohotov Vitaly

#ifndef MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS_H_
#define MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS_H_

#include <string>

#include "include/complex_number.h"

class CalculatorComplexNums {
 private:
    std::string pattern;
    char operation;
    ComplexNumber c1;
    ComplexNumber c2;
 public:
    CalculatorComplexNums();
    explicit CalculatorComplexNums(const std::string _pattern);

    std::string GetPattern();
    void SetPattern(std::string _pattern);
    ComplexNumber GetFirst();
    ComplexNumber GetSecond();
    char GetOperation();
    bool CheckBrackets();
    bool CheckSymbols();
    void InitializeFromPattern();
    ComplexNumber Calculate();
};

#endif  // MODULES_CALCULATOR_COMPLEX_NUMS_INCLUDE_CALCULATOR_COMPLEX_NUMS_H_
