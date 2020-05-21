// Copyright 2020 Poletueva Anastasia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Poletueva_Anastasia_ComplexNumberTest, Create_With_Negative_Re_And_Im) {
    // Arrange
    double re = -1.2;
    double im = -5.3;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Poletueva_Anastasia_ComplexNumberTest, Can_Composition_By_Zero) {
  // Arrange
  ComplexNumber z(8.2, 4.5);
  ComplexNumber k(0, 0);

  // Act
  ComplexNumber p = z*k;

  // Assert
  EXPECT_EQ(0, p.getRe());
  EXPECT_EQ(0, p.getIm());
}

TEST(Poletueva_Anastasia_ComplexNumberTest, Can_Division_By_Zero) {
  // Arrange
  ComplexNumber z(1.2, 3.5);
  ComplexNumber k(0, 0);

  // Act & Assert
  ASSERT_ANY_THROW(z / k);
}

TEST(Poletueva_Anastasia_ComplexNumberTest, Can_Composition) {
  // Arrange
  ComplexNumber a(7.3, 3.1);
  ComplexNumber b(9.2, 3.7);

  // Act
  ComplexNumber p = a*b;

  // Assert
  EXPECT_EQ(55.69, p.getRe());
  EXPECT_EQ(55.53, p.getIm());
}

TEST(Poletueva_Anastasia_ComplexNumberTest, Can_Division) {
  // Arrange
  ComplexNumber a(13, 1);
  ComplexNumber b(7, -6);

  // Act
  ComplexNumber p = a/b;

  // Assert
  EXPECT_DOUBLE_EQ(1, p.getRe());
  EXPECT_DOUBLE_EQ(1, p.getIm());
}
