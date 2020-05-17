// Copyright 2020 Andreev Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Andreev_Sergey_ComplexNumberTest, Comprasion_Equals_Sum) {
// Arrange
double re = 10;
double im = 10;
double re2 = 10;
double im2 = 10;

// Act
ComplexNumber z1(re, im);
ComplexNumber z2(re2, im2);
ComplexNumber z3(re + re2, im + im2);

z2 = z2 + z1;

// Assert
EXPECT_EQ(z2, z3);
}

TEST(Andreev_Sergey_ComplexNumberTest, Comprasion_Not_Equals) {
// Arrange
double re1 = 5.0;
double im1 = 5.0;

double re = re1 * im1;
double im = re;

// Act
ComplexNumber z1(re1, im1);
ComplexNumber z(re, im);

// Assert
EXPECT_NE(z1, z);
}

TEST(Andreev_Sergey_ComplexNumberTest, Comprasion_Not_Equals_Minus) {
// Arrange
double re1 = 1.0;
double im1 = 1.0;
double re2 = -2.0;
double im2 = -2.0;

double re = re1 + re2;
double im = im1 + im2;

// Act
ComplexNumber z1(re1, im1);
ComplexNumber z(re, im);

// Assert
EXPECT_NE(z.getRe(), z1.getRe());
EXPECT_NE(z.getRe(), z1.getIm());
}

TEST(Andreev_Sergey_ComplexNumberTest, Comprasion_Less) {
// Arrange
double re1 = 5.0;
double im1 = 5.0;
double re2 = 5.0;
double im2 = 5.0;

double re3 = re1 * re2;
double im3 = im1 * im2;
double re4 = -(re3);
double im4 = -(im3);

// Act
ComplexNumber z3(re1, im1);
ComplexNumber z4(re4, im4);

// Assert
EXPECT_LT(z4.getRe(), z3.getRe());
EXPECT_LT(z4.getIm(), z3.getIm());
}
