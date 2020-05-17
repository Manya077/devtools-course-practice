// Copyright 2020 Bandenkov Daniil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bandenkov_Daniil_ComplexNumberTest, Can_Create_Zero) {
  double re = 0.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Bandenkov_Daniil_ComplexNumberTest, Division_Of_Complex_Numbers) {
  double re_0 = 3.0;
  double re_1 = 4.0;
  double im_0 = 7.0;
  double im_1 = 15.0;

  ComplexNumber z0(re_0, im_0);
  ComplexNumber z1(re_1, im_1);
  ComplexNumber res((re_0 * re_1 + im_0 * im_1) / (re_1 * re_1 + im_1 * im_1),
    (im_0 * re_1 - re_0 * im_1) / (re_1 * re_1 + im_1 * im_1));

  EXPECT_EQ(res, z0 / z1);
}

TEST(Bandenkov_Daniil_ComplexNumberTest, Equality_Of_Complex_Numbers) {
  double re_0 = 3.0;
  double re_1 = 3.0;
  double im_0 = 7.0;
  double im_1 = 7.0;

  ComplexNumber z0(re_0, im_0);
  ComplexNumber z1(re_1, im_1);

  EXPECT_EQ(z0 == z1, true);
}

TEST(Bandenkov_Daniil_ComplexNumberTest, Subtraction_Of_Complex_Numbers) {
  double re_0 = 1.1;
  double re_1 = 7.9;
  double im_0 = 21.5;
  double im_1 = 1.3;

  ComplexNumber z0(re_0, im_0);
  ComplexNumber z1(re_1, im_1);
  ComplexNumber res(re_0 - re_1, im_0 - im_1);

  EXPECT_EQ(res, z0 - z1);
}
