// Copyright 2020 Dobrohotov Vitaly

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Check_Default_Constructor) {
    ComplexNumber z;

    EXPECT_EQ(0, z.getRe());
    EXPECT_EQ(0, z.getIm());
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Check_Parameterized_Constructor) {
    double re = 20.0;
    double im = 5.0;
    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Check_Copy_Constructor) {
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(z1);

    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Two_Comp_Num_Are_Equal_True) {
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(z1);

    EXPECT_TRUE(z1 == z2);
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Two_Compl_Num_Are_Equal_False) {
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(2.1, 4.0);

    EXPECT_FALSE(z1 == z2);
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Two_Compl_Num_Are_Not_Equal_True) {
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(2.1, 4.0);

    EXPECT_TRUE(z1 != z2);
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Two_Comp_Numb_Are_Not_Equal_False) {
    ComplexNumber z1(2.0, 4.0);
    ComplexNumber z2(2.0, 4.0);

    EXPECT_FALSE(z1 != z2);
}

TEST(Dobrohotov_Vitaly_ComplexNumberTest, Can_Assign_Complex_Number) {
    ComplexNumber z1(2.0, 5.0);
    ComplexNumber z2;
    z2 = z1;

    EXPECT_TRUE(z1 == z2);
}
