// Copyright 2020 Yasakova Anastasia

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Yasakova_Anastasia_ComplexNumberTest, Initialization) {
    // Arrange
    double re1 = 1.2, im1 = 2.7;

    // Act
    ComplexNumber z1(re1, im1);

    // Assert
    EXPECT_EQ(re1, z1.getRe());
    EXPECT_EQ(im1, z1.getIm());
}


TEST(Yasakova_Anastasia_ComplexNumberTest, Copy_Constructor) {
    // Arrange
    double re1 = 3.6, im1 = 2.5;
    ComplexNumber z1(re1, im1);

    // Act
    ComplexNumber z2(z1);

    // Assert
    EXPECT_EQ(z1, z2);
}


TEST(Yasakova_Anastasia_ComplexNumberTest, Addition) {
    // Arrange
    double re1 = 1.1, im1 = 2.9;
    double re2 = 3, im2 = 4;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber res(re1 + re2, im1 + im2);

    // Assert
    EXPECT_EQ(res, z1 + z2);
}


TEST(Yasakova_Anastasia_ComplexNumberTest, Subtraction) {
    // Arrange
    double re1 = 6.8, im1 = 2.2;
    double re2 = 3.3, im2 = 7.4;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber res(re1 - re2, im1 - im2);

    // Assert
    EXPECT_EQ(res, z1 - z2);
}


TEST(Yasakova_Anastasia_ComplexNumberTest, Multiplication) {
    // Arrange
    double re1 = 5.7, im1 = 2.3;
    double re2 = 9.1, im2 = 4.2;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber res(re1 * re2 - im1 * im2, re1 * im2 + re2 * im1);

    // Assert
    EXPECT_EQ(res, z1 * z2);
}


TEST(Yasakova_Anastasia_ComplexNumberTest, Division_By_Zero) {
    // Arrange
    double re1 = 1, im1 = 2;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2;

    // Act and Assert
    ASSERT_ANY_THROW(z1 / z2);
}


TEST(Yasakova_Anastasia_ComplexNumberTest, Division) {
    // Arrange
    double re1 = 1.1, im1 = 8.4;
    double re2 = 3.4, im2 = 6.3;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber res((re1 * re2 + im1 * im2) / (re2 * re2 + im2 * im2),
    (im1 * re2 - re1 * im2) / (re2 * re2 + im2 * im2));

    // Assert
    EXPECT_EQ(res, z1 / z2);
}
