// Copyright 2020 PETROV ANTON

#include <string>

#include "include/Salary_calculator.h"

int main(int argc, const char** argv) {
    SalaryCalculator app;
    std::string output = app(argc, argv);
    std::cout << output.c_str() << std::endl;
    return 0;
}
