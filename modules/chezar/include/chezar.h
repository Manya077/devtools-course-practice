// Copyright 2020 Suchkov Makar

#ifndef MODULES_CHEZAR_INCLUDE_CHEZAR_H_
#define MODULES_CHEZAR_INCLUDE_CHEZAR_H_

#include <string>

class Chezar {
 public:
  static std::string Decrypt(std::string str, unsigned int key);
  static std::string Encrypt(std::string str, unsigned int key);
  static const unsigned int max_key_value = 26;
};

#endif  // MODULES_CHEZAR_INCLUDE_CHEZAR_H_
