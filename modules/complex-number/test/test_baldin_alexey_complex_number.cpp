// Copyright 2020 Baldin Alexey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Baldin_Alexey_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Baldin_Alexey_ComplexNumberTest, Multiple_By_Zero) {
    // Arrange
    double re = 123.0;
    double im = 456.0;
    ComplexNumber z(re, im);
    ComplexNumber zero(0.0, 0.0);

    // Act
    z = z * zero;

    // Assert
    EXPECT_EQ(z.getRe(), 0.0);
    EXPECT_EQ(z.getIm(), 0.0);
}

TEST(Baldin_Alexey_ComplexNumberTest, Negative_Number_Less_Than_Positive) {
    // Arrange
    double re1 = 123.0;
    double re2 = -123.0;
    double im1 = 456.0;
    double im2 = -456.0;

    // Act
    ComplexNumber pos(re1, im1);
    ComplexNumber neg(re2, im2);

    // Assert
    EXPECT_LT(neg.getRe(), pos.getRe());
    EXPECT_LT(neg.getIm(), pos.getIm());
}

TEST(Baldin_Alexey_ComplexNumberTest,
     Check_Correct_Use_Several_Math_Operations_In_One_String) {
    // Arrange
    double num1 = 10.0;
    double num2 = 5.0;
    double num3 = 3.0;
    double num4 = 2.0;
    double check = 0;

    ComplexNumber cNum1(num1, num1);
    ComplexNumber cNum2(num2, num2);
    ComplexNumber cNum3(num3, num3);
    ComplexNumber cNum4(num4, num4);
    ComplexNumber cCheck(0.0, 0.0);

    // Act
    check = num1 + num2 / num3 * num4;
    cCheck = cNum1 + cNum2 / cNum3 * cNum4;

    // Assert
    EXPECT_EQ(check, cCheck.getRe());
    EXPECT_EQ(check, cCheck.getIm());
}

TEST(Baldin_Alexey_ComplexNumberTest, Check_Inverse_Element_Property) {
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
