// Copyright 2020 Dobrohotov Vitaly

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/prime_nums_for_app.h"

class PrimeNumsAppTest : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> parameters;
        parameters.push_back("prime_nums_app.exe");
        for (size_t i = 0; i < args_.size(); ++i) {
            parameters.push_back(args_[i].c_str());
        }
        const char** argv = &parameters.front();
        int argc = static_cast<int>(args_.size()) + 1;
        output_ = app_(argc, argv);
    }
    void Assert(std::string expected) { EXPECT_EQ(expected, output_); }

 private:
    PrimeNums app_;
    std::string output_;
};

TEST_F(PrimeNumsAppTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};
    std::ostringstream  answer;
    answer << "ERROR: Should be 2 arguments\n"
        << "This is a primary numbers application."
        << "\nPlease provide arguments in the following format:\n"
        << "<left border> <right border>\n"
        << "Where all arguments are int numbers,"
        << "\nleft border less than right border,"
        << "\nboth of border not equal null,"
        << "\nand must be possitive number";

    Act(args);

    Assert(answer.str());
}

TEST_F(PrimeNumsAppTest, check_argc_with_1_args) {
    std::vector<std::string> args = { "0" };
    std::ostringstream answer;
    answer << "ERROR: Should be 2 arguments\n"
        << "This is a primary numbers application."
        << "\nPlease provide arguments in the following format:\n"
        << "<left border> <right border>\n"
        << "Where all arguments are int numbers,"
        << "\nleft border less than right border,"
        << "\nboth of border not equal null,"
        << "\nand must be possitive number";

    Act(args);

    Assert(answer.str());
}

TEST_F(PrimeNumsAppTest, check_argc_with_3_args) {
    std::vector<std::string> args = { "0", " 1", "45" };
    std::ostringstream answer;
    answer << "ERROR: Should be 2 arguments\n"
        << "This is a primary numbers application."
        << "\nPlease provide arguments in the following format:\n"
        << "<left border> <right border>\n"
        << "Where all arguments are int numbers,"
        << "\nleft border less than right border,"
        << "\nboth of border not equal null,"
        << "\nand must be possitive number";

    Act(args);

    Assert(answer.str());
}

TEST_F(PrimeNumsAppTest, check_argc_with_2_args) {
    std::vector<std::string> args = { "1", "10" };
    std::string str = "Interval: 1-10\n";
    str += "Primary numbers: 2 3 5 7 ";

    Act(args);

    Assert(str);
}

TEST_F(PrimeNumsAppTest, can_detect_negative_left_border) {
    std::vector<std::string> args = { "-2", "10" };
    std::ostringstream answer;
    answer << "ERROR: Left border can't be less than zero\n"
        << "This is a primary numbers application."
        << "\nPlease provide arguments in the following format:\n"
        << "<left border> <right border>\n"
        << "Where all arguments are int numbers,"
        << "\nleft border less than right border,"
        << "\nboth of border not equal null,"
        << "\nand must be possitive number";

    Act(args);

    Assert(answer.str());
}

TEST_F(PrimeNumsAppTest, can_detect_that_left_bigger_than_right_border) {
    std::vector<std::string> args = { "20", "10" };
    std::ostringstream answer;
    answer << "ERROR: Left border must be less than right\n"
        << "This is a primary numbers application."
        << "\nPlease provide arguments in the following format:\n"
        << "<left border> <right border>\n"
        << "Where all arguments are int numbers,"
        << "\nleft border less than right border,"
        << "\nboth of border not equal null,"
        << "\nand must be possitive number";

    Act(args);

    Assert(answer.str());
}


TEST_F(PrimeNumsAppTest, can_detect_incorrect_input_data) {
    std::vector<std::string> args = { "ads", "10" };
    std::ostringstream answer;
    answer << "ERROR: incorrect input data\n"
        << "This is a primary numbers application."
        << "\nPlease provide arguments in the following format:\n"
        << "<left border> <right border>\n"
        << "Where all arguments are int numbers,"
        << "\nleft border less than right border,"
        << "\nboth of border not equal null,"
        << "\nand must be possitive number";

    Act(args);

    Assert(answer.str());
}
