// Copyright 2020 Suchkov Makar

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/bitfield-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class BitfieldappTest : public ::testing::Test {
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
    Bitfieldapp app_;
    string output_;
};

TEST_F(BitfieldappTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a Bitfield application\\..*");
}

TEST_F(BitfieldappTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be three arguments\\..*");
}

TEST_F(BitfieldappTest, Is_Checking_Type_Of_Arguments) {
    vector<string> args = {"1", "c", "c"};

    Act(args);

    Assert("ERROR: Wrong number format!");
}

TEST_F(BitfieldappTest, Can_One_Bitfield) {
    vector<string> args = {"1", "10", "3"};

    Act(args);

    Assert("0 0 0 1 0 0 0 0 0 0");
}

TEST_F(BitfieldappTest, Can_Three_Bitfield) {
    vector<string> args = {"3", "10", "6"};

    Act(args);

    Assert("1 1 1 1 1 1 0 1 1 1");
}
