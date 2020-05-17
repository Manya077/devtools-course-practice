// Copyright 2020 Arisova Anastasiia

#include "include/Quadratic-equation.h"

#include <math.h>
#include <string>

#define EPS 10e-8

QuadraticEquation::QuadraticEquation(double aa, double bb, double cc) {
    if (abs(aa) < EPS) {
        throw static_cast<std::string>(
            "The coefficient for x^2 cannot be zero!");
    } else {
        a = aa;
        b = bb;
        c = cc;
        count_roots = '-';
    }
}

double QuadraticEquation::GetRoot1() {
    if (count_roots == '0') {
        throw static_cast<std::string>(
            "This equation cannot have real roots!");
    }
    if (count_roots == '-') {
        throw static_cast<std::string>(
            "This equation is not solved!");
    }
    return x1;
}

double QuadraticEquation::GetRoot2() {
    if (count_roots == '0') {
        throw static_cast<std::string>(
            "This equation cannot have real roots!");
    }
    if (count_roots == '-') {
        throw static_cast<std::string>(
            "This equation is not solved!");
    }
    return x2;
}

void QuadraticEquation::SolveQuadraticEquation() {
    double diskriminant = b * b - 4.0 * a * c;
    if (diskriminant < 0.0) {
        count_roots = '0';
    }

    if (abs(diskriminant) < EPS) {
        count_roots = '1';
        x1 = -b / (2.0 * a);
        x2 = x1;
    }

    if (diskriminant > 0.0) {
        count_roots = '2';
        x1 = (-b + sqrt(diskriminant)) / (2.0 * a);
        x2 = (-b - sqrt(diskriminant)) / (2.0 * a);
    }
}

char QuadraticEquation::GetCountRoots() {
    return count_roots;
}

void QuadraticEquation::SetNewCoefficients(double aa,
    double bb, double cc) {
    if (abs(aa) < EPS) {
        throw static_cast<std::string>(
            "The coefficient for x^2 cannot be zero!");
    } else {
        a = aa;
        b = bb;
        c = cc;
        count_roots = '-';
    }
}
