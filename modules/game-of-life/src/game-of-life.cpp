// Copyright 2020 Kriukov Dmitry

#include "include/game-of-life.h"

#define ISDEAD(arg) (arg & 4)
#define RESULTNORMALIZATION(arg) (arg >> 2)

const uchar aliveCell = '*';
const uchar deadCell = '.';

GameOfLifeGrid::GameOfLifeGrid(uint32_t wight_, uint32_t height_)
                                :wight(wight_), height(height_),
node(reinterpret_cast<uchar*>(operator new(sizeof(uchar) *
  (wight + 2)* (height + 2)))) {
  for (uint32_t i = 0; i < (wight + 2) * (height + 2); ++i) {
    new(node + i) uchar(deadCell);
  }
}

GameOfLifeGrid::GameOfLifeGrid(uint32_t wight_, uint32_t height_,
  uchar* input) :wight(wight_), height(height_),
  node(reinterpret_cast<uchar*>(operator new(sizeof(uchar) *
  (wight + 2)* (height + 2)))) {
  for (uint32_t i = 0; i < wight + 2; ++i)
    new(node + i) uchar(deadCell);
  for (uint32_t i = 1; i < height + 1; ++i) {
    new(node + i * (wight + 2)) uchar(deadCell);
    for (uint32_t j = 1; j < wight + 1; ++j)
      new(node + i * (wight + 2) + j)
        uchar(input[(i - 1) * wight + j - 1]);
    new(node + i * (wight + 2) + wight + 1) uchar(deadCell);
  }
  for (uint32_t i = 0; i < wight + 2; ++i)
    new(node + (wight + 2)*(height + 1) + i) uchar(deadCell);
}

GameOfLifeGrid::GameOfLifeGrid(const GameOfLifeGrid& grid):
  wight(grid.wight), height(grid.height),
  node(reinterpret_cast<uchar*>(operator new(sizeof(uchar)*
  (wight + 2)* (height + 2)))) {
  for (uint32_t i = 0; i < (wight + 2) * (height + 2); ++i)
    new(node + i) uchar(grid.node[i]);
}

uint32_t GameOfLifeGrid::GetWight() {
  return wight;
}

uint32_t GameOfLifeGrid::GetHeight() {
  return height;
}

bool GameOfLifeGrid::operator==(const GameOfLifeGrid& grid) const {
  if (wight != grid.wight || height != grid.height)
    return false;
  if ((wight == 0) || (height == 0))
    return true;
  for (uint32_t i = 0; i < (wight + 2) * (height + 2); ++i)
    if (node[i] != grid.node[i])
      return false;
  return true;
}

bool GameOfLifeGrid::operator!=(const GameOfLifeGrid& grid) {
  return !(*this == grid);
}

GameOfLifeGrid& GameOfLifeGrid::operator=(const GameOfLifeGrid& grid) {
  uint32_t size = grid.wight * grid.height;
  if (size == 0) {
    operator delete (node);
    node = nullptr;
    wight = grid.wight;
    height = grid.height;
    return *this;
  } else if (size != height * wight) {
    operator delete (node);
    node = reinterpret_cast<uchar*>(operator new(sizeof(uchar) *
      (grid.wight + 2) * (grid.height + 2)));
    wight = grid.wight;
    height = grid.height;
  }
  for (uint32_t i = 0; i < (wight + 2) * (height + 2); ++i) {
    node[i] = grid.node[i];
  }
  return *this;
}

uchar GameOfLifeGrid::NeighborCount(uint32_t x, uint32_t y) {
  const uchar cAllNeighborCellCount = 8;
  uchar res = 0;
  res += ISDEAD(node[y * (wight + 2) + x]);
  res += ISDEAD(node[y * (wight + 2) + (x + 1)]);
  res += ISDEAD(node[y * (wight + 2) + (x + 2)]);
  res += ISDEAD(node[(y + 1) * (wight + 2) + x]);
  res += ISDEAD(node[(y + 1) * (wight + 2) + x + 2]);
  res += ISDEAD(node[(y + 2) * (wight + 2) + x]);
  res += ISDEAD(node[(y + 2) * (wight + 2) + (x + 1)]);
  res += ISDEAD(node[(y + 2) * (wight + 2) + (x + 2)]);
  return cAllNeighborCellCount - RESULTNORMALIZATION(res);
}

void GameOfLifeGrid::SetCell(uint32_t x, uint32_t y, uchar cell) {
  if ((x < 0) || (x > wight) || (y < 0) || (y > height))
    throw "index is out of the grid";
  node[(x + 1) + (y + 1) * (wight + 2)] = cell;
}

uchar GameOfLifeGrid::GetCell(uint32_t x, uint32_t y) {
  if ((x < 0) || (x > wight) || (y < 0) || (y > height))
    throw "index is out of the grid";
  return node[(x + 1) + (y + 1) * (wight + 2)];
}

GameOfLifeGrid GameOfLifeGrid::NextGrid() {
  GameOfLifeGrid res(wight, height);
  for (uint32_t i = 0; i < height; ++i) {
    for (uint32_t j = 0; j < wight; ++j)
      res.node[(i + 1) * (wight + 2) + (j + 1)] = NextCondition(j, i);
  }
  return res;
}

uchar GameOfLifeGrid::NextCondition(uint32_t x, uint32_t y) {
  const uchar willLiveAnyway = 3;
  const uchar willLiveOnlyAlive = 2;
  uchar ncount = NeighborCount(x, y);
  if (ncount == willLiveAnyway) {
    return aliveCell;
  } else if (ncount == willLiveOnlyAlive && (!ISDEAD(node[(y + 1) *
    (wight + 2) + x + 1]))) {
    return aliveCell;
  }
  return deadCell;
}

GameOfLifeGrid::~GameOfLifeGrid() {
  operator delete (node);
}
