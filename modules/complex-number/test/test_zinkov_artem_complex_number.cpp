// Copyright 2020 Zinkov Artem

#include <gtest/gtest.h>
#include "include/complex_number.h"


TEST(Zinkov_Artem_ComplexNumberTest, Inequality_Operator_Test) {
    // Arrange
    double re_1 = 7.0;
    double im_1 = 2.0;
    double re_2 = 9.0;
    double im_2 = 2.0;

    // Act
    ComplexNumber z1(re_1, im_1);
    ComplexNumber z2(re_2, im_2);

    // Assert
    EXPECT_TRUE(z1 != z2);
}

TEST(Zinkov_Artem_ComplexNumberTest, Addition_Complex_Number) {
    // Arrange
    double re_1 = 4.2;
    double im_1 = 2.0;
    double re_2 = 5.3;
    double im_2 = 2.1;
    ComplexNumber z1(re_1, im_1);
    ComplexNumber z2(re_2, im_2);
    ComplexNumber res(re_1 + re_2, im_1 + im_2);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_EQ(z, res);
}

TEST(Zinkov_Artem_ComplexNumberTest, Subtraction_Complex_Number) {
    // Arrange
    double re_1 = 12.3;
    double im_1 = 9.0;
    double re_2 = 7.3;
    double im_2 = 2.1;
    ComplexNumber z1(re_1, im_1);
    ComplexNumber z2(re_2, im_2);
    ComplexNumber res(re_1 - re_2, im_1 - im_2);

    // Act
    ComplexNumber z = z1 - z2;

    // Assert
    EXPECT_EQ(z, res);
}

TEST(Zinkov_Artem_ComplexNumberTest, Operator_Assigment_Test) {
    // Arrange
    double re_1 = 12.3;
    double im_1 = 9.0;

    ComplexNumber z1;
    ComplexNumber z2(re_1, im_1);

    // Act
    z1 = z2;

    // Assert
    EXPECT_EQ(z1, z2);
}
