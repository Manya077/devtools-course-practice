// Copyright 2020 Suchkov Makar

#include <gtest/gtest.h>
#include <string>
#include "include/chezar.h"

TEST(Suchkov_Makar_Chezar_Test, Can_Decrypt_Correct_Data_Arguments) {
    // Arrange & Assert
    std::string a("fghijklmnopqrstuvwxyzabcde");
    std::string res(Chezar::Decrypt(a, 5));
    // Act
    EXPECT_EQ("abcdefghijklmnopqrstuvwxyz", res);
}

TEST(Suchkov_Makar_Chezar_Test, Can_Crypt_Correct_Data_Arguments) {
    // Arrange & Assert
    std::string a("abcdefghijklmnopqrstuvwxyz");
    std::string res(Chezar::Encrypt(a, 5));
    // Act
    EXPECT_EQ("fghijklmnopqrstuvwxyzabcde", res);
}

TEST(Suchkov_Makar_Chezar_Test, Can_Decrypt_Correct_Data_Arguments_Upper) {
    // Arrange & Assert
    std::string a("FGHIJKLMNOPQRSTUVWXYZABCDE");
    std::string res(Chezar::Decrypt(a, 5));
    // Act
    EXPECT_EQ("ABCDEFGHIJKLMNOPQRSTUVWXYZ", res);
}

TEST(Suchkov_Makar_Chezar_Test, Can_Crypt_Correct_Data_Arguments_Upper) {
    // Arrange & Assert
    std::string a("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::string res(Chezar::Encrypt(a, 5));
    // Act
    EXPECT_EQ("FGHIJKLMNOPQRSTUVWXYZABCDE", res);
}
