// Copyright 2020 Andreev Sergey

#include "include/converter.h"

double Convert::convert_to_Kelvins(const double& celsius) {
    return (num_to_Kelvins + celsius);
}

double Convert::convert_to_Fahrenheit(const double& celsius) {
    return (celsius * coef_to_Fahrenheit + num_to_Fahrenheit);
}

double Convert::convert_to_Newton(const double& celsius) {
    return (num_to_Newton * celsius);
}
