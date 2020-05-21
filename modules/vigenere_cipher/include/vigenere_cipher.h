// Copyright 2020 Zinkov Artem

#ifndef MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_
#define MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_

#include <string>

std::string Encrypt_Vigenere_Cipher(const std::string& text,
    const std::string& key);
std::string Decrypt_Vigenere_Cipher(const std::string& text,
    const std::string& key);

#endif  // MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_
