// Copyright 2020 Zinkov Artem

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/merge_batcher_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Merge_Batcher_App_Test : public ::testing::Test {
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
    Merge_Batcher_App app_;
    string output_;
};

TEST_F(Merge_Batcher_App_Test, Do_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("This is a merge batcher application\\..*");
}

TEST_F(Merge_Batcher_App_Test, Is_Checking_Number_Of_Arguments) {
    // Arrange
    vector<string> args = { "1" };

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Should be 2 arguments.");
}

TEST_F(Merge_Batcher_App_Test, Can_Detect_Wrong_Number_Format) {
    // Arrange
    vector<string> args = { "1,2,3", "45,t,67" };

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Wrong format!");
}

TEST_F(Merge_Batcher_App_Test, Merge_With_Empty_Vector) {
    // Arrange
    vector<string> args = { "1,2,3", "" };

    // Act
    Act(args);

    // Assert
    Assert("result vector = 1 2 3");
}

TEST_F(Merge_Batcher_App_Test, Merge_Unsorted_Vector) {
    // Arrange
    vector<string> args = { "4,23,5", "93,2,54" };

    // Act
    Act(args);

    // Assert
    Assert("result vector = 2 4 5 23 54 93");
}

TEST_F(Merge_Batcher_App_Test, Merge_Vectors_With_Negative_Arguments) {
    // Arrange
    vector<string> args = { "-1,9,18", "-74" };

    // Act
    Act(args);

    // Assert
    Assert("result vector = -74 -1 9 18");
}
