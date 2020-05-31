// Copyright 2020 Tihomirova Mariya

#ifndef MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APPLICATION_H_
#define MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APPLICATION_H_

#include <string>
#include <sstream>
#include <vector>
#include "include/leftist_heap.h"

class LeftHeapApp {
 public:
  LeftHeapApp() = default;
  std::string operator()(int argc, const char** argv);
 private:
  std::string help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  int parseToValue(std::string strval);
  LeftistHeap heap;
  std::stringstream _sstream;
};

class LHOperation {
 public:
  explicit LHOperation(const int _argc) : argc(_argc) {}
  virtual ~LHOperation() = default;
  static LHOperation* makeOperation(std::string op);
  virtual std::string operator()(LeftistHeap* heap,
    const std::vector<int>& arg) = 0;
  int getArgc() { return argc; }
 private:
  int argc;
};

class InsertOperation : public LHOperation {
 public:
  InsertOperation() : LHOperation(2) {}
  std::string operator()(LeftistHeap* heap,
    const std::vector<int>& arg) override;
};

class FindMinOperation : public LHOperation {
 public:
  FindMinOperation() : LHOperation(1) {}
  std::string operator()(LeftistHeap* heap,
    const std::vector<int>& arg) override;
};

class DeleteMinOperation : public LHOperation {
 public:
  DeleteMinOperation() : LHOperation(1) {}
  std::string operator()(LeftistHeap* heap,
    const std::vector<int>& arg) override;
};

class IsEmptyOperation : public LHOperation {
 public:
  IsEmptyOperation() : LHOperation(1) {}
  std::string operator()(LeftistHeap* heap,
    const std::vector<int>& arg) override;
};

#endif  // MODULES_LEFTIST_HEAP_INCLUDE_LEFTIST_HEAP_APPLICATION_H_
