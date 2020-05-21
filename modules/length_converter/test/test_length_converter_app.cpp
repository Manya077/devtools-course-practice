// Copyright 2020 Brazhnikov Eugene

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/length_converter_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class LengthCalculatorTest : public ::testing::Test {
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
    LengthCalculator app_;
    string output_;
};

TEST_F(LengthCalculatorTest, Can_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};
    // Act
    Act(args);
    // Assert
    Assert("This is a length calculator application\\..*");
}

TEST_F(LengthCalculatorTest, Can_Check_Number_Of_Arguments) {
    // Arrange
    vector<string> args = { "273.0" };
    // Act
    Act(args);
    // Assert
    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(LengthCalculatorTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    vector<string> args = { "five", "kilometer", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Wrong number format!.*");
}

TEST_F(LengthCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    // Arrange
    vector<string> args = { "1.5", "Operation", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Wrong operation format!");
}

TEST_F(LengthCalculatorTest, Kilometer_to_meter) {
    // Arrange
    vector<string> args = { "0.0", "kilometer", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Kilometer-meter converter: 0");
}

TEST_F(LengthCalculatorTest, Meter_to_Kilometer) {
    // Arrange
    vector<string> args = { "5.0", "kilometer", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Kilometer-meter converter: 0.005");
}

TEST_F(LengthCalculatorTest, Meter_to_Kilometer_minus) {
    // Arrange
    vector<string> args = { "-5.0", "kilometer", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Kilometer-meter converter: -1");
}

TEST_F(LengthCalculatorTest, santimeter_to_meter) {
    // Arrange
    vector<string> args = { "5.0", "santimeter", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Santimeter-meter converter: 500");
}

TEST_F(LengthCalculatorTest, meter_to_santimeter) {
    // Arrange
    vector<string> args = { "5.0", "santimeter", "1" };
    // Act
    Act(args);
    // Assert
    Assert("Santimeter-meter converter: 0.05");
}

TEST_F(LengthCalculatorTest, meter_to_santimeter_minus) {
    // Arrange
    vector<string> args = { "-5.0", "santimeter", "1" };
    // Act
    Act(args);
    // Assert
    Assert("Santimeter-meter converter: -1");
}

TEST_F(LengthCalculatorTest, mile_to_meter) {
    // Arrange
    vector<string> args = { "5.0", "mile", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Mile-meter converter: 0.00310685");
}

TEST_F(LengthCalculatorTest, meter_to_mile) {
    // Arrange
    vector<string> args = { "5.0", "mile", "1" };
    // Act
    Act(args);
    // Assert
    Assert("Mile-meter converter: 8046.72");
}

TEST_F(LengthCalculatorTest, meter_to_mile_minus) {
    // Arrange
    vector<string> args = { "-5.0", "mile", "1" };
    // Act
    Act(args);
    // Assert
    Assert("Mile-meter converter: -1");
}

TEST_F(LengthCalculatorTest, yard_to_meter) {
    // Arrange
    vector<string> args = { "5.0", "yard", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Yard-meter converter: 5.46805");
}

TEST_F(LengthCalculatorTest, meter_to_yard) {
    // Arrange
    vector<string> args = { "5.0", "yard", "1" };
    // Act
    Act(args);
    // Assert
    Assert("Yard-meter converter: 4.57201");
}

TEST_F(LengthCalculatorTest, meter_to_yard_minus) {
    // Arrange
    vector<string> args = { "-5.0", "yard", "1" };
    // Act
    Act(args);
    // Assert
    Assert("Yard-meter converter: -1");
}

TEST_F(LengthCalculatorTest, ft_to_meter) {
    // Arrange
    vector<string> args = { "5.0", "ft", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Ft-meter converter: 16.4042");
}

TEST_F(LengthCalculatorTest, meter_to_ft) {
    // Arrange
    vector<string> args = { "5.0", "ft", "1" };
    // Act
    Act(args);
    // Assert
    Assert("Ft-meter converter: 1.524");
}

TEST_F(LengthCalculatorTest, meter_to_ft_minus_minus) {
    // Arrange
    vector<string> args = { "-5.0", "ft", "1" };
    // Act
    Act(args);
    // Assert
    Assert("Ft-meter converter: -1");
}

TEST_F(LengthCalculatorTest, inch_to_meter) {
    // Arrange
    vector<string> args = { "5.0", "inch", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Inch-meter converter: 196.851");
}

TEST_F(LengthCalculatorTest, meter_to_inch) {
    // Arrange
    vector<string> args = { "5.0", "inch", "1" };
    // Act
    Act(args);
    // Assert
    Assert("Inch-meter converter: 0.127");
}

TEST_F(LengthCalculatorTest, meter_to_inch_minus) {
    // Arrange
    vector<string> args = { "-5.0", "inch", "1" };
    // Act
    Act(args);
    // Assert
    Assert("Inch-meter converter: -1");
}
