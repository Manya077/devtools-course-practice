// Copyright 2020 Arisova Anastasiia

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_

class QuadraticEquation {
 private:
        double a, b, c;
        double x1, x2;
        char count_roots;
 public:
        QuadraticEquation(double aa, double bb, double cc);
        double GetRoot1();
        double GetRoot2();
        char GetCountRoots();
        void SolveQuadraticEquation();
        void SetNewCoefficients(double aa, double bb, double cc);
};

#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
