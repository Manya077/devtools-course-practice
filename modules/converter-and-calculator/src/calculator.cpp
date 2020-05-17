// Copyright 2020 Kornev Nikita

#include <vector>

#include "include/converter.h"
#include "include/calculator.h"

// sum

int calculator::sum(const int& a, const int& a_system,
  const int& b, const int& b_system) {
  int res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert(parse(a), a_system, 10);
  temp_b = this->convert(parse(b), b_system, 10);

  res = this->parse(temp_a) + this->parse(temp_b);

  return res;
}

int calculator::sum(const int& a, const int& a_system,
  const vector<char>& b) {
  int res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert(parse(a), a_system, 10);
  temp_b = this->convert_16_to(b, 16, 10);

  res = this->parse(temp_a) + this->parse(temp_b);

  return res;
}

int calculator::sum(const vector<char>& a, const vector<char>& b) {
  int res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert_16_to(a, 16, 10);
  temp_b = this->convert_16_to(b, 16, 10);

  res = this->parse(temp_a) + this->parse(temp_b);

  return res;
}

int calculator::diff(const int& a, const int& a_system,
  const int& b, const int& b_system) {
  int res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert(parse(a), a_system, 10);
  temp_b = this->convert(parse(b), b_system, 10);

  res = this->parse(temp_a) - this->parse(temp_b);

  return res;
}

int calculator::diff(const int& a, const int& a_system,
  const vector<char>& b) {
  int res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert(parse(a), a_system, 10);
  temp_b = this->convert_16_to(b, 16, 10);

  res = this->parse(temp_a) - this->parse(temp_b);

  return res;
}

int calculator::diff(const vector<char>& a, const int& b,
  const int& b_system) {
  int res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert_16_to(a, 16, 10);
  temp_b = this->convert(parse(b), b_system, 10);

  res = this->parse(temp_a) - this->parse(temp_b);

  return res;
}

int calculator::diff(const vector<char>& a, const vector<char>& b) {
  int res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert_16_to(a, 16, 10);
  temp_b = this->convert_16_to(b, 16, 10);

  res = this->parse(temp_a) - this->parse(temp_b);

  return res;
}

int calculator::mult(const int& a, const int& a_system,
  const int& b, const int& b_system) {
  int res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert(parse(a), a_system, 10);
  temp_b = this->convert(parse(b), b_system, 10);

  res = this->parse(temp_a) * this->parse(temp_b);

  return res;
}

int calculator::mult(const int& a, const int& a_system,
  const vector<char>& b) {
  int res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert(parse(a), a_system, 10);
  temp_b = this->convert_16_to(b, 16, 10);

  res = this->parse(temp_a) * this->parse(temp_b);

  return res;
}

int calculator::mult(const vector<char>& a, const vector<char>& b) {
  int res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert_16_to(a, 16, 10);
  temp_b = this->convert_16_to(b, 16, 10);

  res = this->parse(temp_a) * this->parse(temp_b);

  return res;
}

double calculator::div(const int& a, const int& a_system,
  const int& b, const int& b_system) {
  double res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert(parse(a), a_system, 10);
  temp_b = this->convert(parse(b), b_system, 10);

  res = static_cast<double>(this->parse(temp_a)) /
    static_cast<double>(this->parse(temp_b));

  return res;
}

double calculator::div(const int& a, const int& a_system,
  const vector<char>& b) {
  double res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert(parse(a), a_system, 10);
  temp_b = this->convert_16_to(b, 16, 10);

  res = static_cast<double>(this->parse(temp_a)) /
    static_cast<double>(this->parse(temp_b));

  return res;
}

double calculator::div(const vector<char>& a,
  const int& b, const int& b_system) {
  double res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert_16_to(a, 16, 10);
  temp_b = this->convert(parse(b), b_system, 10);

  res = static_cast<double>(this->parse(temp_a)) /
    static_cast<double>(this->parse(temp_b));

  return res;
}

double calculator::div(const vector<char>& a, const vector<char>& b) {
  double res;
  vector<int> temp_a, temp_b;

  temp_a = this->convert_16_to(a, 16, 10);
  temp_b = this->convert_16_to(b, 16, 10);

  res = static_cast<double>(this->parse(temp_a)) /
    static_cast<double>(this->parse(temp_b));

  return res;
}
