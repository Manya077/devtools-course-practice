// Copyright 2020 Dobrohotov Vitaly

#include <gtest/gtest.h>

#include <string>

#include "include/calculator_complex_nums.h"
#include "include/complex_number.h"

TEST(CalculatorComplexNums, can_create_empty_pattern) {
    // Arrange & Act
    CalculatorComplexNums c;

    // Assert
    EXPECT_EQ("", c.GetPattern());
}

TEST(CalculatorComplexNums, can_create_pattern) {
    // Arrange
    std::string str = "(5+2i)+(2-0i)";

    // Act
    CalculatorComplexNums c(str);

    // Assert
    EXPECT_EQ("(5+2i)+(2-0i)", c.GetPattern());
}

TEST(CalculatorComplexNums, throw_when_create_with_wrong_pattern) {
    // Arrange
    std::string str = "(5+2i)=(2-0i)";
    bool check = true;

    // Act
    try {
        CalculatorComplexNums c(str);
    }
    catch (...) {
        check = false;
    }

    // Assert
    EXPECT_FALSE(check);
}

TEST(CalculatorComplexNums, can_set_pattern) {
    // Arrange
    std::string str = "(5+2i)+(2-0i)";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_EQ("(5+2i)+(2-0i)", c.GetPattern());
}

TEST(CalculatorComplexNums, check_brackets_return_true_1) {
    // Arrange
    std::string str = "(5+2i)+(2-0i)";

    // Act
    CalculatorComplexNums c(str);

    // Assert
    EXPECT_TRUE(c.CheckBrackets());
}

TEST(CalculatorComplexNums, check_brackets_return_false_1) {
    // Arrange
    std::string str = "((5+2i)+(2-0i)";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_FALSE(c.CheckBrackets());
}

TEST(CalculatorComplexNums, check_brackets_return_false_2) {
    // Arrange
    std::string str = "(5+)2i)+(2-0i)";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_FALSE(c.CheckBrackets());
}

TEST(CalculatorComplexNums, check_brackets_return_false_3) {
    // Arrange
    std::string str = "(5+2i)=(2-0i)";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_FALSE(c.CheckBrackets());
}

TEST(CalculatorComplexNums, check_brackets_return_false_4) {
    // Arrange
    std::string str = "5+2i()=(2-0i)";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_FALSE(c.CheckBrackets());
}

TEST(CalculatorComplexNums, check_brackets_return_false_5) {
    // Arrange
    std::string str = "(5+0i)/(2+5)i8";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_FALSE(c.CheckBrackets());
}

TEST(CalculatorComplexNums, check_brackets_return_false_6) {
    // Arrange
    std::string str = "(5)+0i8/(2+5i)";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_FALSE(c.CheckBrackets());
}

TEST(CalculatorComplexNums, correct_characters_return_true_1) {
    // Arrange
    std::string str = "(5+2i)+(5.2-0i)";

    // Act
    CalculatorComplexNums c(str);

    // Assert
    EXPECT_TRUE(c.CheckSymbols());
}

TEST(CalculatorComplexNums, correct_characters_return_true_2) {
    // Arrange
    std::string str = "()()()()()()";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_TRUE(c.CheckSymbols());
}

TEST(CalculatorComplexNums, correct_characters_return_true_3) {
    // Arrange
    std::string str = "123456789+-*/()";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_TRUE(c.CheckSymbols());
}

TEST(CalculatorComplexNums, correct_characters_return_false_1) {
    // Arrange
    std::string str = "(5+2i) + (5.2-0i)";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_FALSE(c.CheckSymbols());
}

TEST(CalculatorComplexNums, correct_characters_return_false_2) {
    // Arrange
    std::string str = "(5+2i)a-i (5.2-0i)";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_FALSE(c.CheckSymbols());
}

TEST(CalculatorComplexNums, correct_characters_return_false_3) {
    // Arrange
    std::string str = "(5+2i)-(5,2-0i)";

    // Act
    CalculatorComplexNums c;
    c.SetPattern(str);

    // Assert
    EXPECT_FALSE(c.CheckSymbols());
}

TEST(CalculatorComplexNums, initialize_from_pattern_with_positive_data) {
    // Arrange
    std::string str = "(5+2i)-(5.2+0i)";

    // Act
    CalculatorComplexNums c(str);
    c.InitializeFromPattern();

    // Assert
    EXPECT_EQ(c.GetFirst().getRe(), 5);
    EXPECT_EQ(c.GetFirst().getIm(), 2);
    EXPECT_EQ(c.GetSecond().getRe(), 5.2);
    EXPECT_EQ(c.GetSecond().getIm(), 0);
    EXPECT_EQ(c.GetOperation(), '-');
}

TEST(CalculatorComplexNums, initialize_from_pattern_with_negative_data) {
    // Arrange
    std::string str = "(-5-2i)-(-5.2-0i)";

    // Act
    CalculatorComplexNums c(str);
    c.InitializeFromPattern();

    // Assert
    EXPECT_EQ(c.GetFirst().getRe(), -5);
    EXPECT_EQ(c.GetFirst().getIm(), -2);
    EXPECT_EQ(c.GetSecond().getRe(), -5.2);
    EXPECT_EQ(c.GetSecond().getIm(), 0);
    EXPECT_EQ(c.GetOperation(), '-');
}

TEST(CalculatorComplexNums, calculate_with_plus) {
    // Arrange
    CalculatorComplexNums c("(1.3+5i)+(0.5-3.2i)");
    ComplexNumber res;

    // Act
    c.InitializeFromPattern();
    res = c.Calculate();

    // Assert
    EXPECT_EQ(res.getRe(), 1.8);
    EXPECT_NEAR(res.getIm(), 1.8, 0.001);
}

TEST(CalculatorComplexNums, calculate_with_minus) {
    // Arrange
    CalculatorComplexNums c("(1.3+5i)-(0.5-3.2i)");
    ComplexNumber res;

    // Act
    c.InitializeFromPattern();
    res = c.Calculate();

    // Assert
    EXPECT_EQ(res.getRe(), 0.8);
    EXPECT_EQ(res.getIm(), 8.2);
}

TEST(CalculatorComplexNums, calculate_with_multiplication) {
    // Arrange
    CalculatorComplexNums c("(1.3+5i)*(0.5-3.5i)");
    ComplexNumber res;

    // Act
    c.InitializeFromPattern();
    res = c.Calculate();

    // Assert
    EXPECT_EQ(res.getRe(), 18.15);
    EXPECT_EQ(res.getIm(), -2.05);
}

TEST(CalculatorComplexNums, calculate_with_division) {
    // Arrange
    CalculatorComplexNums c("(1.3+5i)/(0.5-3.5i)");
    ComplexNumber res;

    // Act
    c.InitializeFromPattern();
    res = c.Calculate();

    // Assert
    EXPECT_EQ(res.getRe(), -1.348);
    EXPECT_NEAR(res.getIm(), 0.564, 0.001);
}

TEST(CalculatorComplexNums, throw_if_try_calculate_without_initialize) {
    // Arrange & Act
    CalculatorComplexNums c("(1.3+5i)/(0.5-3.5i)");

    // Assert
    EXPECT_ANY_THROW(c.Calculate());
}

TEST(CalculatorComplexNums, throw_division_by_zero) {
    // Arrange & Act
    CalculatorComplexNums c("(1.3+5i)/(0-0i)");
    c.InitializeFromPattern();

    // Assert
    EXPECT_ANY_THROW(c.Calculate());
}
