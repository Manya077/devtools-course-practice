// Copyright 2020 Kriukov Dmitry

#include <gtest/gtest.h>

#include <string>

#include "include/game-of-life.h"


TEST(GameOfLifeTest, Can_Create_Default_Grid) {
  // Arrange & Act & Assert
  EXPECT_NO_THROW(GameOfLifeGrid());
}

TEST(GameOfLifeTest, Can_Create_With_Input) {
  // Arrange
  unsigned char input[] = { deadCell, aliveCell,
    deadCell, aliveCell, deadCell, deadCell };

  // Act & Assert
  EXPECT_NO_THROW(GameOfLifeGrid(2, 3, input));
}

TEST(GameOfLifeTest, Can_Create_With_Parameters) {
  // Arrange
  uint32_t w = 2;
  uint32_t h = 4;

  // Act
  GameOfLifeGrid res(w, h);

  // Assert
  EXPECT_EQ(w, res.GetWight());
  EXPECT_EQ(h, res.GetHeight());
  }

TEST(GameOfLifeTest, Copy_Constructor_Test) {
  // Arrange
  uint32_t w = 2;
  uint32_t h = 3;
  unsigned char input1[] = { deadCell, aliveCell, deadCell,
    aliveCell, deadCell, deadCell };
  GameOfLifeGrid expected(w, h, input1);
  // Act
  GameOfLifeGrid actual(expected);

  // Assert
  EXPECT_EQ(expected, actual);
}

TEST(GameOfLifeTest, Equality_operator_test) {
  // Arrange
  uint32_t w = 2;
  uint32_t h = 3;
  unsigned char input[] = { deadCell, aliveCell,
    deadCell, aliveCell, deadCell, deadCell };
  GameOfLifeGrid a(w, h, input);
  GameOfLifeGrid b(w, h, input);

  // Act & Assert
  EXPECT_TRUE(a == b);
}

TEST(GameOfLifeTest, Equality_operator_test_zero_size) {
  // Arrange
  uint32_t w = 0;
  uint32_t h = 0;
  GameOfLifeGrid a(w, h);
  GameOfLifeGrid b(w, h);

  // Act & Assert
  EXPECT_TRUE(a == b);
}

TEST(GameOfLifeTest, Equality_operator_test_different_size) {
  // Arrange
  uint32_t w = 2;
  uint32_t h = 3;
  GameOfLifeGrid a(w, h);
  GameOfLifeGrid b(w + 1, h);

  // Act & Assert
  EXPECT_FALSE(a == b);
}

TEST(GameOfLifeTest, Unequality_operator_test) {
  // Arrange
  uint32_t w = 2;
  uint32_t h = 3;
  unsigned char input1[] = { deadCell, aliveCell, deadCell,
    aliveCell, deadCell, deadCell };
  unsigned char input2[] = { deadCell, aliveCell, deadCell,
    aliveCell, aliveCell, deadCell };
  GameOfLifeGrid a(w, h, input1);
  GameOfLifeGrid b(w, h, input2);

  // Act & Assert
  EXPECT_TRUE(a != b);
}

TEST(GameOfLifeTest, Test_Count_Neigbors_0_Neigbors) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  const uchar expect = 0;
  unsigned char input[] = { deadCell, deadCell, deadCell, deadCell,
    aliveCell, deadCell , deadCell, deadCell, deadCell };
  GameOfLifeGrid grid(w, h, input);

  // Act & Assert
  EXPECT_EQ(expect, grid.NeighborCount(1, 1));
}

TEST(GameOfLifeTest, Test_Count_Neigbors_4_Neigbors) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  const uchar expect = 4;
  unsigned char input[] = { deadCell, aliveCell, deadCell, aliveCell,
    aliveCell, aliveCell , deadCell, aliveCell, deadCell };
  GameOfLifeGrid grid(w, h, input);

  // Act & Assert
  EXPECT_EQ(expect, grid.NeighborCount(1, 1));
}

TEST(GameOfLifeTest, Test_Count_Neigbors_2_Neigbors) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  const uchar expect = 2;
  unsigned char input[] = { deadCell, deadCell, deadCell, aliveCell,
    aliveCell, aliveCell , deadCell, deadCell, deadCell };
  GameOfLifeGrid grid(w, h, input);

  // Act & Assert
  EXPECT_EQ(expect, grid.NeighborCount(1, 1));
}

TEST(GameOfLifeTest, Alive_Check_Test_0_Neigbors) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  unsigned char input[] = { deadCell, deadCell, deadCell,
    deadCell, aliveCell, deadCell , deadCell, deadCell, deadCell};
  GameOfLifeGrid grid(w, h, input);

  // Act & Assert
  EXPECT_EQ(deadCell, grid.NextCondition(1, 1));
}

TEST(GameOfLifeTest, Alive_Check_Test_4_Neigbors) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  unsigned char input[] = { deadCell, aliveCell, deadCell,
    aliveCell, aliveCell, aliveCell , deadCell, aliveCell, deadCell };
  GameOfLifeGrid grid(w, h, input);

  // Act & Assert
  EXPECT_EQ(deadCell, grid.NextCondition(1, 1));
}

TEST(GameOfLifeTest, Alive_Check_Test_2_Neigbors) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  unsigned char input[] = { deadCell, deadCell, deadCell, aliveCell,
    aliveCell, aliveCell , deadCell, deadCell, deadCell };
  GameOfLifeGrid grid(w, h, input);

  // Act & Assert
  EXPECT_EQ(aliveCell, grid.NextCondition(1, 1));
}

TEST(GameOfLifeTest, Alive_Check_Test_3_Neigbors_Dead_Cell) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  unsigned char input[] = { deadCell, aliveCell, deadCell, aliveCell,
    deadCell, aliveCell , deadCell, deadCell, deadCell };
  GameOfLifeGrid grid(w, h, input);
  // Act & Assert
  EXPECT_EQ(aliveCell, grid.NextCondition(1, 1));
}

TEST(GameOfLifeTest, Test_Get_Cell) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  unsigned char input[] = { deadCell, aliveCell, deadCell,
    aliveCell, deadCell, aliveCell , deadCell, deadCell, deadCell };
  GameOfLifeGrid grid(w, h, input);
  // Act & Assert
  EXPECT_EQ(deadCell, grid.GetCell(1, 1));
}

TEST(GameOfLifeTest, Test_Throw_Get_Index_Out_Of_Grid) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  unsigned char input[] = { deadCell, aliveCell,
    deadCell, aliveCell, deadCell,
    aliveCell , deadCell, deadCell, deadCell };
  GameOfLifeGrid grid(w, h, input);
  // Act & Assert
  EXPECT_ANY_THROW(grid.GetCell(-1, -1));
}

TEST(GameOfLifeTest, Test_Set_Cell) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  GameOfLifeGrid grid(w, h);
  // Act
  grid.SetCell(1, 1, aliveCell);
  // Assert
  EXPECT_EQ(aliveCell, grid.GetCell(1, 1));
}

TEST(GameOfLifeTest, Test_Throw_Set_Index_Out_Of_Grid) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  GameOfLifeGrid grid(w, h);
  // Act & Assert
  EXPECT_ANY_THROW(grid.SetCell(-1, -1, aliveCell));
}

TEST(GameOfLifeTest, Test_Grid_Assignment_same_size) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  unsigned char input[] = { deadCell, aliveCell, deadCell,
    aliveCell, deadCell, aliveCell, deadCell,
    deadCell, deadCell };
  GameOfLifeGrid expect(w, h, input);
  GameOfLifeGrid actual(w, h);
  // Act
  actual = expect;
  // Assert
  EXPECT_EQ(expect, actual);
}

TEST(GameOfLifeTest, Test_Grid_Assignment_different_size) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  unsigned char input[] = { deadCell, aliveCell, deadCell,
    aliveCell, deadCell, aliveCell , deadCell, deadCell,
    deadCell };
  GameOfLifeGrid expect(w, h, input);
  GameOfLifeGrid actual(w - 1, h - 1);
  // Act
  actual = expect;
  // Assert
  EXPECT_EQ(expect, actual);
}

TEST(GameOfLifeTest, Test_Grid_Assignment_zero_size) {
  // Arrange
  uint32_t w = 3;
  uint32_t h = 3;
  GameOfLifeGrid expect(0, 0);
  GameOfLifeGrid actual(w, h);
  // Act
  actual = expect;
  // Assert
  EXPECT_EQ(expect, actual);
}

TEST(GameOfLifeTest, Test_Get_Next_Grid) {
  // Arrange
  uint32_t w = 8;
  uint32_t h = 4;
  unsigned char input[] = { deadCell, deadCell, deadCell,
    deadCell, deadCell, deadCell, deadCell, deadCell, deadCell,
    deadCell, deadCell, deadCell, aliveCell, deadCell,
    deadCell, deadCell, deadCell, deadCell, deadCell,
    aliveCell, aliveCell, deadCell, deadCell, deadCell,
    deadCell, deadCell, deadCell, deadCell,
    deadCell, deadCell, deadCell, deadCell };
  unsigned char expect_input[] = { deadCell, deadCell,
    deadCell, deadCell, deadCell, deadCell, deadCell,
    deadCell, deadCell, deadCell, deadCell, aliveCell, aliveCell,
    deadCell, deadCell, deadCell, deadCell, deadCell, deadCell,
    aliveCell,  aliveCell, deadCell, deadCell, deadCell,
    deadCell, deadCell, deadCell, deadCell, deadCell, deadCell,
    deadCell, deadCell };
  GameOfLifeGrid grid(w, h, input);
  GameOfLifeGrid expect(w, h, expect_input);
  // Act & Assert
  EXPECT_EQ(expect, grid.NextGrid());
}
