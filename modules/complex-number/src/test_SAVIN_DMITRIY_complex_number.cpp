// Copyright 2020 Savin_Dmitriy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Savin_Dmitriy_ComplexNumberTest, Test_With_Create_Number) {
    const double re = 14.88;
    const double im = 14.88;

    ComplexNumber num(re, im);

    EXPECT_EQ(re, num.getRe());
    EXPECT_EQ(im, num.getIm());
}
TEST(Savin_Dmitriy_ComplexNumberTest, Test_Number_On_Than_comparison_less) {
    double re = 228.0;
    double im = 1488.0;
    double re1 = 1337.0;
    double im2 = 55555.0;

    ComplexNumber num2(re1, im2);

    EXPECT_LT(re, num2.getRe());
    EXPECT_LT(im, num2.getIm());
}
TEST(Savin_Dmitriy_ComplexNumberTest, Test_Number_On_Than_comparison) {
    double re = 4.0;
    double im = 3.0;
    double re1 = 2.0;
    double im2 = 1.0;

    ComplexNumber num2(re, im);

    ASSERT_GE(re, num2.getRe());
    ASSERT_GE(im, num2.getIm());
}

