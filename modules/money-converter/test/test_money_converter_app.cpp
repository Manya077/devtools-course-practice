// Copyright 2020 Sokova Anastasia

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/money_converter_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class MoneyCalculatorTest : public ::testing::Test {
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
    MoneyCalculator app_;
    string output_;
};

TEST_F(MoneyCalculatorTest, Can_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};
    // Act
    Act(args);
    // Assert
    Assert("This is a money calculator application\\..*");
}

TEST_F(MoneyCalculatorTest, Can_Check_Number_Of_Arguments) {
    // Arrange
    vector<string> args = { "273.0" };
    // Act
    Act(args);
    // Assert
    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(MoneyCalculatorTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    vector<string> args = { "ten", "usd", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Wrong number format!.*");
}

TEST_F(MoneyCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    // Arrange
    vector<string> args = { "10.0", "Operation", "0" };
    // Act
    Act(args);
    // Assert
    Assert("Wrong operation format!");
}

TEST_F(MoneyCalculatorTest, rub_to_usd_zero) {
    // Arrange
    vector<string> args = { "0.0", "usd", "0" };
    // Act
    Act(args);
    // Assert
    Assert("usd-rub converter: 0");
}

TEST_F(MoneyCalculatorTest, rub_to_usd) {
    // Arrange
    vector<string> args = { "50.0", "usd", "0" };
    // Act
    Act(args);
    // Assert
    Assert("usd-rub converter: 0.643");
}

TEST_F(MoneyCalculatorTest, usd_to_rub) {
    // Arrange
    vector<string> args = { "15.0", "usd", "1" };
    // Act
    Act(args);
    // Assert
    Assert("usd-rub converter: 1165.95");
}

TEST_F(MoneyCalculatorTest, usd_to_rub_minus) {
    // Arrange
    vector<string> args = { "-5.0", "usd", "0" };
    // Act
    Act(args);
    // Assert
    Assert("usd-rub converter: -1");
}

TEST_F(MoneyCalculatorTest, rub_to_eur) {
    // Arrange
    vector<string> args = { "100.0", "eur", "0" };
    // Act
    Act(args);
    // Assert
    Assert("eur-rub converter: 1.166");
}

TEST_F(MoneyCalculatorTest, eur_to_rub) {
    // Arrange
    vector<string> args = { "5.0", "eur", "1" };
    // Act
    Act(args);
    // Assert
    Assert("eur-rub converter: 428.65");
}

TEST_F(MoneyCalculatorTest, eur_to_rub_minus) {
    // Arrange
    vector<string> args = { "-5.0", "eur", "1" };
    // Act
    Act(args);
    // Assert
    Assert("eur-rub converter: -1");
}

TEST_F(MoneyCalculatorTest, rub_to_jpy) {
    // Arrange
    vector<string> args = { "10.0", "jpy", "0" };
    // Act
    Act(args);
    // Assert
    Assert("jpy-rub converter: 14.49");
}

TEST_F(MoneyCalculatorTest, jpy_to_rub) {
    // Arrange
    vector<string> args = { "200.0", "jpy", "1" };
    // Act
    Act(args);
    // Assert
    Assert("jpy-rub converter: 138");
}

TEST_F(MoneyCalculatorTest, jpy_to_rub_minus) {
    // Arrange
    vector<string> args = { "-5.0", "jpy", "1" };
    // Act
    Act(args);
    // Assert
    Assert("jpy-rub converter: -1");
}

TEST_F(MoneyCalculatorTest, rub_to_sek) {
    // Arrange
    vector<string> args = { "5.0", "sek", "0" };
    // Act
    Act(args);
    // Assert
    Assert("sek-rub converter: 0.67");
}

TEST_F(MoneyCalculatorTest, sek_to_rub) {
    // Arrange
    vector<string> args = { "7.0", "sek", "1" };
    // Act
    Act(args);
    // Assert
    Assert("sek-rub converter: 52.15");
}

TEST_F(MoneyCalculatorTest, sek_to_rub_minus) {
    // Arrange
    vector<string> args = { "-5.0", "sek", "1" };
    // Act
    Act(args);
    // Assert
    Assert("sek-rub converter: -1");
}

TEST_F(MoneyCalculatorTest, rub_to_uah) {
    // Arrange
    vector<string> args = { "60.0", "uah", "0" };
    // Act
    Act(args);
    // Assert
    Assert("uah-rub converter: 21.5054");
}

TEST_F(MoneyCalculatorTest, uah_to_rub) {
    // Arrange
    vector<string> args = { "40.0", "uah", "1" };
    // Act
    Act(args);
    // Assert
    Assert("uah-rub converter: 111.6");
}

TEST_F(MoneyCalculatorTest, uah_to_rub_minus) {
    // Arrange
    vector<string> args = { "-5.0", "uah", "1" };
    // Act
    Act(args);
    // Assert
    Assert("uah-rub converter: -1");
}
