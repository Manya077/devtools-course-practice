// Copyright 2020 Pauzin Leonid

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "include/avl_tree_app.h"
#include "include/avl_actions.h"

std::string AvlApp::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return _sstream.str();
  }
  try {
    for (int i = 1; i < argc;) {
      Operation* op = Operation::makeOperation(*(argv + i));
      std::vector<int> args;
      for (int j = 1; j < op->getArgc(); ++j)
        args.push_back(parseToValue(*(argv + i + 1)));
      _sstream << op->operator()(&tree, args);
      i += op->getArgc();
      delete op;
    }
    return _sstream.str();
  }
  catch (std::exception& exc) {
    return exc.what();
  }
}

std::string AvlApp::help(const char* appname, const char* message) {
  return std::string(message) + "This is a AVL-tree application.\n\n" +
    "Please provide arguments in the following format:\n\n" +
    "  $ " + appname + " <actions> \n\n" +
    "Where <actions> are: \n\n" +
    "insert <key> - insert element into tree\n" +
    "remove <key> - remove element from tree\n ";
}

bool AvlApp::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    _sstream << help(argv[0]);
    return false;
  }
  return true;
}

int AvlApp::parseToValue(std::string strval) {
  for (size_t i = 1; i < strval.size(); ++i) {
    if (!std::isdigit(strval[i]))
      throw
      std::invalid_argument("Invalid value: " + std::string(strval));
  }
  try {
    auto value = std::stoi(strval);
    return value;
  }
  catch (...) {
    throw std::invalid_argument("Invalid value: " + strval);
  }
}
