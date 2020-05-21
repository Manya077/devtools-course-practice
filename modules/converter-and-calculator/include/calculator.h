// Copyright 2020 Zakharov Mikhail
#ifndef MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CALCULATOR_H_
#define MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CALCULATOR_H_

#include <vector>

#include "include/converter.h"

class calculator : public converter {
 public:
  // resultat vsegda v desytichnoy sisteme

  // sum
  int sum(const int& a, const int& a_system,
    const int& b, const int& b_system);
  int sum(const int& a, const int& a_system, const vector<char>& b);
  int sum(const vector<char>& a, const vector<char>& b);

  // difference
  int diff(const int& a, const int& a_system,
    const int& b, const int& b_system);
  int diff(const int& a, const int& a_system, const vector<char>& b);
  int diff(const vector<char>& a, const int& b, const int& b_system);
  int diff(const vector<char>& a, const vector<char>& b);

  // multiply
  int mult(const int& a, const int& a_system,
    const int& b, const int& b_system);
  int mult(const int& a, const int& a_system, const vector<char>& b);
  int mult(const vector<char>& a, const vector<char>& b);

  // division
  double div(const int& a, const int& a_system,
    const int& b, const int& b_system);
  double div(const int& a, const int& a_system, const vector<char>& b);
  double div(const vector<char>& a, const int& b, const int& b_system);
  double div(const vector<char>& a, const vector<char>& b);
};

#endif  // MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CALCULATOR_H_
