// Copyright 2020 Golubev Vlad
#ifndef MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_CALCULATOR_H_
#define MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_CALCULATOR_H_

#include <string>
#include <vector>
#include "include/matrix_operations.h"

class MatrixCalculator {
 public:
  MatrixCalculator();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  std::vector<double> pushA(int argc, const char** argv);
  std::vector<double> pushB(int argc, const char** argv);
  std::string message_;
  using Arguments = struct {
    std::vector<double> a;
    std::vector<double> b;
    double c;
    char operation;
  };
  std::string RunOperations(int argc, Arguments args, Matrix lhs, Matrix rhs);
};

#endif  // MODULES_MATRIX_OPERATIONS_INCLUDE_MATRIX_CALCULATOR_H_
