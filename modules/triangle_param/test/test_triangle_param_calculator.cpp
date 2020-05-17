// Copyright 2020 Kudryashov Nikita

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "../include/triangle_param_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class TriangleParamCalculatorTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_.calculate(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    TriangleParamCalculator app_;
    string output_;
};

TEST_F(TriangleParamCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("Follow syntax rules:");
}

TEST_F(TriangleParamCalculatorTest, Wrong_Top_Name) {
    vector<string> args = {"a", "0", "0", "b", "1", "0",
        "c", "0", "1"};
    Act(args);

    Assert("Wrong top names arguments. Please, follow the syntax.\n");
}

TEST_F(TriangleParamCalculatorTest, All_Points_Are_In_The_Same_Line) {
    vector<string> args = {"A", "0", "0", "B", "1", "1",
        "C", "2", "2"};
    Act(args);

    Assert("Three of your points are in the same line\n.");
}

TEST_F(TriangleParamCalculatorTest, Wrong_Numbers_Type) {
    vector<string> args = {"A", "a", "c", "B", "0", "1",
        "C", "0", "2"};
    Act(args);

    Assert("Wrong number type arguments. Please, follow the syntax.\n");
}

TEST_F(TriangleParamCalculatorTest, Can_Work_With_No_Requests) {
    vector<string> args = {"A", "0", "0", "B", "0", "1",
        "C", "1", "0"};
    Act(args);

    Assert("Requested calculations:\n");
}

TEST_F(TriangleParamCalculatorTest, Wrong_Requests) {
    vector<string> args = {"A", "0", "0", "B", "0", "1",
        "C", "1", "0", "asddasd"};
    Act(args);

    Assert("Wrong requests arguments. Please, follow the syntax.\n");
}

TEST_F(TriangleParamCalculatorTest, LengthAB_Req) {
    vector<string> args = {"A", "0", "0", "B", "0", "1",
        "C", "1", "0", "LengthAB"};
    Act(args);

    Assert("Requested calculations:\n1. LengthAB = 1");
}

TEST_F(TriangleParamCalculatorTest, LengthBC_Req) {
    vector<string> args = {"A", "0", "0", "B", "0", "1",
        "C", "1", "0", "LengthBC"};
    Act(args);

    Assert("Requested calculations:\n1. LengthBC = 1.414214");
}

TEST_F(TriangleParamCalculatorTest, LengthAC_Req) {
    vector<string> args = {"A", "0", "0", "B", "0", "1",
        "C", "1", "0", "LengthAC"};
    Act(args);

    Assert("Requested calculations:\n1. LengthAC = 1");
}

TEST_F(TriangleParamCalculatorTest, CornerA_Req) {
    vector<string> args = {"A", "0", "0", "B", "0", "1",
        "C", "1", "0", "CornerA"};
    Act(args);

    Assert("Requested calculations:\n1. CornerA = 1.570796");
}

TEST_F(TriangleParamCalculatorTest, CornerB_Req) {
    vector<string> args = {"A", "0", "0", "B", "0", "1",
        "C", "1", "0", "CornerB"};
    Act(args);

    Assert("Requested calculations:\n1. CornerB = 0.785398");
}

TEST_F(TriangleParamCalculatorTest, CornerC_Req) {
    vector<string> args = {"A", "0", "0", "B", "0", "1",
        "C", "1", "0", "CornerC"};
    Act(args);

    Assert("Requested calculations:\n1. CornerC = 0.785398");
}

TEST_F(TriangleParamCalculatorTest, Perimeter_Req) {
    vector<string> args = {"A", "0", "0", "B", "0", "1",
        "C", "1", "0", "Perimeter"};
    Act(args);

    Assert("Requested calculations:\n1. Perimeter = 3.414214");
}

TEST_F(TriangleParamCalculatorTest, Square_Req) {
    vector<string> args = {"A", "0", "0", "B", "0", "1",
        "C", "1", "0", "Square"};
    Act(args);

    Assert("Requested calculations:\n1. Square = 0.5");
}
