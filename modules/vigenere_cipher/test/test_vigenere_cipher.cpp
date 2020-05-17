// Copyright 2020 Zinkov Artem

#include <gtest/gtest.h>
#include <string>
#include "include/vigenere_cipher.h"

TEST(Vigenere_Cipher_Test, Encryption_With_Zero_Length_Key) {
    // Arrange
    std::string text("skjdfkop");
    std::string key;

    // Assert
    ASSERT_ANY_THROW(Encrypt_Vigenere_Cipher(text, key));
}

TEST(Vigenere_Cipher_Test, Encryption_With_Zero_Length_Text) {
    // Arrange
    std::string text;
    std::string key("abc");

    // Act
    std::string res = Encrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("", res);
}

TEST(Vigenere_Cipher_Test, Encryption_Uppercase_Text) {
    // Arrange
    std::string text("AAAA");
    std::string key("bb");

    // Act
    std::string res = Encrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("BBBB", res);
}

TEST(Vigenere_Cipher_Test, Encryption_Uppercase_Key) {
    // Arrange
    std::string text("kdokfs");
    std::string key("LSLFA");

    // Act
    std::string res = Encrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("vvzpfd", res);
}

TEST(Vigenere_Cipher_Test, Encryption_Uppercase_Key_And_Text) {
    // Arrange
    std::string text("OSKOFOSKFPASD");
    std::string key("LSLFA");

    // Act
    std::string res = Encrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("ZKVTFZKVKPLKO", res);
}

TEST(Vigenere_Cipher_Test, Encryption_With_Different_Registers) {
    // Arrange
    std::string text("skLSFspldfpsLFLDPLF");
    std::string key("sefsaLLFFsaggsd");

    // Act
    std::string res = Encrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("koQKFdaqixpyRXOVTQX", res);
}

TEST(Vigenere_Cipher_Test, Encryption_Text_Shorter_Key) {
    // Arrange
    std::string text("f");
    std::string key("abc");

    // Act
    std::string res = Encrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("f", res);
}

TEST(Vigenere_Cipher_Test, Encryption_Key_Shorter_Text) {
    // Arrange
    std::string text("sdkfasdaslfsl");
    std::string key("abc");

    // Act
    std::string res = Encrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("semfbudbulgul", res);
}

TEST(Vigenere_Cipher_Test, Encryption_Key_A) {
    // Arrange
    std::string text("fsdfsgsdgassd");
    std::string key("aaaa");

    // Act
    std::string res = Encrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ(text, res);
}

TEST(Vigenere_Cipher_Test, Encryption_Key_Lenght_One) {
    // Arrange
    std::string text("fsdfsgsdgassd");
    std::string key("g");

    // Act
    std::string res = Encrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("lyjlymyjmgyyj", res);
}

TEST(Vigenere_Cipher_Test, Decryption_With_Zero_Length_Key) {
    // Arrange
    std::string text("oskokfkssokdf");
    std::string key;

    // Assert
    ASSERT_ANY_THROW(Decrypt_Vigenere_Cipher(text, key));
}

TEST(Vigenere_Cipher_Test, Decryption_With_Zero_Length_Text) {
    // Arrange
    std::string text;
    std::string key("abc");

    // Act
    std::string res = Decrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("", res);
}

TEST(Vigenere_Cipher_Test, Decryption_Uppercase_Text) {
    // Arrange
    std::string text("SKFOD");
    std::string key("fffsg");

    // Act
    std::string res = Decrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("NFAWX", res);
}

TEST(Vigenere_Cipher_Test, Decryption_Uppercase_Key) {
    // Arrange
    std::string text("dfffdss");
    std::string key("PSLDFA");

    // Act
    std::string res = Decrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("onucysd", res);
}

TEST(Vigenere_Cipher_Test, Decryption_Uppercase_Key_And_Text) {
    // Arrange
    std::string text("JSSOFKSFSJDIFJJAJISAFIJSIFJAIJSfiAJISJFA");
    std::string key("SIJFSJDFSF");

    // Act
    std::string res = Decrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("RKJJNBPAAELAWERRGDAVNAANQWGVQEAxzVRZPENV", res);
}

TEST(Vigenere_Cipher_Test, Decryption_With_Different_Registers) {
    // Arrange
    std::string text("JSfsfsdfskdfkSDJFISJDFJjdif");
    std::string key("idfIDS");

    // Act
    std::string res = Decrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("BPakcavcncancPYBCQKGYXGrvfa", res);
}

TEST(Vigenere_Cipher_Test, Decryption_Text_Shorter_Key) {
    // Arrange
    std::string text("f");
    std::string key("abc");

    // Act
    std::string res = Decrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("f", res);
}

TEST(Vigenere_Cipher_Test, Decryption_Key_Shorter_Text) {
    // Arrange
    std::string text("sdkfasdaslfsl");
    std::string key("dogony");

    // Act
    std::string res = Decrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("ppernuammxsui", res);
}

TEST(Vigenere_Cipher_Test, Decryption_Key_A) {
    // Arrange
    std::string text("ksoekfksesd");
    std::string key("aaaa");

    // Act
    std::string res = Decrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ(text, res);
}

TEST(Vigenere_Cipher_Test, Decryption_Key_Lenght_One) {
    // Arrange
    std::string text("sleoasldalfapFLS");
    std::string key("h");

    // Act
    std::string res = Decrypt_Vigenere_Cipher(text, key);

    // Assert
    ASSERT_EQ("lexhtlewteytiYEL", res);
}

TEST(Vigenere_Cipher_Test, Encryption_and_Decryption_Text) {
    // Arrange
    std::string text("skefsejsiejfsefksfsekdjfsdfopakfs");
    std::string key("bbgekaksokdaw");

    // Act
    std::string res = Encrypt_Vigenere_Cipher(text, key);
    res = Decrypt_Vigenere_Cipher(res, key);

    // Assert
    ASSERT_EQ(text, res);
}
