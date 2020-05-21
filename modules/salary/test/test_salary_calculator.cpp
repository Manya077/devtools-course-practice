// Copyright 2020 Petrov Anton
#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/Salary_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class SalaryCalculatorTest : public ::testing::Test {
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
    SalaryCalculator app_;
    string output_;
};

TEST_F(SalaryCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a salary calculator application\\..*");
}

TEST_F(SalaryCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1000", "2000"};

    Act(args);

    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(SalaryCalculatorTest, Can_Set_All_Paramaters) {
    vector<string> args = { "40", "3", "6", "120000" };

    Act(args);

    Assert("payment = 117000");
}

TEST_F(SalaryCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "1000", "2000", "4000", "pi"};

    Act(args);

    Assert("Wrong number format!.*");
}
