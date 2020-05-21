// Copyright 2020 Mazur Daniil
#include <gtest/gtest.h>
#include <string>
#include "include/ciesars_code.h"

// Arrange
class CiesarsCodeTest : public ::testing::Test {
 public:
    const int zero_key = 0;
    const int positive_key = 11;
    const int negative_key = -13;
    const int big_key = 37;
    const std::string empty_message = "";
    const std::string message = "Compatibility";
    const std::string message_positive_encode = "Nzxaletmtwtej";
    const std::string message_negative_encode = "Pbzcngvovyvgl";
    const std::string complex_message = "Development 2020_C++";
    const std::string complex_message_positive_encode = "Opgpwzaxpye 2020_N++";
    const std::string complex_message_negative_encode = "Qrirybczrag 2020_P++";
};

TEST_F(CiesarsCodeTest, Empty_Message_Encoder_With_Zero_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::encode(empty_message, zero_key));
  EXPECT_EQ(empty_message, CiesarsCode::encode(empty_message, zero_key));
}

TEST_F(CiesarsCodeTest,
  Empty_Message_Encoder_With_Positive_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::encode(empty_message, positive_key));
  EXPECT_EQ(empty_message,
    CiesarsCode::encode(empty_message, positive_key));
}

TEST_F(CiesarsCodeTest,
  Empty_Message_Encoder_With_Negative_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::encode(empty_message, negative_key));
  EXPECT_EQ(empty_message,
    CiesarsCode::encode(empty_message, negative_key));
}

TEST_F(CiesarsCodeTest, Message_Encoder_With_Zero_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::encode(message, zero_key));
  EXPECT_EQ(message, CiesarsCode::encode(message, zero_key));
}

TEST_F(CiesarsCodeTest,
  Message_Encoder_With_Positive_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::encode(message, positive_key));
  EXPECT_EQ(message_positive_encode,
    CiesarsCode::encode(message, positive_key));
}

TEST_F(CiesarsCodeTest,
  Message_Encoder_With_Negative_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::encode(message, negative_key));
  EXPECT_EQ(message_negative_encode,
    CiesarsCode::encode(message, negative_key));
}

TEST_F(CiesarsCodeTest,
  Complex_Message_Encoder_With_Zero_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::encode(complex_message, zero_key));
  EXPECT_EQ(complex_message,
    CiesarsCode::encode(complex_message, zero_key));
}

TEST_F(CiesarsCodeTest,
  Complex_Message_Encoder_With_Positive_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::encode(complex_message, positive_key));
  EXPECT_EQ(complex_message_positive_encode,
    CiesarsCode::encode(complex_message, positive_key));
}

TEST_F(CiesarsCodeTest,
  Complex_Message_Encoder_With_Negative_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::encode(complex_message, negative_key));
  EXPECT_EQ(complex_message_negative_encode,
    CiesarsCode::encode(complex_message, negative_key));
}

TEST_F(CiesarsCodeTest,
  Empty_Message_Decoder_With_Zero_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::decode(empty_message, zero_key));
  EXPECT_EQ(empty_message,
    CiesarsCode::decode(empty_message, zero_key));
}

TEST_F(CiesarsCodeTest,
  Empty_Message_Decoder_With_Positive_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::decode(empty_message, positive_key));
  EXPECT_EQ(empty_message,
    CiesarsCode::decode(empty_message, positive_key));
}

TEST_F(CiesarsCodeTest,
  Empty_Message_Decoder_With_Negative_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::decode(empty_message, negative_key));
  EXPECT_EQ(empty_message,
    CiesarsCode::decode(empty_message, negative_key));
}

TEST_F(CiesarsCodeTest, Message_Decoder_With_Zero_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::decode(message, zero_key));
  EXPECT_EQ(message, CiesarsCode::decode(message, zero_key));
}

TEST_F(CiesarsCodeTest,
  Message_Decoder_With_Positive_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::decode(message, positive_key));
  EXPECT_EQ(message,
    CiesarsCode::decode(message_positive_encode, positive_key));
}

TEST_F(CiesarsCodeTest,
  Message_Decoder_With_Negative_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::decode(message, negative_key));
  EXPECT_EQ(message,
    CiesarsCode::decode(message_negative_encode, negative_key));
}

TEST_F(CiesarsCodeTest,
  Complex_Message_Decoder_With_Zero_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::decode(complex_message, zero_key));
  EXPECT_EQ(complex_message,
    CiesarsCode::decode(complex_message, zero_key));
}

TEST_F(CiesarsCodeTest,
  Complex_Message_Decoder_With_Positive_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::decode(complex_message, positive_key));
  EXPECT_EQ(complex_message,
    CiesarsCode::decode(complex_message_positive_encode,
      positive_key));
}

TEST_F(CiesarsCodeTest,
  Complex_Message_Decoder_With_Negative_Key_Is_Correct) {
  // Act & Assert
  EXPECT_NO_THROW(CiesarsCode::decode(complex_message, negative_key));
  EXPECT_EQ(complex_message,
    CiesarsCode::decode(complex_message_negative_encode,
      negative_key));
}

TEST_F(CiesarsCodeTest, Big_Key_Encoder_Is_Correct) {
  // Act & Assert
  EXPECT_EQ(message_positive_encode,
    CiesarsCode::encode(message, big_key));
}

TEST_F(CiesarsCodeTest, Big_Key_Decoder_Is_Correct) {
  // Act & Assert
  EXPECT_EQ(message,
    CiesarsCode::decode(message_positive_encode, big_key));
}
