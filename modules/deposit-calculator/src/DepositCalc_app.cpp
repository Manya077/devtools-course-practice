// Copyright 2020 Kornev Nikita

#include "include/DepositCalc.h"
#include "include/DepositCalc_app.h"

#include <string>
#include <sstream>

using std::stoi;

DepositCalc_app::DepositCalc_app() : message_("") {}

void DepositCalc_app::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is a deposit calc application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <deposit amount> " +
    "<period> <rate>\n\n" +

    "Where all arguments are integer numbers " +
    "and period must be >= 0 and < 1827. ";
}

bool DepositCalc_app::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc != 4) {
    help(argv[0], "ERROR: Should be 3 arguments.\n\n");
    return false;
  }
  return true;
}

bool DepositCalc_app::validateArguments(const char** argv) {
  if (std::stoi(argv[2]) < 0) {
    help(argv[0], "ERROR: Period cant be negative.\n\n");
    return false;
  } else {
    if (std::stoi(argv[2]) == 0) {
      help(argv[0], "ERROR: Period cant be equal zero.\n\n");
      return false;
    } else {
      if (std::stoi(argv[2]) > 1826) {
        help(argv[0], "ERROR: Period cant be bigger then 1826.\n\n");
        return false;
      }
    }
  }
  return true;
}

std::string DepositCalc_app::operator()(int argc, const char** argv) {
  Arguments args;

  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }

  if (!validateArguments(argv)) {
    return message_;
  }

  try {
    args.depositAmount = stoi(argv[1]);
    args.period = stoi(argv[2]);
    args.rate = stoi(argv[3]);
  }
  catch (...) {
    throw("Invalid arguments");
  }

  DepositCalc dc(args.depositAmount, args.period, args.rate);

  std::ostringstream stream;

  int depositWithRate;
  int interestCharges;

  dc.calc();
  depositWithRate = dc.getDepositWithRate();
  interestCharges = dc.getInterestCharges();
  stream << "Deposit with rate = " << depositWithRate << ", "
    "interest charges = " << interestCharges << ".";

  message_ = stream.str();

  return message_;
}
