// Copyright 2020 Suchkov Makar

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Suchkov_Makar_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Suchkov_Makar_ComplexNumberTest, Get_Re) {
    // Arrange
    double re = 987.0;
    double im = 789.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
}

TEST(Suchkov_Makar_ComplexNumberTest, Set_Re) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);
    z.setRe(7);

    // Assert
    EXPECT_EQ(7, z.getRe());
}

TEST(Suchkov_Makar_ComplexNumberTest, Set_Im) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);
    z.setIm(10);

    // Assert
    EXPECT_EQ(10, z.getIm());
}

TEST(Suchkov_Makar_ComplexNumberTest, Get_Im) {
    // Arrange
    double re = 2.0;
    double im = 3.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Suchkov_Makar_ComplexNumberTest, Multiple_By_Zero) {
    // Arrange
    double re = 123.0;
    double im = 987.0;
    ComplexNumber z(re, im);
    ComplexNumber zero(0.0, 0.0);

    // Act
    z = z * zero;

    // Assert
    EXPECT_EQ(z.getRe(), 0.0);
    EXPECT_EQ(z.getIm(), 0.0);
}

TEST(Suchkov_Makar_ComplexNumberTest, Correct_Copy_Constructor) {
    // Arrange
    double re1 = 2.0;
    double im1 = 1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(z1);

    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Suchkov_Makar_ComplexNumberTest, Check_Inverse_Element_Property) {
    // Arrange
    double re = 123.0;
    double im = 456.0;
    ComplexNumber pos(re, im);
    ComplexNumber neg(-re, -im);

    // Act
    ComplexNumber check = pos + neg;

    // Assert
    EXPECT_EQ(check.getRe(), 0.0);
    EXPECT_EQ(check.getIm(), 0.0);
}

TEST(Suchkov_Makar_ComplexNumberTest, Math_Operators_Correct) {
    // Arrange
    ComplexNumber z1(7.0, 2.0), z2(5.0, 3.0), z3(-1.0, 2.0), z4(1.0, 1.0);

    // Act
    ComplexNumber result = z1 * z2 + z3 / z4 - z4;

    // Assert
    EXPECT_EQ(ComplexNumber(28.5, 31.5), result);
}
