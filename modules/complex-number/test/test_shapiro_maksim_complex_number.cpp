// Copyright 2020 Shapiro Maksim

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shapiro_Maksim_ComplexNumberTest, Can_Create_Defoult) {
    double r = 0.0;
    double i = 0.0;

    ComplexNumber n1;
    ComplexNumber n2(r, i);

    EXPECT_EQ(n1, n2);
}

TEST(Shapiro_Maksim_ComplexNumberTest, Can_Multiply_To_Itself) {
    double r = 2.0;
    double i = 1.0;

    ComplexNumber n1(r, i);
    ComplexNumber n2 = n1 * n1;
    ComplexNumber correct_res(3.0, 4.0);

    EXPECT_EQ(correct_res, n2);
}

TEST(Shapiro_Maksim_ComplexNumberTest, Multiplication_By_Zero_Is_Zero) {
    double r1 = 15.3, r2 = 0.0;
    double i1 = 1.04, i2 = 0.0;

    ComplexNumber n1(r1, i1);
    ComplexNumber n2(r2, i2);
    n1 = n1 * n2;

    EXPECT_EQ(n1, n2);
}

TEST(Shapiro_Maksim_ComplexNumberTest, Can_Compare) {
    double r = 1.2;
    double i = 13.0;
    ComplexNumber n1(r, i);
    ComplexNumber n2(r, i);

    EXPECT_TRUE(n1 == n2);
}
