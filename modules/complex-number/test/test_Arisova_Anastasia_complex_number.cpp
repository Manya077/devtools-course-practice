// Copyright 2020 Arisova Anastasiia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Arisova_Anastasiia_ComplexNumberTest, Can_Create_Zero) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Arisova_Anastasiia_ComplexNumberTest, Can_Multiplicate_Zero) {
    // Arrange
    double re1 = 2.0, im1 = 5.4;
    double re2 = 0.0, im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber answer(re2, im2);

    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_EQ(answer, z);
}

TEST(Arisova_Anastasiia_ComplexNumberTest, Can_Multiplicate_By_Itself) {
    // Arrange
    double re1 = 1.0, im1 = 2.0;
    double re2 = -3.0, im2 = 4.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber answer(re2, im2);

    ComplexNumber z = z1 * z1;

    // Assert
    EXPECT_EQ(answer, z);
}

TEST(Arisova_Anastasiia_ComplexNumberTest, Can_Swap_Summands) {
    // Arrange
    double re1 = 1.0, im1 = 2.0;
    double re2 = 0.4, im2 = 3.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ComplexNumber z = z1 + z2;
    ComplexNumber answer = z2 + z1;

    // Assert
    EXPECT_EQ(answer, z);
}

TEST(Arisova_Anastasiia_ComplexNumberTest, Check_Associativity) {
    // Arrange
    double re1 = 1.0, im1 = 2.0;
    double re2 = 2.0, im2 = 3.0;
    double re3 = 3.0, im3 = 4.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    ComplexNumber answer1 = (z1 + z2) + z3;
    ComplexNumber answer2 = z1 + (z2 + z3);

    // Assert
    EXPECT_EQ(answer1, answer2);
}

TEST(Arisova_Anastasiia_ComplexNumberTest, Check_Distributivity) {
    // Arrange
    double re1 = 1.0, im1 = 2.0;
    double re2 = 2.0, im2 = 3.0;
    double re3 = 3.0, im3 = 4.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    ComplexNumber answer1 = (z1 + z2) * z3;
    ComplexNumber answer2 = z1 * z3 + z2 * z3;

    // Assert
    EXPECT_EQ(answer1, answer2);
}
