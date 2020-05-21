// Copyright 2020 Zinkov Artem

#include "include/vigenere_cipher.h"
#include <stdexcept>
#include <string>
#include <vector>

std::string Encrypt_Vigenere_Cipher(const std::string& text,
    const std::string& key) {
    if (key.size() < 1)
        throw std::length_error("key length must be greater than 0");

    std::string result = text;
    int i = 0;
    int difference = 0;

    for (auto& s : result) {
        if (islower(key[i % key.size()]))
            difference = static_cast<int>(key[i++ % key.size()] - 'a');
        else if (isupper(key[i % key.size()]))
                difference = static_cast<int>(key[i++ % key.size()] - 'A');
        if (islower(s))
            s = ((static_cast<int>(s - 'a') + difference) % 26) + 'a';
        else if (isupper(s))
                s = ((static_cast<int>(s - 'A') + difference) % 26) + 'A';
    }
    return result;
}

std::string Decrypt_Vigenere_Cipher(const std::string& text,
    const std::string& key) {
    if (key.size() < 1)
        throw std::length_error("key length must be greater than 0");

    std::string result = text;
    int i = 0;
    int difference = 0;

    for (auto& s : result) {
        if (islower(key[i % key.size()]))
            difference = static_cast<int>(key[i++ % key.size()] - 'a');
        else if (isupper(key[i % key.size()]))
                difference = static_cast<int>(key[i++ % key.size()] - 'A');
        if (islower(s))
            s = ((static_cast<int>(s - 'a') + 26 - difference) % 26) + 'a';
        else if (isupper(s))
                s = ((static_cast<int>(s - 'A') + 26 - difference) % 26) + 'A';
    }
    return result;
}
