// Copyright 2020 Myshkin Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Myshkin_Andrey_ComplexNumberTest, Test_With_Create_Number) {
    const double real = 12.0;
    const double imag = 45.4;

    ComplexNumber num(real, imag);

    EXPECT_EQ(real, num.getRe());
    EXPECT_EQ(imag, num.getIm());
}


TEST(Myshkin_Andrey_ComplexNumberTest, Work_With_Constructor) {
    const double real = 1.1;
    const double imag = 20.0;

    ComplexNumber num1(real, imag);
    ComplexNumber num2;

    num2 = num1;

    ASSERT_EQ(num1, num2);
}

TEST(Myshkin_Andrey_ComplexNumberTest, Work_With_Copy_Constructor) {
    const double real = 10.0;
    const double imag = 32.0;

    ComplexNumber num(real, imag);
    ComplexNumber numC(num);

    ASSERT_EQ(numC, num);
}

TEST(Myshkin_Andrey_ComplexNumberTest, Work_With_Get) {
    const double real = 5.6;
    const double imag = 13.0;

    ComplexNumber num(real, imag);

    ASSERT_EQ(5.6, num.getRe());
    ASSERT_EQ(13.0, num.getIm());
}

TEST(Myshkin_Andrey_ComplexNumberTest, Work_With_Set) {
    const double real = 5.6;
    const double imag = 13.0;

    ComplexNumber num;

    num.setRe(real);
    num.setIm(imag);

    ASSERT_EQ(real, num.getRe());
    ASSERT_EQ(imag, num.getIm());
}
