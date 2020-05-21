// Copyright 2020 Andreev Sergey

#ifndef MODULES_CONVERTER_INCLUDE_CONVERTER_H_
#define MODULES_CONVERTER_INCLUDE_CONVERTER_H_

class Convert {
 private:
    const double num_to_Kelvins = 273.15;
    const double num_to_Newton = 0.33;
    const double coef_to_Fahrenheit = 1.8;
    const double num_to_Fahrenheit = 32.0;

 public:
    Convert() {}

    double convert_to_Kelvins(const double& celsius);
    double convert_to_Fahrenheit(const double& celsius);
    double convert_to_Newton(const double& celsius);
};

#endif  // MODULES_CONVERTER_INCLUDE_CONVERTER_H_
