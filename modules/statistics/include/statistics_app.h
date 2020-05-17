// Copyright 2020 Kukushkina Ksenia

#ifndef MODULES_STATISTICS_INCLUDE_STATISTICS_APP_H_
#define MODULES_STATISTICS_INCLUDE_STATISTICS_APP_H_

#include <string>
#include <vector>

class Statistics_app {
 public:
  Statistics_app();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  std::string message_;
  bool validateNumberOfArguments(int argc, const char** argv);
  typedef struct {
    std::vector<int> value;
    std::vector<double> probability;
    std::string operation;
  } Arguments;
};

#endif  // MODULES_STATISTICS_INCLUDE_STATISTICS_APP_H_
