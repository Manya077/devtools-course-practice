// Copyright 2020 Tihomirova Mariya

#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
#include "include/leftist_heap_application.h"
#include "include/leftist_heap.h"

std::string LeftHeapApp::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return _sstream.str();
  }
  try {
    for (int i = 1; i < argc;) {
      LHOperation* op = LHOperation::makeOperation(*(argv + i));
      std::vector<int> args;
      for (int j = 1; j < op->getArgc(); ++j)
        args.push_back(parseToValue(*(argv + i + 1)));
      _sstream << op->operator()(&heap, args);
      i += op->getArgc();
      delete op;
    }
    return _sstream.str();
  }
  catch (std::exception & exc) {
    return exc.what();
  }
}

std::string LeftHeapApp::help(const char* appname, const char* message) {
  return std::string(message) + "This is a Leftist Heap application.\n\n" +
    "Please provide arguments in the following format:\n\n" +
    "  $ " + appname + " <actions> \n\n" +
    "Where <actions> are: \n\n" +
    "isEmpty - check for emptiness\n" +
    "insert <key> - insert node into heap\n" +
    "findMin - find min element from heap\n" +
    "deleteMin - delete min element from heap\n ";
}

bool LeftHeapApp::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    _sstream << help(argv[0]);
    return false;
  }
  return true;
}

int LeftHeapApp::parseToValue(std::string strval) {
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

LHOperation* LHOperation::makeOperation(std::string op) {
  LHOperation* res = nullptr;
  if (op == "isEmpty") {
    res = new IsEmptyOperation;
  } else if (op == "insert") {
      res = new InsertOperation;
  } else if (op == "findMin") {
      res = new FindMinOperation;
  } else if (op == "deleteMin") {
      res = new DeleteMinOperation;
  } else {
      throw std::invalid_argument("Bad arguments!");
  }
  return res;
}

std::string IsEmptyOperation::operator()(LeftistHeap* heap,
  const std::vector<int>& arg) {
  bool empty = heap->isEmpty();
  std::stringstream stream;
  if (!empty) {
    stream << "Heap is not empty";
  } else {
      stream << "Heap is empty";
  }
  return stream.str();
}

std::string InsertOperation::operator()(LeftistHeap* heap,
  const std::vector<int>& arg) {
  heap->insert(arg[0]);
  return "";
}

std::string FindMinOperation::operator()(LeftistHeap* heap,
  const std::vector<int>& arg) {
  std::stringstream stream;
  int found = heap->findMin();
  stream << "Min is " << found;
  return stream.str();
}

std::string DeleteMinOperation::operator()(LeftistHeap* heap,
  const std::vector<int>& arg) {
  std::stringstream stream;
  int del = heap->deleteMin();
  stream << del << " is delete";
  return stream.str();
}
