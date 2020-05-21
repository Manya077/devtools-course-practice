// Copyright 2020 Baldin Alexey

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/vector3D.h"
#include "include/vector3D_application.h"
#include "include/vector3D_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Vector3DCalculatorTest : public ::testing::Test {
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
    Vector3DApplication app_;
    string output_;
};

TEST_F(Vector3DCalculatorTest, Can_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a 3d vector calculator application\\..*");
}

TEST_F(Vector3DCalculatorTest, Check_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("Should be 4 or 7 arguments\\..*");
}

TEST_F(Vector3DCalculatorTest, Can_Detect_Wrong_Number_Format4) {
    vector<string> args = { "q", "1", "1", "+" };

    Act(args);

    Assert("Wrong number format!*");
}

TEST_F(Vector3DCalculatorTest, Can_Detect_Wrong_Number_Format7) {
    vector<string> args = { "q", "1", "1", "1", "1", "1", "+" };

    Act(args);

    Assert("Wrong number format!*");
}

TEST_F(Vector3DCalculatorTest, Can_Detect_Wrong_Operation_Format7) {
    vector<string> args = { "1", "1", "1", "1", "1", "1", "q" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(Vector3DCalculatorTest, Can_Detect_Wrong_Operation_Format4) {
    vector<string> args = { "1", "1", "1", "q" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(Vector3DCalculatorTest, Can_Add_Vectors) {
    vector<string> args = { "1", "2", "3", "4", "5", "6", "+" };

    Act(args);

    Assert("X = 5 Y = 7 Z = 9");
}

TEST_F(Vector3DCalculatorTest, Can_Diff_Vectors) {
    vector<string> args = { "1", "2", "3", "4", "5", "6", "-" };

    Act(args);

    Assert("X = -3 Y = -3 Z = -3");
}

TEST_F(Vector3DCalculatorTest, Can_Normalize_Vector) {
    vector<string> args = { "1", "1", "1", "n" };

    Act(args);

    Assert("X = 0.57735 Y = 0.57735 Z = 0.57735");
}

TEST_F(Vector3DCalculatorTest, Normalize_Zero_Vector_Test) {
    vector<string> args = { "0", "0", "0", "n" };

    Act(args);

    Assert("can`t be zero\\..*");
}

TEST_F(Vector3DCalculatorTest, Can_Use_Scalar_Product) {
    vector<string> args = { "1", "2", "3", "4", "5", "6", "s" };

    Act(args);

    Assert("Scalar product = 32");
}

TEST_F(Vector3DCalculatorTest, Can_Use_Vector_Product) {
    vector<string> args = { "1", "2", "3", "4", "5", "6", "v" };

    Act(args);

    Assert("X = -3 Y = 6 Z = -3");
}

TEST_F(Vector3DCalculatorTest, Calculate_Length_Vector_Test) {
    vector<string> args = { "4", "4", "2", "l" };

    Act(args);

    Assert("Vector length = 6");
}
