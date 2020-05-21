// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <sstream>
#include <iostream>
#include <cmath>

#include "include/numerical_integration_app.h"
#include "include/numerical_integration.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class NumberIntegrationTest : public ::testing::Test {
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
    NumericalIntegrationApp app_;
    string output_;
};

class func1 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return x * x;
     }
};

class func2 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return sin(x);
     }
};

class func3 : public FunctionsForIntegration {
 public:
     double f(double x) {
         return x;
     }
};


class NumericalIntegrationTest : public NumericalIntegration {
 public:
     static const double epsilon;
     static const unsigned int N;

     static double F1(double x) {
         return (x * x * x) / 3.0;
     }
};

TEST_F(NumberIntegrationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a numerical integration application\\..*");
}

TEST_F(NumberIntegrationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2", "3"};

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Of_Iteration) {
    vector<string> args = {"1", "3", "-1", "2", "2"};

    Act(args);

    Assert("Incorrect <number_of_iteration>.*");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Of_Function) {
    vector<string> args = {"1", "3", "100", "4", "2"};

    Act(args);

    Assert("Incorrect <number_of_function>.*");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Of_Algorithm) {
    vector<string> args = {"1", "3", "100", "2", "7"};

    Act(args);

    Assert("Incorrect <number_of_algorithm>.*");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Format_Argument_1) {
    vector<string> args = {"1", "3", "=", "2", "7"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Format_Argument_2) {
    vector<string> args = {"pi", "3", "100", "2", "7"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Format_Argument_3) {
    vector<string> args = {"1", "left", "100", "2", "7"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Format_Argument_4) {
    vector<string> args = {"1", "3", "100", "first", "7"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumberIntegrationTest, Can_Detect_Wrong_Number_Format_Argument_5) {
    vector<string> args = {"1", "3", "100", "1", "second"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(NumberIntegrationTest, Test_Left_rectangle_method_in_app) {
    vector <string> args = {"1", "10", "10000", "1", "1"};
    double a = 1;
    double b = 10;
    int N = 10000;

    Left_rectangle_method obj(a, b);
    func1 f;

    string ans;
    ans += "Answer is ";
    double temp = obj.Integration_method(&f, N);
    std::stringstream ss;
    string s;
    ss << s << std::fixed << std::setprecision(4) << temp;
    s = ss.str();
    ans += s;

    Act(args);

    Assert(ans);
}


TEST_F(NumberIntegrationTest, Test_Right_rectangle_method_in_app) {
    vector <string> args = {"1", "5", "100000", "1", "2"};
    double a = 1;
    double b = 5;
    int N = 100000;

    Right_rectangle_method obj(a, b);
    func1 f;

    string ans;
    ans += "Answer is ";
    double temp = obj.Integration_method(&f, N);
    std::stringstream ss;
    string s;
    ss << s << std::fixed << std::setprecision(4) << temp;
    s = ss.str();
    ans += s;

    Act(args);

    Assert(ans);
}

TEST_F(NumberIntegrationTest, Test_Middle_rectangle_method_in_app) {
    vector <string> args = {"3", "10", "100000", "2", "3"};
    double a = 3;
    double b = 10;
    int N = 100000;

    Middle_rectangle_method obj(a, b);
    func2 f;

    string ans;
    ans += "Answer is ";
    double temp = obj.Integration_method(&f, N);
    std::stringstream ss;
    string s;
    ss << s << std::fixed << std::setprecision(4) << temp;
    s = ss.str();
    ans += s;

    Act(args);

    Assert(ans);
}

TEST_F(NumberIntegrationTest, Test_Trapezoid_method_in_app) {
    vector <string> args = {"3", "10", "100000", "2", "4"};
    double a = 3;
    double b = 10;
    int N = 100000;

    Trapezoid_method obj(a, b);
    func2 f;

    string ans;
    ans += "Answer is ";
    double temp = obj.Integration_method(&f, N);
    std::stringstream ss;
    string s;
    ss << s << std::fixed << std::setprecision(4) << temp;
    s = ss.str();
    ans += s;

    Act(args);

    Assert(ans);
}

TEST_F(NumberIntegrationTest, Test_Simpsons_method_in_app) {
    vector <string> args = {"1", "100", "10000", "3", "5"};
    double a = 1;
    double b = 100;
    int N = 10000;

    Simpsons_method obj(a, b);
    func3 f;

    string ans;
    ans += "Answer is ";
    double temp = obj.Integration_method(&f, N);
    std::stringstream ss;
    string s;
    ss << s << std::fixed << std::setprecision(4) << temp;
    s = ss.str();
    ans += s;

    Act(args);

    Assert(ans);
}

TEST_F(NumberIntegrationTest, Test_Gauss_method_in_app) {
    vector <string> args = {"1", "100", "100000", "3", "6"};
    double a = 1;
    double b = 100;
    int N = 100000;

    Gauss_method obj(a, b);
    func3 f;

    string ans;
    ans += "Answer is ";
    double temp = obj.Integration_method(&f, N);
    std::stringstream ss;
    string s;
    ss << s << std::fixed << std::setprecision(4) << temp;
    s = ss.str();
    ans += s;

    Act(args);

    Assert(ans);
}
