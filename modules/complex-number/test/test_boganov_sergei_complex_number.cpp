// Copyright 2020 Boganov Sergei

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Boganov_Sergei_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Get_Re) {
    // Arrange
    double re = 5.0;
    double im = 1.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Get_Im) {
    // Arrange
    double re = 2.0;
    double im = 3.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Boganov_Sergei_ComplexNumberTest, Correct_Assignment_Operator) {
    // Arrange
    double re1 = 2.0;
    double im1 = 3.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2;

    z2 = z1;

    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Set_Re) {
    // Arrange
    double re1 = 2.0;
    double im1 = 3.0;
    double re2 = -5.0;

    // Act
    ComplexNumber z(re1, im1);

    z.setRe(re2);

    // Assert
    EXPECT_DOUBLE_EQ(re2, z.getRe());
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Set_Im) {
    // Arrange
    double re1 = 1.0;
    double im1 = 6.0;
    double im2 = 4.0;

    // Act
    ComplexNumber z(re1, im1);

    z.setIm(im2);

    // Assert
    EXPECT_DOUBLE_EQ(im2, z.getIm());
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Add_Complex_Numbers) {
    // Arrange
    double re1 = 1.0;
    double im1 = 3.0;
    double re2 = 4.0;
    double im2 = -5.0;
    double re3 = 5.0;
    double im3 = -2.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    // Assert
    EXPECT_EQ(z1 + z2, z3);
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Subtract_Complex_Numbers) {
    // Arrange
    double re1 = -3.0;
    double im1 = 6.0;
    double re2 = 2.0;
    double im2 = 7.0;
    double re3 = -5.0;
    double im3 = -1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    // Assert
    EXPECT_EQ(z1 - z2, z3);
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Multiply_Complex_Numbers) {
    // Arrange
    double re1 = 2.0;
    double im1 = 4.0;
    double re2 = -4.0;
    double im2 = 5.0;
    double re3 = -28.0;
    double im3 = -6.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    // Assert
    EXPECT_EQ(z1 * z2, z3);
}

TEST(Boganov_Sergei_ComplexNumberTest, Can_Divide_Complex_Numbers) {
    // Arrange
    double re1 = 1.0;
    double im1 = -1.0;
    double re2 = 1.0;
    double im2 = 1.0;
    double re3 = 0.0;
    double im3 = -1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    // Assert
    EXPECT_EQ(z1 / z2, z3);
}

TEST(Boganov_Sergei_ComplexNumberTest, Prohibited_Division_By_Zero) {
    // Arrange
    double re1 = 2.0;
    double im1 = 1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2;

    // Assert
    ASSERT_ANY_THROW(z1 / z2);
}

TEST(Boganov_Sergei_ComplexNumberTest, Correct_Not_Equal_Operator) {
    // Arrange
    double re1 = 2.0;
    double im1 = 1.0;
    double re2 = 5.0;
    double im2 = 4.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_NE(z1, z2);
}

TEST(Boganov_Sergei_ComplexNumberTest, Correct_Copy_Constructor) {
    // Arrange
    double re1 = 2.0;
    double im1 = 1.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(z1);

    // Assert
    EXPECT_EQ(z1, z2);
}
