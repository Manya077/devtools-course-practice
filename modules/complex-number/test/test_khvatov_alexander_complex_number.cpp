// Copyright 2020 Khvatov Alexander

#include <gtest/gtest.h>

#include <limits>

#include "include/complex_number.h"

TEST(Khvatov_Alexander_ComplexNumberTest, can_create_complex_number) {
    // Arrange, Act, Assert
    EXPECT_NO_THROW(ComplexNumber());
}

TEST(Khvatov_Alexander_ComplexNumberTest, can_create_complex_number_with_inf) {
    // Arrange
    double re = std::numeric_limits<double>::infinity();
    double im = std::numeric_limits<double>::infinity();

    // Act, Assert
    EXPECT_NO_THROW(ComplexNumber z(re, im));
}

TEST(Khvatov_Alexander_ComplexNumberTest, setters_correct) {
    // Arrange
    double re = 7.5;
    double im = 5.7;
    ComplexNumber z1;

    // Act
    z1.setRe(re);
    z1.setIm(im);

    // Assert
    EXPECT_EQ(ComplexNumber(re, im), z1);
}

TEST(Khvatov_Alexander_ComplexNumberTest, getters_correct) {
    // Arrange
    double re = 7.5;
    double im = 5.7;
    ComplexNumber z1(re, im);

    // Act, Assert
    EXPECT_EQ(re, z1.getRe());
    EXPECT_EQ(im, z1.getIm());
}

TEST(Khvatov_Alexander_ComplexNumberTest, DISABLED_cant_create_with_NaN) {
    // Arrange
    double re = std::numeric_limits<double>::quiet_NaN();
    double im = std::numeric_limits<double>::quiet_NaN();

    // Act, Assert
    EXPECT_ANY_THROW(ComplexNumber z(re, im));
}

TEST(Khvatov_Alexander_ComplexNumberTest, complex_number_not_equal) {
    // Arrange
    double re = std::numeric_limits<double>::infinity();
    double im = std::numeric_limits<double>::infinity();
    ComplexNumber z1(re, im), z2;

    // Act, Assert
    EXPECT_NE(z1, z2);
}

TEST(Khvatov_Alexander_ComplexNumberTest, copy_constructor_correct) {
    // Arrange
    ComplexNumber z1(5.0, 7.0);

    // Act
    ComplexNumber z2(z1);

    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Khvatov_Alexander_ComplexNumberTest, assignment_operator_correct) {
    // Arrange
    ComplexNumber z1(7.0, 5.0), z2;

    // Act
    z2 = z1;

    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Khvatov_Alexander_ComplexNumberTest, math_operators_correct) {
    // Arrange
    ComplexNumber z1(7.0, 2.0), z2(5.0, 3.0), z3(-1.0, 2.0), z4(1.0, 1.0);

    // Act
    ComplexNumber result = z1 * z2 + z3 / z4 - z4;

    // Assert
    EXPECT_EQ(ComplexNumber(28.5, 31.5), result);
}
