// Copyright 2020 Mazur Daniil
#ifndef MODULES_CIESARS_CODE_INCLUDE_CIESARS_CODE_APPLICATION_H_
#define MODULES_CIESARS_CODE_INCLUDE_CIESARS_CODE_APPLICATION_H_

#include <string>
#include "include/ciesars_code.h"

class CiesarsCodeApplication {
 private:
  std::string errormes;
  bool checkArgs(int _argc, const char** _argv);
  bool readFile(std::string in_filename);
  bool writeFile(std::string out_filename);
  std::string filetext_;
  CiesarsCode code_;
  std::string getHelpMessage();
  std::string decodeFile(std::string in_filename, std::string out_filename,
                         int key);
  std::string encodeFile(std::string in_filename, std::string out_filename,
                         int key);

 public:
  std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_CIESARS_CODE_INCLUDE_CIESARS_CODE_APPLICATION_H_
