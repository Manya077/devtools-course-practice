// Copyright 2020 Vedrukov Pavel

#include <string>
#include <vector>
#include "include/roman-arabic-converter.h"

constexpr char romanNumbersC[] = "IVXLCDM";

int RomanArabicConverter::validationCheckRomanNum(std::string romanNum) {
    for (unsigned int i = 0; i < romanNum.size(); i++) {
        for (unsigned int j = 0; j < 7; j++) {
            if (romanNum[i] == romanNumbersC[j]) {
                break;
            }
            if (j == 6) {
                throw(std::string)"It is not roman number";
            }
        }
    }

    for (unsigned int i = 0; i < romanNum.size(); i++) {
        switch (romanNum[i]) {
            case static_cast<char>(romanNumbersC[0]):
                if (i < romanNum.size() - 3 &&
                    romanNum[i + 1] == romanNumbersC[0] &&
                    romanNum[i + 2] == romanNumbersC[0] &&
                    romanNum[i + 3] == romanNumbersC[0]) {
                    throw(std::string)"Incorrect input of the roman number";
                }
                if (i < romanNum.size() - 2) {
                    if ((romanNum[i + 1] == romanNumbersC[2] &&
                        romanNum[i + 2] == romanNumbersC[3]) ||
                        (romanNum[i + 1] == romanNumbersC[2] &&
                        romanNum[i + 2] == romanNumbersC[4])) {
                        throw(std::string)"Incorrect input of the roman number";
                    }
                }
                if (i < romanNum.size() - 1) {
                    if (romanNum[i + 1] == romanNumbersC[3] ||
                        romanNum[i + 1] == romanNumbersC[4] ||
                        romanNum[i + 1] == romanNumbersC[5] ||
                        romanNum[i + 1] == romanNumbersC[6]) {
                        throw(std::string)"Incorrect input of the roman number";
                    }
                }
                break;
            case static_cast<char>(romanNumbersC[1]):
                if (i < romanNum.size() - 1 &&
                    (romanNum[i + 1] == romanNumbersC[1] ||
                    romanNum[i + 1] == romanNumbersC[2] ||
                    romanNum[i + 1] == romanNumbersC[3] ||
                    romanNum[i + 1] == romanNumbersC[4] ||
                    romanNum[i + 1] == romanNumbersC[5] ||
                    romanNum[i + 1] == romanNumbersC[6])) {
                    throw(std::string)"Incorrect input of the roman number";
                }
                break;
            case static_cast<char>(romanNumbersC[2]):
                if (i < romanNum.size() - 3 &&
                    romanNum[i + 1] == romanNumbersC[2] &&
                    romanNum[i + 2] == romanNumbersC[2] &&
                    romanNum[i + 3] == romanNumbersC[2]) {
                    throw(std::string)"Incorrect input of the roman number";
                }
                if (i < romanNum.size() - 2) {
                    if ((romanNum[i + 1] == romanNumbersC[4] &&
                        romanNum[i + 2] == romanNumbersC[5]) ||
                        (romanNum[i + 1] == romanNumbersC[4] &&
                        romanNum[i + 2] == romanNumbersC[6])) {
                        throw(std::string)"Incorrect input of the roman number";
                    }
                }
                if (i < romanNum.size() - 1) {
                    if (romanNum[i + 1] == romanNumbersC[5] ||
                        romanNum[i + 1] == romanNumbersC[6]) {
                        throw(std::string)"Incorrect input of the roman number";
                    }
                }
                break;
            case static_cast<char>(romanNumbersC[3]):
                if (i < romanNum.size() - 1 &&
                    (romanNum[i + 1] == romanNumbersC[3] ||
                    romanNum[i + 1] == romanNumbersC[4] ||
                    romanNum[i + 1] == romanNumbersC[5] ||
                    romanNum[i + 1] == romanNumbersC[6])) {
                    throw(std::string)"Incorrect input of the roman number";
                }
                break;
            case static_cast<char>(romanNumbersC[4]):
                if (i < romanNum.size() - 3 &&
                    romanNum[i + 1] == romanNumbersC[4] &&
                    romanNum[i + 2] == romanNumbersC[4] &&
                    romanNum[i + 3] == romanNumbersC[4]) {
                    throw(std::string)"Incorrect input of the roman number";
                }
                break;
            case static_cast<char>(romanNumbersC[5]):
                if (i < romanNum.size() - 1 &&
                   (romanNum[i + 1] == romanNumbersC[5] ||
                    romanNum[i + 1] == romanNumbersC[6])) {
                    throw(std::string)"Incorrect input of the roman number";
                }
                break;
            case static_cast<char>(romanNumbersC[6]):
                if (i < romanNum.size() - 3 &&
                    romanNum[i + 1] == romanNumbersC[6] &&
                    romanNum[i + 2] == romanNumbersC[6] &&
                    romanNum[i + 3] == romanNumbersC[6]) {
                    throw(std::string)"Incorrect input of the roman number";
                }
                break;
        }
    }
    return 0;
}

int RomanArabicConverter::setArabicNum(std::string romanNum) {
    int arabicNum = 0;
    for (unsigned int i = 0; i < romanNum.size(); i++) {
        switch (romanNum[i]) {
            case static_cast<char>(romanNumbersC[6]):
                arabicNum += 1000;
                break;
            case static_cast<char>(romanNumbersC[5]):
                arabicNum += 500;
                break;
            case static_cast<char>(romanNumbersC[4]):
                if (romanNum[i + 1] == romanNumbersC[5] &&
                    i != romanNum.size() - 1) {
                    i++;
                    arabicNum += 400;
                    break;
                }
                if (romanNum[i + 1] == romanNumbersC[6] &&
                    i != romanNum.size() - 1) {
                    i++;
                    arabicNum += 900;
                    break;
                }
                arabicNum += 100;
                break;
            case static_cast<char>(romanNumbersC[3]):
                arabicNum += 50;
                break;
            case static_cast<char>(romanNumbersC[2]):
                if (romanNum[i + 1] == romanNumbersC[3] &&
                    i != romanNum.size() - 1) {
                    i++;
                    arabicNum += 40;
                    break;
                }
                if (romanNum[i + 1] == romanNumbersC[4] &&
                    i != romanNum.size() - 1) {
                    i++;
                    arabicNum += 90;
                    break;
                }
                arabicNum += 10;
                break;
            case static_cast<char>(romanNumbersC[1]):
                arabicNum += 5;
                break;
            case static_cast<char>(romanNumbersC[0]):
                if (romanNum[i + 1] == romanNumbersC[1] &&
                    i != romanNum.size() - 1) {
                i++;
                arabicNum += 4;
                break;
                }
                if (romanNum[i + 1] == romanNumbersC[2] &&
                    i != romanNum.size() - 1) {
                    i++;
                    arabicNum += 9;
                    break;
                }
                arabicNum += 1;
                break;
        }
    }
    return arabicNum;
}

int RomanArabicConverter::validationCheckArabicNum(int arabicNum) {
    if (arabicNum < 1 || arabicNum > 3999) {
        throw(std::string)"OutOfRange";
    }
    return 0;
}

std::string RomanArabicConverter::setRomanNumUnits(int arabicNumUnits) {
    std::string romanNumUnits = "";
    switch (arabicNumUnits) {
        case 1:
            romanNumUnits.resize(1);
            romanNumUnits[0] = romanNumbersC[0];
            break;
        case 2:
            romanNumUnits.resize(2);
            romanNumUnits[0] = romanNumbersC[0];
            romanNumUnits[1] = romanNumbersC[0];
            break;
        case 3:
            romanNumUnits.resize(3);
            romanNumUnits[0] = romanNumbersC[0];
            romanNumUnits[1] = romanNumbersC[0];
            romanNumUnits[2] = romanNumbersC[0];
            break;
        case 4:
            romanNumUnits.resize(2);
            romanNumUnits[0] = romanNumbersC[0];
            romanNumUnits[1] = romanNumbersC[1];
            break;
        case 5:
            romanNumUnits.resize(1);
            romanNumUnits[0] = romanNumbersC[1];
            break;
        case 6:
            romanNumUnits.resize(2);
            romanNumUnits[0] = romanNumbersC[1];
            romanNumUnits[1] = romanNumbersC[0];
            break;
        case 7:
            romanNumUnits.resize(3);
            romanNumUnits[0] = romanNumbersC[1];
            romanNumUnits[1] = romanNumbersC[0];
            romanNumUnits[2] = romanNumbersC[0];
            break;
        case 8:
            romanNumUnits.resize(4);
            romanNumUnits[0] = romanNumbersC[1];
            romanNumUnits[1] = romanNumbersC[0];
            romanNumUnits[2] = romanNumbersC[0];
            romanNumUnits[3] = romanNumbersC[0];
            break;
        case 9:
            romanNumUnits.resize(2);
            romanNumUnits[0] = romanNumbersC[0];
            romanNumUnits[1] = romanNumbersC[2];
            break;
    }
    return romanNumUnits;
}

std::string RomanArabicConverter::setRomanNumTens(int arabicNumTens) {
    std::string romanNumTens = "";
    switch (arabicNumTens) {
        case 1:
            romanNumTens.resize(1);
            romanNumTens[0] = romanNumbersC[2];
            break;
        case 2:
            romanNumTens.resize(2);
            romanNumTens[0] = romanNumbersC[2];
            romanNumTens[1] = romanNumbersC[2];
            break;
        case 3:
            romanNumTens.resize(3);
            romanNumTens[0] = romanNumbersC[2];
            romanNumTens[1] = romanNumbersC[2];
            romanNumTens[2] = romanNumbersC[2];
            break;
        case 4:
            romanNumTens.resize(2);
            romanNumTens[0] = romanNumbersC[2];
            romanNumTens[1] = romanNumbersC[3];
            break;
        case 5:
            romanNumTens.resize(1);
            romanNumTens[0] = romanNumbersC[3];
            break;
        case 6:
            romanNumTens.resize(2);
            romanNumTens[0] = romanNumbersC[3];
            romanNumTens[1] = romanNumbersC[2];
            break;
        case 7:
            romanNumTens.resize(3);
            romanNumTens[0] = romanNumbersC[3];
            romanNumTens[1] = romanNumbersC[2];
            romanNumTens[2] = romanNumbersC[2];
            break;
        case 8:
            romanNumTens.resize(4);
            romanNumTens[0] = romanNumbersC[3];
            romanNumTens[1] = romanNumbersC[2];
            romanNumTens[2] = romanNumbersC[2];
            romanNumTens[3] = romanNumbersC[2];
            break;
        case 9:
            romanNumTens.resize(2);
            romanNumTens[0] = romanNumbersC[2];
            romanNumTens[1] = romanNumbersC[4];
            break;
    }
    return romanNumTens;
}

std::string RomanArabicConverter::setRomanNumHundreds(int arabicNumHundreds) {
    std::string romanNumHundreds = "";
    switch (arabicNumHundreds) {
        case 1:
            romanNumHundreds.resize(1);
            romanNumHundreds[0] = romanNumbersC[4];
            break;
        case 2:
            romanNumHundreds.resize(2);
            romanNumHundreds[0] = romanNumbersC[4];
            romanNumHundreds[1] = romanNumbersC[4];
            break;
        case 3:
            romanNumHundreds.resize(3);
            romanNumHundreds[0] = romanNumbersC[4];
            romanNumHundreds[1] = romanNumbersC[4];
            romanNumHundreds[2] = romanNumbersC[4];
            break;
        case 4:
            romanNumHundreds.resize(2);
            romanNumHundreds[0] = romanNumbersC[4];
            romanNumHundreds[1] = romanNumbersC[5];
            break;
        case 5:
            romanNumHundreds.resize(1);
            romanNumHundreds[0] = romanNumbersC[5];
            break;
        case 6:
            romanNumHundreds.resize(2);
            romanNumHundreds[0] = romanNumbersC[5];
            romanNumHundreds[1] = romanNumbersC[4];
            break;
        case 7:
            romanNumHundreds.resize(3);
            romanNumHundreds[0] = romanNumbersC[5];
            romanNumHundreds[1] = romanNumbersC[4];
            romanNumHundreds[2] = romanNumbersC[4];
            break;
        case 8:
            romanNumHundreds.resize(4);
            romanNumHundreds[0] = romanNumbersC[5];
            romanNumHundreds[1] = romanNumbersC[4];
            romanNumHundreds[2] = romanNumbersC[4];
            romanNumHundreds[3] = romanNumbersC[4];
            break;
        case 9:
            romanNumHundreds.resize(2);
            romanNumHundreds[0] = romanNumbersC[4];
            romanNumHundreds[1] = romanNumbersC[6];
            break;
    }
    return romanNumHundreds;
}

std::string RomanArabicConverter::setRomanNumThousands(int arabicNumThousands) {
    std::string romanNumThousands = "";
    switch (arabicNumThousands) {
        case 1:
            romanNumThousands.resize(1);
            romanNumThousands[0] = romanNumbersC[6];
            break;
        case 2:
            romanNumThousands.resize(2);
            romanNumThousands[0] = romanNumbersC[6];
            romanNumThousands[1] = romanNumbersC[6];
            break;
        case 3:
            romanNumThousands.resize(3);
            romanNumThousands[0] = romanNumbersC[6];
            romanNumThousands[1] = romanNumbersC[6];
            romanNumThousands[2] = romanNumbersC[6];
            break;
    }
    return romanNumThousands;
}

std::string RomanArabicConverter::setRomanNum(int arabicNum) {
    std::string romanNum = "";
    int digitArabicNum[4] = {arabicNum / 1000, arabicNum % 1000 / 100,
                             arabicNum % 100 / 10, arabicNum % 10};
    romanNum.insert(0, setRomanNumUnits(digitArabicNum[3]));
    romanNum.insert(0, setRomanNumTens(digitArabicNum[2]));
    romanNum.insert(0, setRomanNumHundreds(digitArabicNum[1]));
    romanNum.insert(0, setRomanNumThousands(digitArabicNum[0]));
    return romanNum;
}

int RomanArabicConverter::romanToArabic(std::string romanNum) {
    int arabicNum = 0;
    if (validationCheckRomanNum(romanNum) == 0) {
        arabicNum = setArabicNum(romanNum);
    }
    return arabicNum;
}

std::string RomanArabicConverter::arabicToRoman(int arabicNum) {
    std::string romanNum = "";
    if (validationCheckArabicNum(arabicNum) == 0) {
        romanNum = setRomanNum(arabicNum);
    }
    return romanNum;
}
