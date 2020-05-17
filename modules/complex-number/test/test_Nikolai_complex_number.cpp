// Copyright 2020 Sokolov Nikolai

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Nikolai_Sokolov_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Nikolai_Sokolov_ComplexNumberTest, Add_Operator) {
    // Arrange
    double re = 2.0;
    double im = 5.0;

    double re2 = 2.0;
    double im2 = 5.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z2(re2, im2);
    ComplexNumber rez = z + z2;

    double sumRe = re + re2;
    double sumIm = im + im2;

    // Assert
    EXPECT_EQ(sumRe, rez.getRe());
    EXPECT_EQ(sumIm, rez.getIm());
}

TEST(Nikolai_Sokolov_ComplexNumberTest, Difference_Operator) {
    double re = 2.0;
    double im = 5.0;

    double re2 = 5.0;
    double im2 = 1.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z2(re2, im2);

    ComplexNumber rez = z2 - z;
    double sumRe = re2 - re;
    double sumIm = im2 - im;

    // Assert
    EXPECT_EQ(sumRe, rez.getRe());
    EXPECT_EQ(sumIm, rez.getIm());
}

TEST(Nikolai_Sokolov_ComplexNumberTest, Set_Re) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);
    z.setRe(5);

    // Assert
    EXPECT_EQ(5, z.getRe());
}

TEST(Nikolai_Sokolov_ComplexNumberTest, Set_Im) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);
    z.setIm(5);

    // Assert
    EXPECT_EQ(5, z.getIm());
}
