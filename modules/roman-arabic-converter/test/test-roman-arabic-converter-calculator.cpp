// Copyright 2020 Arisova Anastasiia

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "../include/roman-arabic-converter-calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class RAConvertCalculatorTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

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
    RomanArabicConvertCalculator app_;
    string output_;
};

TEST_F(RAConvertCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a Roman-Arabic Convert calculator application\\..*");
}

TEST_F(RAConvertCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: incorrect number of parameters. Please try again.*");
}

TEST_F(RAConvertCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"1", "+", "4"};

    Act(args);

    Assert("Wrong mode format!");
}

TEST_F(RAConvertCalculatorTest, Can_Convert_Arabic_To_Roman_One_Number) {
    vector<string> args = {"1", "arabic_to_roman", "5"};

    Act(args);

    Assert("Results of the conversion: 5 -> V");
}

TEST_F(RAConvertCalculatorTest, Can_Convert_Roman_To_Arabic_One_Number) {
    vector<string> args = {"1", "roman_to_arabic", "IX"};

    Act(args);

    Assert("Results of the conversion: IX -> 9");
}

TEST_F(RAConvertCalculatorTest, Can_Convert_Roman_To_Arabic_Two_Numbers) {
    vector<string> args =
        {"2", "roman_to_arabic", "IX", "roman_to_arabic", "XII"};

    Act(args);

    Assert("Results of the conversion: IX -> 9   XII -> 12");
}

TEST_F(RAConvertCalculatorTest, Can_Convert_Arabic_To_Roman_Two_Numbers) {
    vector<string> args =
        {"2", "arabic_to_roman", "11", "arabic_to_roman", "20"};

    Act(args);

    Assert("Results of the conversion: 11 -> XI   20 -> XX");
}

TEST_F(RAConvertCalculatorTest, Can_Convert_Two_Number_In_Different_Mode_1) {
    vector<string> args =
        {"2", "arabic_to_roman", "11", "roman_to_arabic", "X"};

    Act(args);

    Assert("Results of the conversion: 11 -> XI   X -> 10");
}

TEST_F(RAConvertCalculatorTest, Can_Convert_Two_Number_In_Different_Mode_2) {
    vector<string> args =
        {"2", "roman_to_arabic", "XIX", "arabic_to_roman", "20"};

    Act(args);

    Assert("Results of the conversion: XIX -> 19   20 -> XX");
}

TEST_F(RAConvertCalculatorTest, Can_Convert_Three_Numbers) {
    vector<string> args =
        {"3", "arabic_to_roman", "11",
        "roman_to_arabic", "X", "arabic_to_roman", "20"};

    Act(args);

    Assert("Results of the conversion: 11 -> XI   X -> 10   20 -> XX");
}
