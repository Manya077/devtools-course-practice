// Copyright 2020 Brazhnikov Eugene

#include <gtest/gtest.h>
#include "include/length_converter.h"

TEST(test_sokova_anastasia_length_converter, Can_Create) {
    ASSERT_NO_THROW(LengthConverter a);
}

TEST(test_sokova_anastasia_length_converter, Can_Convert_meter_to_km) {
    // Arrange
    LengthConverter converter;
    double input = 1.0;
    double output;

    // Act
    output = converter.m_kmeter(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(0.001, output);
}

TEST(test_sokova_anastasia_length_converter, Can_Convert_km_to_meter) {
    // Arrange
    LengthConverter converter;
    double input = 1.0;
    double output;

    // Act
    output = converter.m_kmeter(input, true);

    // Assert
    ASSERT_DOUBLE_EQ(1000, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_km_with_negative) {
    // Arrange
    LengthConverter converter;
    double input = -5.0;
    double output;

    // Act
    output = converter.m_kmeter(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(-1, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_km_equal_zero) {
    // Arrange
    LengthConverter converter;
    double input = 0.0;
    double output;

    // Act
    output = converter.m_kmeter(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(0.0, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_km_with_int) {
    // Arrange
    LengthConverter converter;
    double input = 10;
    double output;

    // Act
    output = converter.m_kmeter(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(0.01, output);
}

// ===================================

TEST(test_sokova_anastasia_length_converter, Can_Convert_meter_to_sm) {
    // Arrange
    LengthConverter converter;
    double input = 1;
    double output;

    // Act
    output = converter.m_smeter(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(100, output);
}

TEST(test_sokova_anastasia_length_converter, Can_Convert_sm_to_meter) {
    // Arrange
    LengthConverter converter;
    double input = 100;
    double output;

    // Act
    output = converter.m_smeter(input, true);

    // Assert
    ASSERT_DOUBLE_EQ(1, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_sm_equal_zero) {
    // Arrange
    LengthConverter converter;
    double input = 0.0;
    double output;

    // Act
    output = converter.m_smeter(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(0.0, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_sm_with_negative) {
    // Arrange
    LengthConverter converter;
    double input = -12.0;
    double output;

    // Act
    output = converter.m_smeter(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(-1, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_sm_with_int) {
    // Arrange
    LengthConverter converter;
    double input = 10;
    double output;

    // Act
    output = converter.m_smeter(input, false);

    // Assert
    ASSERT_NEAR(1000, output, 0.1);
}

// ============================

TEST(test_sokova_anastasia_length_converter, Can_Convert_meter_to_mile) {
    // Arrange
    LengthConverter converter;
    double input = 1000;
    double output;

    // Act
    output = converter.m_mile(input, false);

    // Assert
    ASSERT_NEAR(0.621371, output, 0.01);
}

TEST(test_sokova_anastasia_length_converter, Can_Convert_mile_to_meter) {
    // Arrange
    LengthConverter converter;
    double input = 0.621371;
    double output;

    // Act
    output = converter.m_mile(input, true);

    // Assert
    ASSERT_NEAR(1000, output, 0.01);
}

TEST(test_sokova_anastasia_length_converter, meter_to_mile_equal_zero) {
    // Arrange
    LengthConverter converter;
    double input = 0.0;
    double output;

    // Act
    output = converter.m_mile(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(0.0, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_mile_with_negative) {
    // Arrange
    LengthConverter converter;
    double input = -5.0;
    double output;

    // Act
    output = converter.m_mile(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(-1, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_mile_with_int) {
    // Arrange
    LengthConverter converter;
    double input = 100;
    double output;

    // Act
    output = converter.m_mile(input, false);

    // Assert
    ASSERT_NEAR(0.062, output, 0.01);
}

// ===================================

TEST(test_sokova_anastasia_length_converter, Can_Convert_meter_to_yard) {
    // Arrange
    LengthConverter converter;
    double input = 10.5;
    double output;

    // Act
    output = converter.m_yard(input, false);

    // Assert
    ASSERT_NEAR(11.48294, output, 0.01);
}

TEST(test_sokova_anastasia_length_converter, Can_Convert_yard_to_meter) {
    // Arrange
    LengthConverter converter;
    double input = 11.48294;
    double output;

    // Act
    output = converter.m_yard(input, true);

    // Assert
    ASSERT_NEAR(10.5, output, 0.01);
}

TEST(test_sokova_anastasia_length_converter, meter_to_yard_equal_zero) {
    // Arrange
    LengthConverter converter;
    double input = 0.0;
    double output;

    // Act
    output = converter.m_yard(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(0.0, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_yard_with_negative) {
    // Arrange
    LengthConverter converter;
    double input = -5.0;
    double output;

    // Act
    output = converter.m_yard(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(-1, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_yard_with_int) {
    // Arrange
    LengthConverter converter;
    double input = 10;
    double output;

    // Act
    output = converter.m_yard(input, false);

    // Assert
    ASSERT_NEAR(10.9361, output, 0.01);
}

// =================================

TEST(test_sokova_anastasia_length_converter, Can_Convert_meter_to_ft) {
    // Arrange
    LengthConverter converter;
    double input = 10.5;
    double output;

    // Act
    output = converter.m_ft(input, false);

    // Assert
    ASSERT_NEAR(34.44882, output, 0.01);
}

TEST(test_sokova_anastasia_length_converter, Can_Convert_ft_to_meter) {
    // Arrange
    LengthConverter converter;
    double input = 34.44882;
    double output;

    // Act
    output = converter.m_ft(input, true);

    // Assert
    ASSERT_NEAR(10.5, output, 0.01);
}

TEST(test_sokova_anastasia_length_converter, meter_to_ft_with_zero) {
    // Arrange
    LengthConverter converter;
    double input = 0.0;
    double output;

    // Act
    output = converter.m_ft(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(0.0, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_ft_with_negative) {
    // Arrange
    LengthConverter converter;
    double input = -5.0;
    double output;

    // Act
    output = converter.m_ft(input, true);

    // Assert
    ASSERT_DOUBLE_EQ(-1, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_ft_with_int) {
    // Arrange
    LengthConverter converter;
    double input = 10;
    double output;

    // Act
    output = converter.m_ft(input, false);

    // Assert
    ASSERT_NEAR(32.8084, output, 0.01);
}

// =================================

TEST(test_sokova_anastasia_length_converter, Can_Convert_meter_to_inch) {
    // Arrange
    LengthConverter converter;
    double input = 10.5;
    double output;

    // Act
    output = converter.m_inch(input, false);

    // Assert
    ASSERT_NEAR(413.3858, output, 0.01);
}

TEST(test_sokova_anastasia_length_converter, Can_Convert_inch_to_meter) {
    // Arrange
    LengthConverter converter;
    double input = 413.3858;
    double output;

    // Act
    output = converter.m_inch(input, true);

    // Assert
    ASSERT_NEAR(10.5, output, 0.01);
}

TEST(test_sokova_anastasia_length_converter, meter_to_inch_with_zero) {
    // Arrange
    LengthConverter converter;
    double input = 0.0;
    double output;

    // Act
    output = converter.m_inch(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(0.0, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_inch_with_negative) {
    // Arrange
    LengthConverter converter;
    double input = -5.0;
    double output;

    // Act
    output = converter.m_inch(input, false);

    // Assert
    ASSERT_DOUBLE_EQ(-1, output);
}

TEST(test_sokova_anastasia_length_converter, meter_to_inch_with_int) {
    // Arrange
    LengthConverter converter;
    double input = 10;
    double output;

    // Act
    output = converter.m_inch(input, false);

    // Assert
    ASSERT_NEAR(393.701, output, 0.01);
}
