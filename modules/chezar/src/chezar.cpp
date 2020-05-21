// Copyright 2020 Suchkov Makar

#include "include/chezar.h"
#include <string>

std::string Chezar::Encrypt(std::string str, unsigned int key) {
    for (unsigned int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] += key;
            if (str[i] > 'z') {
                str[i] = str[i] - 'z' + 'a' - 1;
            }
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += key;
            if (str[i] > 'Z') {
                str[i] = str[i] - 'Z' + 'A' - 1;
            }
        }
    }
    return str;
}

std::string Chezar::Decrypt(std::string str, unsigned int key) {
    for (unsigned int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= key;
            if (str[i] < 'a') {
                str[i] = str[i] + 'z' - 'a' + 1;
            }
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] -= key;
            if (str[i] < 'A') {
                str[i] = str[i] + 'Z' - 'A' + 1;
            }
        }
    }
    return str;
}
