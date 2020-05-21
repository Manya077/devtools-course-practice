// Copyright 2020 Kriukov Dmitry

#ifndef MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_H_
#define MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_H_

typedef unsigned char uchar;
extern const unsigned char aliveCell;
extern const unsigned char deadCell;

#include<stdint.h>
#include <new>

class GameOfLifeGrid {
 public:
  GameOfLifeGrid() :wight(0), height(0), node(nullptr) {}
  GameOfLifeGrid(uint32_t wight_, uint32_t height_);
  GameOfLifeGrid(uint32_t wight_, uint32_t height_, uchar* input);
  GameOfLifeGrid(const GameOfLifeGrid& grid);
  ~GameOfLifeGrid();
  uint32_t GetWight();
  uint32_t GetHeight();
  bool operator==(const GameOfLifeGrid& grid) const;
  bool operator!=(const GameOfLifeGrid& grid);
  GameOfLifeGrid& operator=(const GameOfLifeGrid&);
  uchar NextCondition(uint32_t x, uint32_t y);
  uchar NeighborCount(uint32_t x, uint32_t y);
  void SetCell(uint32_t x, uint32_t y, uchar cell);
  uchar GetCell(uint32_t x, uint32_t y);
  GameOfLifeGrid NextGrid();
 protected:
  uint32_t wight;
  uint32_t height;
  uchar* node;
};

#endif  // MODULES_GAME_OF_LIFE_INCLUDE_GAME_OF_LIFE_H_
