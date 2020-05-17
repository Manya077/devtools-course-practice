// Copyright 2020 Kornev Nikita

#ifndef MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_APP_H_
#define MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_APP_H_

#include <string>

class DepositCalc_app {
 public:
    DepositCalc_app();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    bool validateArguments(const char** argv);
    std::string message_;

    using Arguments = struct {
      unsigned int depositAmount;
      unsigned int period;
      unsigned int rate;
    };
};

#endif  // MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_APP_H_
