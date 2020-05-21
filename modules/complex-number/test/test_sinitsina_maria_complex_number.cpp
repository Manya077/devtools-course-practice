// Copyright 2020 Sinitsina Maria

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sinitsina_Maria_ComplexNumberTest, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Sinitsina_Maria_ComplexNumberTest, PlusPlus_Of_Complex_Numbers) {
  double re_0 = 8.0;
  double im_0 = 5.0;
  double re_1 = 2.0;
  double im_1 = 4.0;

  ComplexNumber x(re_0, im_0);
  ComplexNumber y(re_1, im_1);
  ComplexNumber res(re_0 + re_1, im_0 + im_1);

  EXPECT_EQ(res, x + y);
}

TEST(Sinitsina_Maria_ComplexNumberTest, Product_Of_Two_Conjugate_Complex) {
  double re_0 = 3.0;
  double im_0 = 8.0;
  double re_1 = 9.0;
  double im_1 = 5.0;

  ComplexNumber x(re_0, im_0);
  ComplexNumber y(re_1, im_1);
  ComplexNumber res(re_0 * re_1 - im_0 * im_1, re_0 * im_1 + re_1 * im_0);

  EXPECT_EQ(res, x * y);
}

TEST(Sinitsina_Maria_ComplexNumberTest, Inequality_Of_Complex_Numbers) {
  double re_0 = 1.0;
  double im_0 = 9.0;
  double re_1 = 5.0;
  double im_1 = 7.0;

  ComplexNumber z0(re_0, im_0);
  ComplexNumber z1(re_1, im_1);

  EXPECT_EQ(z0 != z1, true);
}
