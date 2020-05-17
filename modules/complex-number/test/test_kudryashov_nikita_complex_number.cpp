// Copyright 2020 Kudryashov Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kudryashov_Nikita_ComplexNumberTest, Adding_Zero_Change_Nothing) {
    // Arrange
    ComplexNumber zero(0.0, 0.0);
    ComplexNumber temp(128.25, 0.25);
    double ans_re = 128.25;
    double ans_im = 0.25;

    // Act
    temp = temp + zero;

    // Assert
    EXPECT_EQ(ans_re, temp.getRe());
    EXPECT_EQ(ans_im, temp.getIm());
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Subtracting_Zero_Change_Nothing) {
    // Arrange
    ComplexNumber zero(0.0, 0.0);
    ComplexNumber temp(11.0, 732.0);
    double ans_re = 11.0;
    double ans_im = 732.0;

    // Act
    temp = temp - zero;

    // Assert
    EXPECT_EQ(ans_re, temp.getRe());
    EXPECT_EQ(ans_im, temp.getIm());
}

TEST(Kudryashov_Nikita_ComplexNumberTest,
        Division_With_Divider_Having_Zero_Im) {
    // Arrange
    ComplexNumber z_1(8.0, 1.0);
    ComplexNumber z_2(2.0, 0.0);
    ComplexNumber ans;
    double ans_re = 4.0;
    double ans_im = 0.5;

    // Act
    ans = z_1 / z_2;

    // Assert
    EXPECT_EQ(ans_re, ans.getRe());
    EXPECT_EQ(ans_im, ans.getIm());
}

TEST(Kudryashov_Nikita_ComplexNumberTest,
        Division_With_Divider_Having_Zero_Real) {
    // Arrange
    ComplexNumber z_1(8.0, 1.0);
    ComplexNumber z_2(0.0, 2.0);
    ComplexNumber ans;
    double ans_re = 0.5;
    double ans_im = -4;

    // Act
    ans = z_1 / z_2;

    // Assert
    EXPECT_EQ(ans_re, ans.getRe());
    EXPECT_EQ(ans_im, ans.getIm());
}
