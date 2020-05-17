// Copyright 2020 Egorov Danil

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/converter_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Converter_impl_Test : public ::testing::Test {
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
    Converter_impl app_;
    string output_;
};

TEST_F(Converter_impl_Test, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a temperature converter application\\..*");
}

TEST_F(Converter_impl_Test, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1"};

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(Converter_impl_Test, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"pi", "kelv"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(Converter_impl_Test, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"1", "garbage"};

    Act(args);

    Assert("Wrong format!");
}

TEST_F(Converter_impl_Test, Can_Convert_to_Kelvins) {
    vector<string> args = {"27.54", "kelv"};

    Act(args);

    Assert("Celsius = 27.54 Kelvins = 300.69");
}

TEST_F(Converter_impl_Test, Can_Convert_to_Fahrenheit) {
    vector<string> args = {"27.54", "fahr"};

    Act(args);

    Assert("Celsius = 27.54 Farenheits = 81.572");
}

TEST_F(Converter_impl_Test, Can_Convert_to_Newton) {
    vector<string> args = {"27.54", "newt"};

    Act(args);

    Assert("Celsius = 27.54 Newtons = 9.0882");
}
