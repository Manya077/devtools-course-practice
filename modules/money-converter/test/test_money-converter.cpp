// Copyright 2020 Brazhnikov Eugene

#include <gtest/gtest.h>
#include "include/Money_Converter.h"

TEST(test_brazhnikov_eugene_money_converter, Can_Create) {
    ASSERT_NO_THROW(MoneyConverter a);
}

TEST(test_brazhnikov_eugene_money_converter, Can_Convert_RUB_to_USD) {
    MoneyConverter converter;
    double input = 1;
    double output;

    output = converter.rubUSD(input, 0);

    ASSERT_NEAR(0.012, output, 0.1);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_USD_with_negative) {
    MoneyConverter converter;
    double input = -12.0;
    double output;

    output = converter.rubUSD(input, 0);

    ASSERT_DOUBLE_EQ(-1, output);
}

TEST(test_brazhnikov_eugene_money_converter, Can_USD_to_RUB) {
    MoneyConverter converter;
    double input = 1.0;
    double output;

    output = converter.rubUSD(input, 1);

    ASSERT_NEAR(77.730, output, 0.1);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_USD_equal_zero) {
    MoneyConverter converter;
    double input = 0.0;
    double output;

    output = converter.rubUSD(input, 0);

    ASSERT_DOUBLE_EQ(0.0, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_USD_with_int) {
    MoneyConverter converter;
    double input = 10;
    double output;

    output = converter.rubJPY(input, 0);

    ASSERT_NEAR(0.128, output, 0.1);
}

// ===================================

TEST(test_brazhnikov_eugene_money_converter, Can_Convert_Rub_to_Eur) {
    MoneyConverter converter;
    double input = 85.73;
    double output;

    output = converter.rubEUR(input, 0);

    ASSERT_DOUBLE_EQ(1, output);
}

TEST(test_brazhnikov_eugene_money_converter, Can_Convert_EUR_to_RUB) {
    MoneyConverter converter;
    double input = 1;
    double output;

    output = converter.rubEUR(input, 1);

    ASSERT_DOUBLE_EQ(85.73, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_EUR_equal_zero) {
    MoneyConverter converter;
    double input = 0.0;
    double output;

    output = converter.rubEUR(input, 0);

    ASSERT_DOUBLE_EQ(0.0, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_EUR_with_negative) {
    MoneyConverter converter;
    double input = -12.0;
    double output;

    output = converter.rubEUR(input, 0);

    ASSERT_DOUBLE_EQ(-1, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_EUR_with_int) {
    MoneyConverter converter;
    double input = 10;
    double output;

    output = converter.rubEUR(input, 0);

    ASSERT_NEAR(0.116, output, 0.1);
}

// ============================

TEST(test_brazhnikov_eugene_money_converter, Can_Convert_Rub_to_JPY) {
    MoneyConverter converter;
    double input = 71.40;
    double output;

    output = converter.rubJPY(input, 0);

    ASSERT_DOUBLE_EQ(1, output);
}

TEST(test_brazhnikov_eugene_money_converter, Can_Convert_JPY_to_RUB) {
    MoneyConverter converter;
    double input = 1;
    double output;

    output = converter.rubJPY(input, 1);

    ASSERT_DOUBLE_EQ(71.40, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_JPY_equal_zero) {
    MoneyConverter converter;
    double input = 0.0;
    double output;

    output = converter.rubJPY(input, 0);

    ASSERT_DOUBLE_EQ(0.0, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_JPY_with_negative) {
    MoneyConverter converter;
    double input = -12.0;
    double output;

    output = converter.rubJPY(input, 0);

    ASSERT_DOUBLE_EQ(-1, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_JPY_with_int) {
    MoneyConverter converter;
    double input = 10;
    double output;

    output = converter.rubJPY(input, 0);

    ASSERT_NEAR(0.14, output, 0.1);
}

// ===================================

TEST(test_brazhnikov_eugene_money_converter, Can_Convert_RUB_to_SEK) {
    MoneyConverter converter;
    double input = 78;
    double output;

    output = converter.rubSEK(input, 0);

    ASSERT_DOUBLE_EQ(1, output);
}

TEST(test_brazhnikov_eugene_money_converter, Can_Convert_SEK_to_RUB) {
    MoneyConverter converter;
    double input = 1;
    double output;

    output = converter.rubSEK(input, 1);

    ASSERT_DOUBLE_EQ(78, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_SEK_equal_zero) {
    MoneyConverter converter;
    double input = 0.0;
    double output;

    output = converter.rubSEK(input, 0);

    ASSERT_DOUBLE_EQ(0.0, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_SEK_with_negative) {
    MoneyConverter converter;
    double input = -12.0;
    double output;

    output = converter.rubSEK(input, 0);

    ASSERT_DOUBLE_EQ(-1, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_SEK_with_int) {
    MoneyConverter converter;
    double input = 10;
    double output;

    output = converter.rubJPY(input, 0);

    ASSERT_NEAR(0.128, output, 0.1);
}

// =================================

TEST(test_brazhnikov_eugene_money_converter, Can_Convert_RUB_to_UAH) {
    MoneyConverter converter;
    double input = 1.0;
    double output;

    output = converter.rubUAH(input, 0);

    ASSERT_NEAR(0.36, output, 0.1);
}

TEST(test_brazhnikov_eugene_money_converter, Can_Convert_UAH_to_RUB) {
    MoneyConverter converter;
    double input = 1;
    double output;

    output = converter.rubUAH(input, 1);

    ASSERT_NEAR(2.79, output, 0.1);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_UAH_with_zero) {
    MoneyConverter converter;
    double input = 0.0;
    double output;

    output = converter.rubUAH(input, 0);

    ASSERT_DOUBLE_EQ(0.0, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_UAH_with_negative) {
    MoneyConverter converter;
    double input = -12.0;
    double output;

    output = converter.rubUAH(input, 1);

    ASSERT_DOUBLE_EQ(-1, output);
}

TEST(test_brazhnikov_eugene_money_converter, Rub_to_UAH_with_int) {
    MoneyConverter converter;
    double input = 10;
    double output;

    output = converter.rubUAH(input, 0);

    ASSERT_NEAR(3.58, output, 0.1);
}
