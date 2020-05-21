// Copyright 2020 Andreev Sergey

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/priority_queue_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class pq_app_Test : public ::testing::Test {
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
    pq_app app_;
    string output_;
};

TEST_F(pq_app_Test, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a priority queue application\\..*");
}

TEST_F(pq_app_Test, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1" };

    Act(args);

    Assert("ERROR: Should be 4 arguments\\..*");
}

TEST_F(pq_app_Test, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "3", "hello", "1",
        "2", "2", "3", "3", "extractMin" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(pq_app_Test, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "3", "1", "1",
        "2", "2", "3", "3", "wrong" };

    Act(args);

    Assert("Wrong format!");
}

TEST_F(pq_app_Test, Can_Return_Min_Value_Key) {
    vector<string> args = { "3", "1", "100",
        "2", "2", "3", "3", "extractMin" };

    Act(args);

    Assert("Min value = 100");
}

TEST_F(pq_app_Test, Can_Return_Max_Value_Key) {
    vector<string> args = { "3", "1", "1",
        "2", "2", "3", "300", "extractMax" };

    Act(args);

    Assert("Max value = 300");
}
