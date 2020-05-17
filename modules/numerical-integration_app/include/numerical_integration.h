// Copyright 2020 Devlikamov Vladislav

#ifndef MODULES_NUMERICAL_INTEGRATION_APP_INCLUDE_NUMERICAL_INTEGRATION_H_
#define MODULES_NUMERICAL_INTEGRATION_APP_INCLUDE_NUMERICAL_INTEGRATION_H_

#include <map>
#include <functional>

class FunctionsForIntegration {
 public:
     virtual double f(double x) = 0;
};

class NumericalIntegration {
 protected:
    double a, b;
 public:
    explicit NumericalIntegration(double _a = 0, double _b = 0);
    virtual ~NumericalIntegration() {}
    NumericalIntegration(const NumericalIntegration& obj) : a(obj.a),
    b(obj.b) {}

    bool operator == (const NumericalIntegration& obj) const;
    void Set_integration_borders(double _a, double _b);
    double Get_left_border() const;
    double Get_right_border() const;

    virtual double Integration_method
            (FunctionsForIntegration* func, unsigned int N) = 0;
};

class Left_rectangle_method : public NumericalIntegration {
 public:
    explicit Left_rectangle_method(double _a = 0, double _b = 0):
                                   NumericalIntegration(_a, _b) {}
    double Integration_method(FunctionsForIntegration* func, unsigned int N);
};

class Right_rectangle_method : public NumericalIntegration {
 public:
    explicit Right_rectangle_method(double _a = 0, double _b = 0):
                                    NumericalIntegration(_a, _b) {}
    double Integration_method(FunctionsForIntegration* func, unsigned int N);
};

class Middle_rectangle_method : public NumericalIntegration {
 public:
    explicit Middle_rectangle_method(double _a = 0, double _b = 0):
                                     NumericalIntegration(_a, _b) {}
    double Integration_method(FunctionsForIntegration* func, unsigned int N);
};

class Trapezoid_method : public NumericalIntegration {
 public:
    explicit Trapezoid_method(double _a = 0, double _b = 0):
                              NumericalIntegration(_a, _b) {}
    double Integration_method(FunctionsForIntegration* func, unsigned int N);
};

class Simpsons_method : public NumericalIntegration {
 public:
    explicit Simpsons_method(double _a = 0, double _b = 0):
                             NumericalIntegration(_a, _b) {}
    double Integration_method(FunctionsForIntegration* func, unsigned int N);
};

class Gauss_method : public NumericalIntegration {
 public:
    explicit Gauss_method(double _a = 0, double _b = 0):
                          NumericalIntegration(_a, _b) {}
    double Integration_method(FunctionsForIntegration* func, unsigned int N);
};

#endif  // MODULES_NUMERICAL_INTEGRATION_APP_INCLUDE_NUMERICAL_INTEGRATION_H_
