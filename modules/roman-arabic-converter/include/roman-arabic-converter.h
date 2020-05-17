// Copyright 2020 Vedrukov Pavel

#ifndef MODULES_ROMAN_ARABIC_CONVERTER_INCLUDE_ROMAN_ARABIC_CONVERTER_H_
#define MODULES_ROMAN_ARABIC_CONVERTER_INCLUDE_ROMAN_ARABIC_CONVERTER_H_

#include <string>

class RomanArabicConverter {
 private:
    int validationCheckRomanNum(std::string romanNum);
    int setArabicNum(std::string romanNum);
    int validationCheckArabicNum(int arabicNum);
    std::string setRomanNumUnits(int arabicNumUnits);
    std::string setRomanNumTens(int arabicNumTens);
    std::string setRomanNumHundreds(int arabicNumHundreds);
    std::string setRomanNumThousands(int arabicNumThousands);
    std::string setRomanNum(int arabicNum);
 public:
    int romanToArabic(std::string romanNum);
    std::string arabicToRoman(int arabicNum);
};

#endif  // MODULES_ROMAN_ARABIC_CONVERTER_INCLUDE_ROMAN_ARABIC_CONVERTER_H_
