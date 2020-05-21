// Copyright 2020 Petrov Anton

#include <gtest/gtest.h>

#include "include/complex_number.h"



TEST(Petrov_Anton_ComplexNumberTest, Can_Be_Float ) {
// Arrange
float re = 1.11;
float im = 1.11;

// Act
ComplexNumber z(re, im);
// Assert
ASSERT_FLOAT_EQ(re, z.getRe());
ASSERT_FLOAT_EQ(im, z.getIm());
}

TEST(Petrov_Anton_ComplexNumberTest, Can_Division) {
// Arrange
float re = 10;
float im = 10;
float re1 = 5;
float im1 = 5;
float res = 2;
// Act
ComplexNumber z(re, im);
ComplexNumber z1(re1, im1);
// Assert
EXPECT_EQ(res, z.getRe() / z1.getIm());
EXPECT_EQ(res, z.getIm() / z1.getIm());
}

TEST(Petrov_Anton_ComplexNumberTest, Can_Summarize) {
// Arrange
double re = 10;
double im = 15;
double re1 = 10;
double im1 = 15;
double sumRe = 20;
double sumIm = 30;
// Act
ComplexNumber z1(re, im);
ComplexNumber z2(re1, im1);

// Assert
EXPECT_EQ(sumIm, z1.getIm() + z2.getIm());
EXPECT_EQ(sumRe, z1.getRe() + z2.getRe());
}

TEST(Petrov_Anton_ComplexNumberTest, Can_Throw_Exception_Division_By_Zero) {
// Arrange
double re = 10;
double im = 10;
// Act
ComplexNumber z1(re, im);
ComplexNumber z2(0, 0);
// Assert
ASSERT_ANY_THROW(z1 / z2);
}

TEST(Petrov_Anton_ComplexNumberTest, More_Comparison) {
// Arrange
double re = 10;
double im = 10;
double re1 = 5;
double im1 = 5;
// Act
ComplexNumber z1(re, im);
ComplexNumber z2(0, 0);
// Assert
ASSERT_GT(z1.getRe(), z2.getRe());
ASSERT_GT(z1.getIm(), z2.getIm());
}
