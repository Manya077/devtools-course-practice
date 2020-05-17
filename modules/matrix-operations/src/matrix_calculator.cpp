// Copyright 2020 Golubev Vladislav

#include "include/matrix_calculator.h"
#include "include/matrix_operations.h"

#include <vector>
#include <string>
#include <sstream>

MatrixCalculator::MatrixCalculator() : message_("") {}

void MatrixCalculator::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is a matrix calculator application. \n\n" +
    "Please provide arguments in the following format:\n\n" +

    "$ " + appname + " <a0_0> <a0_1> <a1_0> <a1_1> " +
    "<b0_0> <b0_1> <b1_0> <b1_1> <operation>\n\n" +

    "Where matrix elements are double-precision numbers, " +
    "and <operation> is one of '+', '-', '*', '=='. '!=' " +
    "'det', 'T', 'inv'.\n" +

    "If you want to perform an operation only for the " +
    "first matrix, you don't need to specify the second one.\n";
}

bool MatrixCalculator::validateNumberOfArguments(int argc,
  const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 10 && argc != 7 && argc != 6) {
    help(argv[0], "Should be 5, 6 or 9 arguments!\n\n");
    return false;
  }
  return true;
}

char parseOperation(const char* arg) {
  char op;
  std::string lastArgument(arg);
  if (lastArgument == "+") {
    op = '1';
  } else if (lastArgument == "-") {
    op = '2';
  } else if (lastArgument == "*") {
    op = '3';
  } else if (lastArgument == "==") {
    op = '5';
  } else if (lastArgument == "!=") {
    op = '6';
  } else if (lastArgument == "det") {
    op = '7';
  } else if (lastArgument == "T") {
    op = '8';
  } else if (lastArgument == "inv") {
    op = '9';
  } else {
    throw std::string("Wrong operation format!");
  }
  return op;
}

std::vector<double> MatrixCalculator::pushA(int argc,
  const char** argv) {
  std::vector<double> res(4);

  res[0] = std::stod(argv[1]);
  res[1] = std::stod(argv[2]);
  res[2] = std::stod(argv[3]);
  res[3] = std::stod(argv[4]);

  return res;
}

std::vector<double> MatrixCalculator::pushB(int argc,
  const char** argv) {
  std::vector<double> res(4);

  res[0] = std::stod(argv[5]);
  res[1] = std::stod(argv[6]);
  res[2] = std::stod(argv[7]);
  res[3] = std::stod(argv[8]);

  return res;
}
std::string MatrixCalculator::RunOperations(int argc, Arguments args,
  Matrix lhs, Matrix rhs) {
  Matrix resMatrix(2, 2);
  bool resBool;
  double resDouble;
  double scalar = args.c;
  std::ostringstream stream;

  switch (args.operation) {
  case '1':
    resMatrix = lhs + rhs;
    stream << "res = ";
    stream << resMatrix;
    break;
  case '2':
    resMatrix = lhs - rhs;
    stream << "res = ";
    stream << resMatrix;
    break;
  case '3':
    if (argc == 7) {
      resMatrix = lhs * scalar;
      stream << "res = ";
    } else {
      resMatrix = lhs * rhs;
      stream << "res = ";
    }
    stream << resMatrix;
    break;
  case '5':
    resBool = lhs == rhs;
    stream << "res = ";
    stream << resBool;
    break;
  case '6':
    resBool = lhs != rhs;
    stream << "res = ";
    stream << resBool;
    break;
  case '7':
    resDouble = lhs.determinant();
    stream << "res = ";
    stream << resDouble;
    break;
  case '8':
    resMatrix = lhs.transpose();
    stream << "res = ";
    stream << resMatrix;
    break;
  case '9':
    resMatrix = lhs.takeInverseMatrix();
    stream << "res = ";
    stream << resMatrix;
    break;
  }

  message_ = stream.str();
  return message_;
}

std::string MatrixCalculator::operator()(int argc, const char** argv) {
  Arguments args;

  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  try {
    args.a = pushA(argc, argv);
    switch (argc) {
    case 10:
      args.b = pushB(argc, argv);
      args.operation = parseOperation(argv[9]);
      break;
    case 7:
      args.c = std::stod(argv[5]);
      args.operation = parseOperation(argv[6]);
      break;
    default:
      args.operation = parseOperation(argv[5]);
    }
  }
  catch (std::string & str) {
    return str;
  }

  Matrix lhs(2, 2, args.a);
  Matrix rhs(2, 2);
  if (argc == 10) {
    rhs = Matrix(2, 2, args.b);
  }

  return RunOperations(argc, args, lhs, rhs);
}
