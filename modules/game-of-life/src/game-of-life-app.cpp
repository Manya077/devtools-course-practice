// Copyright 2020 Kriukov Dmitry

#include "include/game-of-life-app.h"

#include <string>
#include <sstream>
#include <exception>

GameOfLifeApp::GameOfLifeApp(): message_("") {}

void GameOfLifeApp::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <grid height> <grid wight> " +
    "<cell 1> ... <cell height * wight> <turns count>\n\n" +

    "A dead cell is written as '.'" +
    "A live cell is written as '*'\n" +
    "Example: \n" + "3 2 . * . * . * 3";
}

bool GameOfLifeApp::validateArguments(int size, int argc, const char** argv) {
  if (argc != size + 4) {
    message_ += "ERROR: You need to fill in the grid completely\n";
    message_ += "and enter the number of steps\n";
    return false;
  }
  return true;
}

std::string GameOfLifeApp::operator()(int argc, const char** argv) {
  GameOfLifeGrid mainGrid;
  int width, hight, steps;

  if (argc == 1) {
    help(argv[0], "This is a game of life application.\n\n");
    return message_;
  }
  if (argc < 3) {
    return std::string("Enter width and hight");
  }

  try {
    width = std::stoi(argv[1]);
    hight = std::stoi(argv[2]);
  } catch (std::exception&) {
    return std::string("Invalid grid size!");
  }

  mainGrid = GameOfLifeGrid(width, hight);
  if (!validateArguments(width * hight, argc, argv)) {
    return message_;
  }

  for (int j = 0; j < hight; ++j)
    for (int i = 0; i < width; ++i) {
      const char arg = *argv[i + j * width + 3];
      if ((arg == '.') || (arg == '*')) {
        mainGrid.SetCell(i, j, arg);
      } else {
        message_ += "Wrong grid elements format:\n";
        message_ += "A dead cell is written as '.'\n";
        message_ += "A live cell is written as '*'\n";
        return message_;
      }
  }

  try {
    steps = std::stoi(argv[3 + hight * width]);
  } catch (std::exception&) {
    return std::string("Invalid steps count!");
  }

  for (int i = 0; i < steps; ++i)
    mainGrid = mainGrid.NextGrid();

  std::ostringstream stream;
  for (uint32_t j = 0; j < mainGrid.GetHeight(); ++j) {
    for (uint32_t i = 0; i < mainGrid.GetWight(); ++i)
      stream << mainGrid.GetCell(i, j);
    stream << std::endl;
  }

  message_ = stream.str();

  return message_;
}
