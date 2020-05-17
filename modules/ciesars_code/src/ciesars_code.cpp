// Copyright 2020 Mazur Daniil
#include <string>
#include "include/ciesars_code.h"

std::string CiesarsCode::shift(const std::string& message, const int key) {
  std::string shifted_message(message);
  int usedkey = key;
  if (usedkey < 0)
    usedkey = litCount + usedkey;
  for (unsigned int i = 0; i < shifted_message.size(); i++) {
    if (isalpha(shifted_message[i])) {
      if (isupper(shifted_message[i]))
        shifted_message[i] = (shifted_message[i] - 'A' + usedkey)
        % litCount + 'A';
      else
       shifted_message[i] = (shifted_message[i] - 'a' + usedkey)
       % litCount + 'a';
    }
  }
  return shifted_message;
}

std::string CiesarsCode::encode(const std::string& message, const int key) {
  return shift(message, key % litCount);
}

std::string CiesarsCode::decode(const std::string &message, const int key) {
  return shift(message, (-key) % litCount);
}
