// Copyright 2020 Kriukov Dmitry

#ifndef MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_APP_H_
#define MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_APP_H_

#include "include/game-of-life.h"

#include <string>

class GameOfLifeApp {
 public:
  GameOfLifeApp();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateArguments(int size, int argc, const char** argv);
  std::string message_;
};

#endif  // MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_APP_H_
