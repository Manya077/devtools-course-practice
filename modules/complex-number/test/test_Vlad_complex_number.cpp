// Copyright 2019 Devlikamov Vladislav

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Devlikamov_Vlad_ComplexNumberTest, Distributivity_complex_number) {
    // Arrange
    double re = 2.0;
    double im = 4.0;
    double re_1 = 1.0;
    double im_1 = 2.0;
    double re_2 = 3.0;
    double im_2 = 4.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re_1, im_1);
    ComplexNumber z2(re_1, im_1);

    // Assert
    EXPECT_EQ((z + z1) * z2, z * z2 + z1 * z2);
}

TEST(Devlikamov_Vlad_ComplexNumberTest, Division_complex_number) {
    // Arrange
    double re = 2.0;
    double im = 4.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(1, 0);
    ComplexNumber z2(re/(re*re + im*im), -im/(re*re + im*im));

    // Assert
    EXPECT_EQ(z1 / z, z2);
}

TEST(Devlikamov_Vlad_ComplexNumberTest, Multiply_complex_number_and_zero) {
    // Arrange
    double re = 2.0;
    double im = 4.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(0, 0);

    // Assert
    EXPECT_EQ(z * z1, z1);
}

TEST(Devlikamov_Vlad_ComplexNumberTest, Multiply_complex_number_and_one) {
    // Arrange
    double re = 2.0;
    double im = 4.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(1, 0);

    // Assert
    EXPECT_EQ(z * z1, z);
}

TEST(Devlikamov_Vlad_ComplexNumberTest, Associativity_mult_complex_number) {
    // Arrange
    double re = 2.0;
    double im = 4.0;
    double re_1 = 1.0;
    double im_1 = 2.0;
    double re_2 = 3.0;
    double im_2 = 4.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re_1, im_1);
    ComplexNumber z2(re_1, im_1);

    // Assert
    EXPECT_EQ((z * z1) * z2, (z1 * z2) * z);
}

TEST(Devlikamov_Vlad_ComplexNumberTest, Associativity_add_complex_number) {
    // Arrange
    double re = 2.0;
    double im = 4.0;
    double re_1 = 1.0;
    double im_1 = 2.0;
    double re_2 = 3.0;
    double im_2 = 4.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re_1, im_1);
    ComplexNumber z2(re_2, im_2);
    ComplexNumber z3 = (z + z1) + z2;
    ComplexNumber z4 = (z1 + z2) + z;

    // Assert
    EXPECT_EQ(z3, z4);
}
