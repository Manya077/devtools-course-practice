// Copyright 2020 Egorov Danil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Egorov_Danil_ComplexNumberTest, Can_Compare_Equal) {
    // Arrange
    double re = 1.5;
    double im = 1.5;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);

    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Egorov_Danil_ComplexNumberTest, Can_Compare_Not_Equal) {
    // Arrange
    double re1 = 1.5;
    double im1 = 1.5;
    double re2 = 5.5;
    double im2 = 3.5;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_NE(z1, z2);
}

TEST(Egorov_Danil_ComplexNumberTest, Can_Multiplication) {
    // Arrange
    double re1 = 1.5;
    double im1 = 1.5;
    double re2 = 5.5;
    double im2 = 3.5;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z3(re1 * re2 - im1 * im2, re1 * im2 + re2 * im1);

    // Assert
    EXPECT_EQ(z3, z1 * z2);
}

TEST(Egorov_Danil_ComplexNumberTest, Can_Division) {
    // Arrange
    double re1 = 1.5;
    double im1 = 1.5;
    double re2 = 5.5;
    double im2 = 3.5;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber z3((re1 * re2 + im1 * im2) / (re2 * re2 + im2 * im2),
        (im1 * re2 - re1 * im2) / (re2 * re2 + im2 * im2));

    // Assert
    EXPECT_EQ(z3, z1 / z2);
}
