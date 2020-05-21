// Copyright 2020 Kriukov Dmitry

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kriukov_Dmitry_ComplexNumberTest, Complex_Number_With_Negtive_Params) {
  ComplexNumber z(-1.0, -2.0);

  EXPECT_EQ(-1.0, z.getRe());
  EXPECT_EQ(-2.0, z.getIm());
}

TEST(Kriukov_Dmitry_ComplexNumberTest, Complex_Number_Multiplication_Test) {
  ComplexNumber a(3, 1);
  ComplexNumber b(2, -3);
  ComplexNumber res(9, -7);

  ComplexNumber c = a * b;

  EXPECT_EQ(c.getRe(), res.getRe());
  EXPECT_EQ(c.getIm(), res.getIm());
}

TEST(Kriukov_Dmitry_ComplexNumberTest, Complex_Number_Test_Diff) {
  ComplexNumber a(3, 1);
  ComplexNumber b(2, -3);
  ComplexNumber res(1, 4);

  ComplexNumber c = a - b;

  EXPECT_EQ(c.getRe(), res.getRe());
  EXPECT_EQ(c.getIm(), res.getIm());
}
