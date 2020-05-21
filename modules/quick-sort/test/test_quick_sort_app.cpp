// Copyright 2020 Poletueva Anastasia

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/quick_sort_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class QuickSortTest : public ::testing::Test {
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
    QuickSortApp app_;
    string output_;
};

TEST_F(QuickSortTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a quick sort application\\..*");
}

TEST_F(QuickSortTest, Can_Sort_Array__5) {
  vector<string> args = { "9", "4", "5", "2", "7"};

  Act(args);

  Assert("2 4 5 7 9");
}

TEST_F(QuickSortTest, Can_Sort_Array_20) {
  vector<string> args = { "9", "4", "5", "2", "7",
    "6", "23", "1", "12", "34", "43", "44", "3", "32", "54",
    "37", "25", "87", "53", "123" };

  Act(args);

  Assert("1 2 3 4 5 6 7 9 12 23 25 32 34 37 43 44 53 54 87 123");
}

TEST_F(QuickSortTest, Wrong_Format) {
  vector<string> args = { "dgfhjk" };

  Act(args);

  Assert("Wrong number format!");
}

TEST_F(QuickSortTest, Wrong_Format_With_Numbers) {
  vector<string> args = { "5", "3", "6", "tut" };

  Act(args);

  Assert("Wrong number format!");
}
