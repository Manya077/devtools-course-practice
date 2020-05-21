// Copyright 2020 Nazarov Vladislav

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Nazarov_Vladislav_ComplexNumberTest, Uniform_Initialization) {
    // Arrange
    double re = 5.3;
    double im = 2.1;

    // Act
    ComplexNumber z{re, im};

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Nazarov_Vladislav_ComplexNumberTest, Defalut_Constructor) {
    // Arrange && Act
    ComplexNumber z{};

    // Act && Assert
    EXPECT_EQ(0, z.getRe());
    EXPECT_EQ(0, z.getIm());
}

TEST(Nazarov_Vladislav_ComplexNumberTest, Float_And_Double_Complex_Not_Equal) {
    // Arrange
    ComplexNumber z{5.321f, 215244.242f};
    ComplexNumber b{5.321, 215244.242};

    // Act && Assert
    EXPECT_TRUE(z != b);
}
