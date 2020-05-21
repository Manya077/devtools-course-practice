// Copyright 2020 Andreev Sergey

#include <gtest/gtest.h>

#include "include/converter.h"

class ConvertTest : public ::testing::Test {};

TEST(ConvertTest, Convert_to_Kelvins_1) {
    // Arrange
    double Cels = 5.0;
    double Kelvins = 278.15;
    double output = 0.0;
    Convert conv;

    // Act
    output = conv.convert_to_Kelvins(Cels);

    // Assert
    ASSERT_EQ(Kelvins, output);
}

TEST(ConvertTest, Convert_to_Kelvins_2) {
    // Arrange
    double Cels = 15.0;
    double Kelvins = 288.15;
    double output = 0.0;
    Convert conv;

    // Act
    output = conv.convert_to_Kelvins(Cels);

    // Assert
    ASSERT_EQ(Kelvins, output);
}


TEST(ConvertTest, Convert_to_Fahrenheit_1) {
    // Arrange
    double Cels = 5.5;
    double Fahrenheit = 41.9;
    double output = 0.0;
    Convert conv;

    // Act
    output = conv.convert_to_Fahrenheit(Cels);

    // Assert
    ASSERT_EQ(Fahrenheit, output);
}

TEST(ConvertTest, Convert_to_Fahrenheit_2) {
    // Arrange
    double Cels = 20.0;
    double Fahrenheit = 68.0;
    double output = 0.0;
    Convert conv;

    // Act
    output = conv.convert_to_Fahrenheit(Cels);

    // Assert
    ASSERT_EQ(Fahrenheit, output);
}

TEST(ConvertTest, Convert_to_Newton_1) {
    // Arrange
    double Cels = 5.0;
    double Newton = 1.65;
    double abs_error = 0.01;
    double output = 0.0;
    Convert conv;

    // Act
    output = conv.convert_to_Newton(Cels);

    // Assert
    ASSERT_DOUBLE_EQ(Newton, output);
}


TEST(ConvertTest, Convert_to_Newton_2) {
    // Arrange
    double Cels = 25.0;
    double Newton = 8.251;
    double abs_error = 0.01;
    double output = 0.0;
    Convert conv;

    // Act
    output = conv.convert_to_Newton(Cels);

    // Assert
    ASSERT_NEAR(Newton, output, abs_error);
}


TEST(ConvertTest, Convert_with_negative_num_Kelvins_1) {
    // Arrange
    double Cels = -5.0;
    double Kelvins = 268.15;
    Convert conv;
    double output = 0.0;

    // Act
    output = conv.convert_to_Kelvins(Cels);

    // Assert
    ASSERT_EQ(Kelvins, output);
}

TEST(ConvertTest, Convert_with_negative_num_Kelvins_2) {
    // Arrange
    double Cels = -275.15;
    double Kelvins = -2.0;
    Convert conv;
    double output = 0.0;

    // Act
    output = conv.convert_to_Kelvins(Cels);

    // Assert
    ASSERT_EQ(Kelvins, output);
}

TEST(ConvertTest, Convert_with_negative_num_Fahrenheit_1) {
    // Arrange
    double Cels = -32.0;
    double Fahrenheit = -25.6;
    Convert conv;
    double output = 0.0;

    // Act
    output = conv.convert_to_Fahrenheit(Cels);

    // Assert
    ASSERT_EQ(Fahrenheit, output);
}

TEST(ConvertTest, Convert_with_negative_num_Fahrenheit_2) {
    // Arrange
    double Cels = -5.0;
    double Fahrenheit = 23.0;
    Convert conv;
    double output = 0.0;

    // Act
    output = conv.convert_to_Fahrenheit(Cels);

    // Assert
    ASSERT_EQ(Fahrenheit, output);
}

TEST(ConvertTest, Convert_with_negative_num_Newton_1) {
    // Arrange
    double Cels = -5.0;
    double Newton = - 1.65;
    Convert conv;
    double output = 0.0;

    // Act
    output = conv.convert_to_Newton(Cels);

    // Assert
    ASSERT_DOUBLE_EQ(Newton, output);
}

TEST(ConvertTest, Convert_with_negative_num_Newton_2) {
    // Arrange
    double Cels = -0.15;
    double Newton = -0.0495;
    Convert conv;
    double output = 0.0;

    // Act
    output = conv.convert_to_Newton(Cels);

    // Assert
    ASSERT_DOUBLE_EQ(Newton, output);
}
