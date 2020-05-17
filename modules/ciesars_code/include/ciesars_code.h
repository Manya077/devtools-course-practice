// Copyright 2020 Mazur Daniil
#ifndef MODULES_CIESARS_CODE_INCLUDE_CIESARS_CODE_H_
#define MODULES_CIESARS_CODE_INCLUDE_CIESARS_CODE_H_

#include <string>

class CiesarsCode {
 public:
    static const int litCount = 26;  // English alphabet
    static std::string encode(const std::string& message, const int key);
    static std::string decode(const std::string& message, const int key);
 private:
    static std::string shift(const std::string& message, const int key);
};

#endif  // MODULES_CIESARS_CODE_INCLUDE_CIESARS_CODE_H_
