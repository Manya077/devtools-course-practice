// Copyright 2020 Savin Dmitry

#ifndef MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_
#define MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_

#include <string>

class MortgageCalculator {
 public:
    MortgageCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    using Arguments = struct {
        int c_cost;
        int d_downPayment;
        int c_creditTerm;
        double i_interestRate;
    };
};

#endif  // MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_
