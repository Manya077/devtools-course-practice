// Copyright 2020 Zakharov Mikhail

#ifndef MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_
#define MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_

#include <vector>
#include <stack>
#include <string>
#include <cmath>
using std::vector;
using std::stack;
using std::string;

class converter {
  vector<int> convert_dec_to_smaller(const vector<int>& value,
    const int& target_system);  // 10 v lubuyu < 10
  vector<int> convert_smaller_to_dec(const vector<int>& value,
    const int& this_system);   // lubuyu < 10 v 10

  vector<char> convert_dec_to_hex(const int& value);  // 10 to 16
  int convert_hex_to_dec(const vector<char>& value);  // 16 to 10

 public:
  // convert umeet konvertirovat' 10 v lubuyu sistemu i naoborot.
  // Vse chisla predstavleni v vide vector<int>, t.e. 666 = { 6, 6, 6 }
  vector<int> convert(const vector<int>& value, const int& this_system,
    const int& target_system);

  vector<char> convert_to_16(const vector<int>& value, const int& this_system,
    const int& target_system);  // lubuyu v 16
  vector<int> convert_16_to(const vector<char>& value, const int& this_system,
    const int& target_system);  // 16 v lubuyu

  int parse(const vector<int>& value);
  vector<int> parse(const int& value);
};

#endif  // MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_H_
