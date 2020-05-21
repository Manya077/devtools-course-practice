// Copyright 2020 Antipin Alexander

#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "../include/radix_sort_app.h"

using ::testing::internal::RE;

class SortVectorAppTest : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("SortVectorApp");
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
    SortVectorApp app_;
    std::string output_;
};

TEST_F(SortVectorAppTest, Print_Help_If_No_Args_Given) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is a integer array sorting application\\..*");
}

TEST_F(SortVectorAppTest, Detects_Wrong_Args_1) {
    std::vector<std::string> args = { "10", "1", "-4", "someText" };

    Act(args);

    Assert("Wrong character in numbers");
}

TEST_F(SortVectorAppTest, Detects_Wrong_Args_2) {
    std::vector<std::string> args = { "10", "1", "-4", "-Someting" };

    Act(args);

    Assert("Wrong character in numbers");
}

TEST_F(SortVectorAppTest, Can_Sort_Some_Array) {
    std::vector<std::string> args = { "10", "1", "-4", "3" };

    Act(args);

    Assert("-4 1 3 10");
}

TEST_F(SortVectorAppTest, Can_Sort_Already_Sort_Array) {
    std::vector<std::string> args = { "-4", "1", "3", "10" };

    Act(args);

    Assert("-4 1 3 10");
}

TEST_F(SortVectorAppTest, Can_Sort_Reverse_Array) {
    std::vector<std::string> args = { "10", "3", "1", "-4" };

    Act(args);

    Assert("-4 1 3 10");
}
