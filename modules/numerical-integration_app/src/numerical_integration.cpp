// Copyright 2020 Devlikamov Vladislav

#include <cmath>
#include <string>
#include <iostream>
#include <utility>
#include <functional>

#include "include/numerical_integration.h"

NumericalIntegration::NumericalIntegration(double _a, double _b) {
    if (_a > _b) {
        a = _b;
        b = _a;
    } else {
        a = _a;
        b = _b;
    }
}

bool NumericalIntegration::operator == (
    const NumericalIntegration& obj) const {
    return (a == obj.a) && (b == obj.b);
}

void NumericalIntegration::Set_integration_borders(double _a, double _b) {
    if (_a > _b) {
        a = _b;
        b = _a;
    } else {
        a = _a;
        b = _b;
    }
}

double NumericalIntegration::Get_left_border() const {
    return a;
}

double NumericalIntegration::Get_right_border() const {
    return b;
}

double Left_rectangle_method::Integration_method
    (FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + i * h;
        I += func->f(x);
    }

    return I * h;
}

double Right_rectangle_method::Integration_method
    (FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 1; i <= N; i++) {
        double x = a + i * h;
        I += func->f(x);
    }

    return I * h;
}

double Middle_rectangle_method::Integration_method
    (FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + (i + 0.5) * h;
        I += func->f(x);
    }

    return I * h;
}

double Trapezoid_method::Integration_method
    (FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + i * h;
        I += (func->f(x) + func->f(x + h)) / 2.0;
    }

    return I * h;
}

double Simpsons_method::Integration_method
    (FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i += 2) {
        double x = a + i * h;
        I += func->f(x - h) + 4.0 * func->f(x) + func->f(x + h);
    }

    return I * h / 3.0;
}

double Gauss_method::Integration_method
    (FunctionsForIntegration* func, unsigned int N) {
    double h = (b - a) / static_cast<double>(N);
    double I = 0.0;

    for (unsigned int i = 0; i < N; i++) {
        double x = a + i * h;
        double t1 = (2.0 * x + h) / 2.0;
        double t2 = h / (2.0 * sqrt(3.0));
        I += func->f(t1 - t2) + func->f(t1 + t2);
    }

    return I * h / 2.0;
}
