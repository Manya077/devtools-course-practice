// Copyright 2020 Devlikamov Vladislav

#ifndef MODULES_NUMERICAL_INTEGRATION_APP_INCLUDE_NUMERICAL_INTEGRATION_APP_H_
#define MODULES_NUMERICAL_INTEGRATION_APP_INCLUDE_NUMERICAL_INTEGRATION_APP_H_

#include "include/numerical_integration.h"

#include <string>
#include <vector>

class NumericalIntegrationApp {
 public:
    NumericalIntegrationApp();
    std::string operator()(int argc, const char** argv);
    ~NumericalIntegrationApp();

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    bool validateArguments(int argc, const char** argv);
    void set_vector(double a, double b);
    std::string message_;
    std::vector <NumericalIntegration*> methods;
    struct Arguments {
        double a;
        double b;
        unsigned int N;
        int num_function;
        int method;
    };
};

#endif  // MODULES_NUMERICAL_INTEGRATION_APP_INCLUDE_NUMERICAL_INTEGRATION_APP_H_
