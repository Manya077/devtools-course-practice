// Copyright 2020 Isaev Ilya

#include <gtest/gtest.h>

#include <string>

#include "include/complex_number.h"

TEST(Ilya_Isaev_Complex_Number_Test, Create_Instance_With_Params) {
    auto a = ComplexNumber(1.05, 2.15);

    EXPECT_EQ(1.05, a.getRe());
    EXPECT_EQ(2.15, a.getIm());
}

TEST(Ilya_Isaev_Complex_Number_Test, EQ_Operator_Test) {
    auto a = ComplexNumber(0, 15);
    auto b = ComplexNumber();

    b = a;

    EXPECT_EQ(a.getRe(), b.getRe());
    EXPECT_EQ(a.getIm(), b.getIm());
}

TEST(Ilya_Isaev_Complex_Number_Test, On_Zero_Division_Test) {
    auto a = ComplexNumber(15, 10);
    auto b = ComplexNumber();

    ASSERT_ANY_THROW(a/b);
}
