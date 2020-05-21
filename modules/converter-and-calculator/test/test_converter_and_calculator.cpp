// Copyright 2020 Zakharov Mikhail

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstring>

#include "include/converter_and_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Converter_and_CalculatorTest : public ::testing::Test {
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
    Converter_and_Calculator app_;
    string output_;
};

TEST_F(Converter_and_CalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a converter and calculator application\\..*");
}

TEST_F(Converter_and_CalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(Converter_and_CalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "pi", "1", "2", "+"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(Converter_and_CalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"10", "10", "1", "2", "garbage"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(Converter_and_CalculatorTest, Can_Sum_Decimal_And_Binary) {
    vector<string> args = {"157", "10", "1011", "2", "+"};

    Act(args);

    Assert("a = 157 b = 1011 c = 168");
}

TEST_F(Converter_and_CalculatorTest, Can_Diff_Decimal_And_Binary) {
    vector<string> args = {"157", "10", "234", "8", "-"};

    Act(args);

    Assert("a = 157 b = 234 c = 1");
}

TEST_F(Converter_and_CalculatorTest, Can_Mult_Two_Decimal) {
    vector<string> args = {"65", "10", "2", "10", "*"};

    Act(args);

    Assert("a = 65 b = 2 c = 130");
}

TEST_F(Converter_and_CalculatorTest, Can_Div_Two_Decimal) {
    vector<string> args = {"54", "10", "27", "10", "/"};

    Act(args);

    Assert("a = 54 b = 27 c = 2");
}

