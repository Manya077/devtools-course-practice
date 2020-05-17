// Copyright 2020 Sokolov Nikolay

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/fraction.h"
#include "include/fraction_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class FractionCalculatorTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    FractionCalculator app_;
    string output_;
};

TEST_F(FractionCalculatorTest, Can_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a fraction calculator application\\..*");
}

TEST_F(FractionCalculatorTest, Check_Number_Of_Arguments_2) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be 3, 4 or 5 arguments\\..*");
}

TEST_F(FractionCalculatorTest, Check_Number_Of_Arguments_6) {
    vector<string> args = { "1", "2", "3", "4", "5", "6" };

    Act(args);

    Assert("ERROR: Should be 3, 4 or 5 arguments\\..*");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Number_Format_3) {
    vector<string> args = { "sda", "1", "+" };

    Act(args);

    Assert("Wrong number format!*");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Number_Format_4) {
    vector<string> args = { "sda", "1", "1", "+" };

    Act(args);

    Assert("Wrong number format!*");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Number_Format_5) {
    vector<string> args = { "sda", "1", "1", "dssd", "+" };

    Act(args);

    Assert("Wrong number format!*");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Number_Size_Format_3) {
    vector<string> args = { "10000000000000000000000000000000000000000000000",
        "1", "+" };

    Act(args);

    Assert("Wrong number format!*");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Number_Size_Format_4) {
    vector<string> args = { "10000000000000000000000000000000000000000000000",
        "1", "1", "+" };

    Act(args);

    Assert("Wrong number format!*");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Number_Size_Format_5) {
    vector<string> args = { "1", "1", "1",
        "100000000000000000000000000000000000000000000000", "+" };

    Act(args);

    Assert("Wrong number format!*");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Operation_Format_5) {
    vector<string> args = { "4", "1", "1", "1", "wdw" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Operation_Format_4) {
    vector<string> args = { "4", "1", "1", "d" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(FractionCalculatorTest, Can_Detect_Wrong_Operation_Format_3) {
    vector<string> args = { "4", "1", "+" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(FractionCalculatorTest, Can_Add_Fractions) {
    vector<string> args = {"1", "2", "3", "4", "+" };

    Act(args);

    Assert("Numerator = 5 Denominator = 4");
}

TEST_F(FractionCalculatorTest, Can_Add_Fraction_With_number) {
    vector<string> args = { "1", "2", "3", "+" };

    Act(args);

    Assert("Numerator = 7 Denominator = 2");
}


TEST_F(FractionCalculatorTest, Can_Sub_Fractions) {
    vector<string> args = {"1", "2", "3", "4", "-" };

    Act(args);

    Assert("Numerator = -1 Denominator = 4");
}

TEST_F(FractionCalculatorTest, Can_Sub_Fractions_With_number) {
    vector<string> args = { "1", "2", "3", "-" };

    Act(args);

    Assert("Numerator = -5 Denominator = 2");
}

TEST_F(FractionCalculatorTest, Can_Mult_Fractions) {
    vector<string> args = { "1", "2", "3", "4", "*" };

    Act(args);

    Assert("Numerator = 3 Denominator = 8");
}

TEST_F(FractionCalculatorTest, Can_Mult_Fractions_With_number) {
    vector<string> args = { "1", "2", "3", "*" };

    Act(args);

    Assert("Numerator = 3 Denominator = 2");
}

TEST_F(FractionCalculatorTest, Can_Div_Fractions) {
    vector<string> args = { "1", "2", "3", "4", "/" };

    Act(args);

    Assert("Numerator = 2 Denominator = 3");
}

TEST_F(FractionCalculatorTest, Can_Div_Fractions_With_Number) {
    vector<string> args = { "1", "2", "3", "/" };

    Act(args);

    Assert("Numerator = 1 Denominator = 6");
}

TEST_F(FractionCalculatorTest, Can_Detect_Zero_Denomirator) {
    vector<string> args = { "1", "0", "2", "0", "+"};

    Act(args);

    Assert("Denominator can`t be zero. Use denominator = 1");
}

TEST_F(FractionCalculatorTest, Can_Detect_Zero_Div_On_Fraction_Number) {
    vector<string> args = { "3", "1", "0", "/" };

    Act(args);

    Assert("Divider can`t be zero");
}

TEST_F(FractionCalculatorTest, Can_Detect_Zero_Div_On_Fractions) {
    vector<string> args = { "3", "1", "0", "2", "/" };

    Act(args);

    Assert("Numerator divider can`t be zero");
}

TEST_F(FractionCalculatorTest, Can_To_Double_Fraction) {
    vector<string> args = {"1", "2", "d" };

    Act(args);

    Assert("Double fraction = 0.5");
}

TEST_F(FractionCalculatorTest, Can_Use_Reduction_Fraction) {
    vector<string> args = { "2", "4", "r" };

    Act(args);

    Assert("Numerator = 1 Denominator = 2");
}

TEST_F(FractionCalculatorTest, Can_Use_Increase_Fraction) {
    vector<string> args = { "1", "2", "3", "i" };

    Act(args);

    Assert("Numerator = 3 Denominator = 6");
}

TEST_F(FractionCalculatorTest, Can_Detect_Zero_Increase_Fraction) {
    vector<string> args = { "1", "2", "0", "i" };

    Act(args);

    Assert("Argument is Zero");
}

TEST_F(FractionCalculatorTest, Bool_Operation_More_Fractions) {
    vector<string> args = { "1", "2", "3", "4", "<" };

    Act(args);

    Assert("True");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Less_Fractions) {
    vector<string> args = { "1", "2", "3", "4", ">" };

    Act(args);

    Assert("False");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Equally_Fractions) {
    vector<string> args = { "1", "2", "2", "4", "=" };

    Act(args);

    Assert("True");
}

TEST_F(FractionCalculatorTest, Bool_Operation_More_Fraction_With_Number) {
    vector<string> args = { "7", "2", "4", "<" };

    Act(args);

    Assert("True");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Less_Fraction_With_Number) {
    vector<string> args = { "7", "2", "4", ">" };

    Act(args);

    Assert("False");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Equally_Fraction_With_Number) {
    vector<string> args = { "4", "2", "2", "=" };

    Act(args);

    Assert("True");
}

TEST_F(FractionCalculatorTest, Bool_Operation_More_In_Fraction) {
    vector<string> args = { "7", "2", "<" };

    Act(args);

    Assert("Denominator is not greater than Numerator");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Less_In_Fraction) {
    vector<string> args = { "7", "2", ">" };

    Act(args);

    Assert("Numerator is greater than Denominator");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Equally_In_Fraction) {
    vector<string> args = { "5", "5", "=" };

    Act(args);

    Assert("Numerator is equal to Denominator");
}

TEST_F(FractionCalculatorTest, Bool_Operation_More_Fractions_No) {
    vector<string> args = { "6", "2", "3", "4", "<" };

    Act(args);

    Assert("False");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Less_Fractions_No) {
    vector<string> args = { "1", "2", "1", "4", ">" };

    Act(args);

    Assert("True");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Equally_Fractions_No) {
    vector<string> args = { "1", "2", "18", "4", "=" };

    Act(args);

    Assert("False");
}

TEST_F(FractionCalculatorTest, Bool_Operation_More_Fraction_With_Number_No) {
    vector<string> args = { "10", "2", "4", "<" };

    Act(args);

    Assert("False");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Less_Fraction_With_Number_No) {
    vector<string> args = { "7", "2", "3", ">" };

    Act(args);

    Assert("True");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Equally_Fraction_With_Number_No) {
    vector<string> args = { "4", "5", "1", "=" };

    Act(args);

    Assert("False");
}

TEST_F(FractionCalculatorTest, Bool_Operation_More_In_Fraction_No) {
    vector<string> args = { "1", "2", "<" };

    Act(args);

    Assert("Denominator is greater than Numerator");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Less_In_Fraction_No) {
    vector<string> args = { "7", "9", ">" };

    Act(args);

    Assert("Numerator is not greater than Denominator");
}

TEST_F(FractionCalculatorTest, Bool_Operation_Equally_In_Fraction_No) {
    vector<string> args = { "5", "4", "=" };

    Act(args);

    Assert("Numerator is not equal to Denominator");
}
