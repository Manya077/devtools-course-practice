// Copyright 2020 Mazur Daniil

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/ciesars_code_application.h"

class CiesarsCodeApplicationTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> parameters;
    parameters.push_back("ciesars-code.exe");
    for (size_t i = 0; i < args_.size(); ++i) {
      parameters.push_back(args_[i].c_str());
    }
    const char** argv = &parameters.front();
    int argc = static_cast<int>(args_.size()) + 1;
    output_ = app_(argc, argv);
  }
  void Assert(std::string expected) { EXPECT_EQ(expected, output_); }

 private:
  CiesarsCodeApplication app_;
  std::string output_;
};

TEST_F(CiesarsCodeApplicationTest, Can_Print_Help_Without_Arguments) {
  // Arrange
  std::vector<std::string> args = {};

  Act(args);

  Assert(
    "\nInvalid count of params."
    "\nThis application encodes/decodes the contents of the file.\n"
    "Please provide arguments in the following format:\n"
    "1: File name(string) for operation;\n"
    "2: File name(string) to save the result;\n"
    "3: The key(int) to encode/decode operations;\n"
    "4: The operation(string): EN to encode or DE to decode;\n");
}

TEST_F(CiesarsCodeApplicationTest, Throws_On_Invalid_FileName) {
  // Arrange
  std::vector<std::string> args = { "InvalidName", "SaveFile", "4", "EN" };

  Act(args);

  Assert(
    "\nCan't open input file."
    "\nCan't open output file."
    "\nThis application encodes/decodes the contents of the file.\n"
    "Please provide arguments in the following format:\n"
    "1: File name(string) for operation;\n"
    "2: File name(string) to save the result;\n"
    "3: The key(int) to encode/decode operations;\n"
    "4: The operation(string): EN to encode or DE to decode;\n");
}

TEST_F(CiesarsCodeApplicationTest, Throws_On_Invalid_Operation) {
  // Arrange
  std::vector<std::string> args = { "Encrypt.txt", "Decrypt.txt", "4",
                                    "InvalidOperation" };

  Act(args);

  Assert(
    "\nInvalid Operator."
    "\nThis application encodes/decodes the contents of the file.\n"
    "Please provide arguments in the following format:\n"
    "1: File name(string) for operation;\n"
    "2: File name(string) to save the result;\n"
    "3: The key(int) to encode/decode operations;\n"
    "4: The operation(string): EN to encode or DE to decode;\n");
}

TEST_F(CiesarsCodeApplicationTest, Can_Encode_File) {
  // Arrange
  std::vector<std::string> args = { "Encrypt.txt", "Decrypt.txt", "4", "EN" };

  Act(args);

  Assert(
    "M orsa xlex xli wtehiw evi xli wasvhw sj e wsphmiv,\n"
    "M orsa xlex xli gpyfw evi aietsrw sj aev,\n"
    "M orsa xlex hmeqsrhw qier qsric jsv xlmw evx,\n"
    "Fyx xlex'w rsx xli wleti sj qc lievx.\n");
}

TEST_F(CiesarsCodeApplicationTest, Can_Decode_File) {
  // Arrange
  std::vector<std::string> args = { "Decrypt.txt", "Encrypt.txt", "4", "DE" };

  Act(args);

  Assert(
    "I know that the spades are the swords of a soldier,\n"
    "I know that the clubs are weapons of war,\n"
    "I know that diamonds mean money for this art,\n"
    "But that's not the shape of my heart.\n");
}

TEST_F(CiesarsCodeApplicationTest, Can_Encode_File_With_Negative_Key) {
  // Arrange
  std::vector<std::string> args = { "Decrypt.txt", "Encrypt.txt", "-4", "EN" };

  Act(args);

  Assert(
    "I know that the spades are the swords of a soldier,\n"
    "I know that the clubs are weapons of war,\n"
    "I know that diamonds mean money for this art,\n"
    "But that's not the shape of my heart.\n");
}

TEST_F(CiesarsCodeApplicationTest, Can_Encode_File_With_Zero_Key) {
  // Arrange
  std::vector<std::string> args = { "Encrypt.txt", "Encrypt.txt", "0", "EN" };

  Act(args);

  Assert(
    "I know that the spades are the swords of a soldier,\n"
    "I know that the clubs are weapons of war,\n"
    "I know that diamonds mean money for this art,\n"
    "But that's not the shape of my heart.\n");
}

TEST_F(CiesarsCodeApplicationTest, Can_Decode_File_With_Zero_Key) {
  // Arrange
  std::vector<std::string> args = { "Decrypt.txt", "Decrypt.txt", "0", "DE" };

  Act(args);

  Assert(
    "M orsa xlex xli wtehiw evi xli wasvhw sj e wsphmiv,\n"
    "M orsa xlex xli gpyfw evi aietsrw sj aev,\n"
    "M orsa xlex hmeqsrhw qier qsric jsv xlmw evx,\n"
    "Fyx xlex'w rsx xli wleti sj qc lievx.\n");
}
