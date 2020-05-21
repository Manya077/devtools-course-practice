// Copyright 2020 Kukushkina Ksenia

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

#include "include/statistics_app.h"
#include "include/statistics.h"

Statistics_app::Statistics_app() : message_("") {}

void Statistics_app::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is a statistics application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    " $" + appname + " <value_1> <probability_1>" +
    "... <value_n> <probability_n> <operation>\n\n" +

    "Where all values are integer numbers, " +
    "all probabilities are double-presision numbers, " +
    "and <operation> is either number or one of 'm' and 'd':\n" +
    " - enter number as operation to calculate <number> order moment\n" +
    " - enter 'm' to calculate expected value of random variable\n" +
    " - enter 'd' to calculate dispersion of random variable\n\n";
}

bool Statistics_app::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc < 4) {
    help(argv[0], "ERROR: Should be more than 2 arguments.\n\n");
    return false;
  } else if (argc % 2 == 1) {
    help(argv[0], "ERROR: Number of arguments should be odd.\n\n");
    return false;
  }
  return true;
}

double parseDouble(const char* arg) {
  char* end;
  double value = strtod(arg, &end);
  if (end[0]) {
    throw std::string("Wrong probability format!");
  }
  return value;
}

double parseInt(const char* arg) {
  int value;
  value = std::atoi(arg);
  if (std::to_string(value) != std::string(arg))
    throw std::string("Wrong value format!");
  return value;
}

std::string parseOperation(const char* arg) {
  std::string op;
  if (strcmp(arg, "m") == 0) {
    op = "m";
  } else if (strcmp(arg, "d") == 0) {
    op = "d";
  } else {
    std::string arg1(arg);
    op = std::to_string(std::stoi(arg1, nullptr));
  }
  return op;
}

std::string Statistics_app::operator()(int argc, const char** argv) {
  Arguments args;

  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  try {
    for (int i = 0; i < (argc - 2) / 2; i++) {
      args.value.push_back(parseInt(argv[1 + 2 * i]));
      args.probability.push_back(parseDouble(argv[2 + 2 * i]));
    }
    args.operation = parseOperation(argv[argc - 1]);
  }
  catch (std::string &str) {
    return str;
  }
  catch (...) {
    return "Wrong operation format!";
  }

  std::map<int, double> S;

  Distribution d;
  try {
    for (int i = 0; i < static_cast<int>(args.value.size()); i++) {
      S.insert(std::pair<int, double>(args.value[i], args.probability[i]));
    }

    Distribution d(S);

    std::ostringstream stream;

    if (args.operation == "m")
      stream << "Expected value is " << d.expectedValue();
    else if (args.operation == "d")
      stream << "Dispersion is " << d.dispersion();
    else
      stream << args.operation << " order moment is "
      << d.moment(stoi(args.operation), d.expectedValue());
    message_ = stream.str();
  }
  catch (std::string &str) {
    return str;
  }
  return message_;
}
