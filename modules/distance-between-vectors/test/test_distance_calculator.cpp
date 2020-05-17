// Copyright 2020 Sokolov Andrey

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/distance_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class DistanceCalculatorTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("DistanceCalculator");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    DistanceCalculator app_;
    string output_;
};

TEST_F(DistanceCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a distance between vectors calculator application.");
}

TEST_F(DistanceCalculatorTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1.0", "2.0", "3.0", "1.0", "2.0", "L1"};

    Act(args);

    Assert("Should be 7 arguments!");
}

TEST_F(DistanceCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1.0", "zero", "3.0", "1.0", "2.0", "3.0", "L1"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(DistanceCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"1.0", "2.0", "3.0", "1.0", "2.0", "3.0", "L5"};

    Act(args);

    Assert("Wrong operation name!");
}

TEST_F(DistanceCalculatorTest, Can_Take_L1_Metrics) {
    vector<string> args = {"1.0", "2.0", "3.0", "2.0", "3.0", "4.0", "L1"};

    Act(args);

    Assert("L1 = 3");
}

TEST_F(DistanceCalculatorTest, Can_Take_L2_Metrics) {
    vector<string> args = { "1.0", "2.0", "3.0", "2.0", "3.0", "4.0", "L2" };

    Act(args);

    Assert("L2 = 1.73205");
}

TEST_F(DistanceCalculatorTest, Can_Take_L3_Metrics) {
    vector<string> args = { "3.0", "1.0", "1.0", "2.0", "3.0", "4.0", "L3" };

    Act(args);

    Assert("L3 = 3.30193");
}

TEST_F(DistanceCalculatorTest, Can_Take_L4_Metrics) {
    vector<string> args = { "3.0", "1.0", "1.0", "2.0", "3.0", "4.0", "L4" };

    Act(args);

    Assert("L4 = 3.14635");
}

TEST_F(DistanceCalculatorTest, Can_Take_LInf_Metrics) {
    vector<string> args = { "3.0", "1.0", "1.0", "2.0", "3.0", "4.0", "LInf" };

    Act(args);

    Assert("LInf = 3");
}
