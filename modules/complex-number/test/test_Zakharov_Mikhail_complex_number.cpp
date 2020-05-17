// Copyright 2020 Zakharov Mikhail

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Zakharov_Mikhail_ComplexNumberTest, Can_Create_Zero) {
// Arrange
double re = 13.37;
double im = 22.88;
// Act
ComplexNumber z(re, im);
// Assert
EXPECT_EQ(re, z.getRe());
EXPECT_EQ(im, z.getIm());
}

TEST(Zakharov_Mikhail_ComplexNumberTest, Test_To_Compare_The) {
const double re = 88.88;
const double im = 22.88;
ComplexNumber num(re, im);
ASSERT_GT(re, num.getIm());
}

TEST(Zakharov_Mikhail_ComplexNumberTest, Test_For_Inequality) {
const double re = 88.88;
const double im = 22.88;
ComplexNumber num(re, im);
ASSERT_NE(re, num.getIm());
}
