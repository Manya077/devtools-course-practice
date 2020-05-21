// Copyright 2020 Brazhnikov Eugene

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Brazhnikov_Eugene_ComplexNumberTest, Self_Assign) {
    // Arrange
    double re = 1.1;
    double im = 1.1;

    // Act
    ComplexNumber a(re, im);

    // Assert
    EXPECT_EQ(re, a.getRe());
    EXPECT_EQ(im, a.getIm());
}

TEST(Brazhnikov_Eugene_ComplexNumberTest, Multiply_6_times_in_a_row) {
    // Arrange
    ComplexNumber CN_1(2.0, 4.0);
    ComplexNumber CN_2(5.0, 2.0);  // 2+24i
    ComplexNumber CN_3(10.0, 5.0);  // -100+250i
    ComplexNumber CN_4(1.0, 2.0);  // -400+450i
    ComplexNumber CN_5(400.0, 450.0);
    ComplexNumber CN_6(1.0, 2.0);
    ComplexNumber expected_CN(237500.0, -775000.0);

    // Act
    ComplexNumber result_CN = CN_1 * CN_2 * CN_3 * CN_4 * CN_5 * CN_6;

    // Assert
    EXPECT_EQ(expected_CN.getRe(), result_CN.getRe());
    EXPECT_EQ(expected_CN.getIm(), result_CN.getIm());
}

TEST(Brazhnikov_Eugene_ComplexNumberTest, Can_Check_Equality) {
    // Act
    ComplexNumber x(5.0, 5.0);
    ComplexNumber y(5.0, 5.0);

    // Assert
    EXPECT_EQ(true, x == y);
}
