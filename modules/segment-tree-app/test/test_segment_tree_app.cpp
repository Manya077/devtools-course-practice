// Copyright 2020 Boganov Sergei

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/segment_tree_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class SegmentTreeAppTest : public ::testing::Test {
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
    SegmentTreeApp app_;
    string output_;
};

TEST_F(SegmentTreeAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a segment tree application\\..*");
}

TEST_F(SegmentTreeAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("Oops, incorrect number of parameters\\..*");
}

TEST_F(SegmentTreeAppTest, Is_Checking_Number_Of_Arguments_2) {
    vector<string> args = {"3", "1", "2", "3", "1", "0", "max"};

    Act(args);

    Assert("Oops, incorrect number of parameters\\..*");
}

TEST_F(SegmentTreeAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"3", "1", "2", "e", "1", "0", "2", "max"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(SegmentTreeAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"2", "1", "3", "1", "0", "1", "garbage"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(SegmentTreeAppTest, Test_Range_Sum_Query_With_5_elements) {
    vector<string> args = {
        "5", "1", "2", "3", "4", "5", "1", "0", "2", "+"};

    Act(args);

    Assert("Answers on queries: 6");
}

TEST_F(SegmentTreeAppTest, Test_Range_Sum_Query_With_4_elements) {
    vector<string> args = {
        "4", "1", "2", "3", "4", "2", "2", "3", "0", "1", "+"};

    Act(args);

    Assert("Answers on queries: 7, 3");
}

TEST_F(SegmentTreeAppTest, Test_Range_Sum_Query_With_2_elements) {
    vector<string> args = {"2", "1", "2", "1", "-1", "1", "+"};

    Act(args);

    Assert("left or right interval cannot be negative");
}

TEST_F(SegmentTreeAppTest, Test_Range_Sum_Query_With_2_elements_2) {
    vector<string> args = {"2", "1", "2", "1", "1", "0", "+"};

    Act(args);

    Assert("left interval cannot be > than right");
}

TEST_F(SegmentTreeAppTest, Test_Range_Sum_Query_With_2_elements_3) {
    vector<string> args = {"2", "1", "2", "1", "1", "3", "+"};

    Act(args);

    Assert("right interval cannot be > that size");
}

TEST_F(SegmentTreeAppTest, Test_Range_Max_Query_With_5_elements) {
    vector<string> args = {
        "5", "1", "2", "3", "4", "5", "2", "0", "2", "1", "4", "max"};

    Act(args);

    Assert("Answers on queries: 3, 5");
}

TEST_F(SegmentTreeAppTest, Test_Range_Min_Query_With_4_elements) {
    vector<string> args = {
        "4", "1", "2", "3", "4", "3", "0", "1", "1", "3", "2", "3", "min"};

    Act(args);

    Assert("Answers on queries: 1, 2, 3");
}

TEST_F(SegmentTreeAppTest, Test_Range_Gcd_Query_With_6_elements) {
    vector<string> args = {
        "3", "1", "2", "6", "2", "0", "1", "1", "2", "gcd"};

    Act(args);

    Assert("Answers on queries: 1, 2");
}
