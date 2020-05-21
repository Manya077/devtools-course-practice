// Copyright 2020 Arisova Anastasiia

#ifndef MODULES_ROMAN_ARABIC_CONVERTER_INCLUDE_ROMAN_ARABIC_CONVERTER_CALCULATOR_H_
#define MODULES_ROMAN_ARABIC_CONVERTER_INCLUDE_ROMAN_ARABIC_CONVERTER_CALCULATOR_H_

#include <string>
#include <vector>
#include <utility>

class RomanArabicConvertCalculator {
 public:
    RomanArabicConvertCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
     using Arguments = struct {
        int count_of_elements;
        std::vector<std::pair<std::string, std::string>> elements;
     };
};

#endif  // MODULES_ROMAN_ARABIC_CONVERTER_INCLUDE_ROMAN_ARABIC_CONVERTER_CALCULATOR_H_
