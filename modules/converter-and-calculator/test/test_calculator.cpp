// Copyright 2020 Zakharov Mikhail

#include <gtest/gtest.h>

#include <vector>

#include "include/calculator.h"

TEST(CalculatorTest, Can_Create_Calculator) {
  // Arrange & Act
  calculator calc;

  // Assert
  ASSERT_NO_THROW();
}

// Sum

TEST(CalculatorTest_Sum, Can_Sum_Two_Decimal) {
  // Arrange
  calculator calc;
  int a = 157, b = 6832, c, exp_res = 6989;

  // Act
  c = calc.sum(a, 10, b, 10);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Sum, Can_Sum_Decimal_And_Binary) {
  // Arrange
  calculator calc;
  int a = 157, b = 1011, c, exp_res = 168;

  // Act
  c = calc.sum(a, 10, b, 2);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Sum, Can_Sum_Binary_And_Decimal) {
  // Arrange
  calculator calc;
  int a = 157, b = 1011, c, exp_res = 168;

  // Act
  c = calc.sum(b, 2, a, 10);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Sum, Can_Sum_Decimal_And_Octal) {
  // Arrange
  calculator calc;
  int a = 157, b = 222, c, exp_res = 303;

  // Act
  c = calc.sum(a, 10, b, 8);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Sum, Can_Sum_Octal_And_Decimal) {
  // Arrange
  calculator calc;
  int a = 157, b = 222, c, exp_res = 303;

  // Act
  c = calc.sum(b, 8, a, 10);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Sum, Can_Sum_Decimal_And_Hexadecimal) {
  // Arrange
  calculator calc;
  int a = 157, c, exp_res = 2897;
  vector<char> b = { 'A', 'B', '4' };

  // Act
  c = calc.sum(a, 10, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Sum, Can_Sum_Binary_And_Hexadecimal) {
  // Arrange
  calculator calc;
  int a = 10110, c, exp_res = 2762;
  vector<char> b = { 'A', 'B', '4' };

  // Act
  c = calc.sum(a, 2, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Sum, Can_Sum_Octal_And_Hexadecimal) {
  // Arrange
  calculator calc;
  int a = 666, c, exp_res = 3757;
  vector<char> b = { 'C', 'F', '7' };

  // Act
  c = calc.sum(a, 8, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Sum, Can_Sum_Hexadecimal_And_Hexadecimal) {
  // Arrange
  calculator calc;
  int exp_res = 3334, c;
  vector<char> a = { 'F' }, b = { 'C', 'F', '7' };

  // Act
  c = calc.sum(a, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

// Diference

TEST(CalculatorTest_Difference, Can_Diff_Two_Decimal) {
  // Arrange
  calculator calc;
  int a = 6832, b = 157, c, exp_res = 6675;

  // Act
  c = calc.diff(a, 10, b, 10);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Difference, Can_Diff_Decimal_And_Binary) {
  // Arrange
  calculator calc;
  int a = 157, b = 1011, c, exp_res = 146;

  // Act
  c = calc.diff(a, 10, b, 2);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Difference, Can_Diff_Decimal_And_Octal) {
  // Arrange
  calculator calc;
  int a = 157, b = 234, c, exp_res = 1;

  // Act
  c = calc.diff(a, 10, b, 8);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Difference, Can_Diff_Decimal_And_Hexadecimal) {
  // Arrange
  calculator calc;
  int a = 3565, c, exp_res = 828;
  vector<char> b = { 'A', 'B', '1' };

  // Act
  c = calc.diff(a, 10, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Difference, Can_Diff_Binary_And_Hexadecimal) {
  // Arrange
  calculator calc;
  int a = 1111, c, exp_res = -2722;
  vector<char> b = { 'A', 'B', '1' };

  // Act
  c = calc.diff(a, 2, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Difference, Can_Diff_Hexadecimal_And_Decimal) {
  // Arrange
  calculator calc;
  int a = 2020, c, exp_res = -181;
  vector<char> b = { '7', '2', 'F' };

  // Act
  c = calc.diff(b, a, 10);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Difference, Can_Diff_Hexadecimal_And_Octal) {
  // Arrange
  calculator calc;
  int a = 234, c, exp_res = 1683;
  vector<char> b = { '7', '2', 'F' };

  // Act
  c = calc.diff(b, a, 8);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Difference, Can_Diff_Hexadecimal_And_Hexadecimal) {
  // Arrange
  calculator calc;
  int c, exp_res = -1249;
  vector<char> a = { '2', '4', 'E' }, b = { '7', '2', 'F' };

  // Act
  c = calc.diff(a, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

// Multiply

TEST(CalculatorTest_Mult, Can_Mult_Two_Decimal) {
  // Arrange
  calculator calc;
  int a = 23, b = 54, c, exp_res = 1242;

  // Act
  c = calc.mult(a, 10, b, 10);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Mult, Can_Mult_Decimal_And_Binary) {
  // Arrange
  calculator calc;
  int a = 23, b = 101, c, exp_res = 115;

  // Act
  c = calc.mult(a, 10, b, 2);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Mult, Can_Mult_Decimal_And_Hexadecimal) {
  // Arrange
  calculator calc;
  int a = 23, exp_res = 3910;
  vector<char> b = { 'A', 'A' };

  // Act
  auto c = calc.mult(a, 10, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Mult, Can_Mult_Binary_And_Hexadecimal) {
  // Arrange
  calculator calc;
  int a = 1110, exp_res = 2604;
  vector<char> b = { 'B', 'A' };

  // Act
  auto c = calc.mult(a, 2, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Mult, Can_Mult_Hexadecimal_And_Hexadecimal) {
  // Arrange
  calculator calc;
  int exp_res = 2790;
  vector<char> a = { 'F' }, b = { 'B', 'A' };

  // Act
  auto c = calc.mult(a, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

// Division

TEST(CalculatorTest_Div, Can_Div_Two_Decimal) {
  // Arrange
  calculator calc;
  double a = 65, b = 54;
  double exp_res = a / b;

  // Act
  auto c = calc.div(a, 10, b, 10);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Div, Can_Div_Decimal_And_Binary) {
  // Arrange
  calculator calc;
  double a = 65, b = 1101, exp_res = a / 13;
  // Act
  auto c = calc.div(a, 10, b, 2);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Div, Can_Div_Decimal_And_Hexadecimal) {
  // Arrange
  calculator calc;
  double a = 65, exp_res = a / 10;
  vector<char> b = { 'A' };

  // Act
  auto c = calc.div(a, 10, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Div, Can_Div_Hexadecimal_And_Decimal) {
  // Arrange
  calculator calc;
  double a = 65, exp_res = 10. / 65.;
  vector<char> b = { 'A' };

  // Act
  auto c = calc.div(b, a, 10);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Div, Can_Div_Hexadecimal_And_Hexadecimal) {
  // Arrange
  calculator calc;
  double exp_res = 154. / 10.;
  vector<char> a = { '9', 'A' }, b = { 'A' };

  // Act
  auto c = calc.div(a, b);

  // Assert
  ASSERT_EQ(exp_res, c);
}

TEST(CalculatorTest_Div, Can_Div_Binary_And_Octal) {
  // Arrange
  calculator calc;
  double a = 10101, b = 77;
  double exp_res = 21. / 63.;
  // Act
  auto c = calc.div(a, 2, b, 8);

  // Assert
  ASSERT_EQ(exp_res, c);
}
