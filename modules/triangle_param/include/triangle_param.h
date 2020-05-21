// Copyright 2020 Mazur Daniil

#ifndef MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_H_
#define MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_H_

#include <utility>

class Triangle {
 public:
    Triangle();
    Triangle(const std::pair<double, double>& _a,
      const std::pair<double, double>& _b,
      const std::pair<double, double>& _c);

    bool isCorrect() const;

    std::pair<double, double> getTopA() const;
    std::pair<double, double> getTopB() const;
    std::pair<double, double> getTopC() const;

    void setTopA(const std::pair<double, double>& _top);
    void setTopB(const std::pair<double, double>& _top);
    void setTopC(const std::pair<double, double>& _top);

    bool operator== (const Triangle& _triangle) const;
    bool operator!= (const Triangle& _triangle) const;

    double side(std::pair<double, double> _top1,
      std::pair<double, double> _top2) const;

    double cornA() const;
    double cornB() const;
    double cornC() const;

    double perimetr() const;
    double square() const;

 private:
    std::pair <double, double> a;
    std::pair <double, double> b;
    std::pair <double, double> c;
};

#endif  // MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_H_
