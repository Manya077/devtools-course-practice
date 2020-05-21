// Copyright 2020 Guschin Alexander & Antipin Alexander

#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "../include/radix_sort.h"

TEST(RadixSortTest, Can_Fill_Array) {
  // Arrange
  std::vector<std::int32_t> vec(3, 0);
  std::vector<std::int32_t> old_vec(3, 0);

  // Act
  FillRandom(&vec);

  // Assert
  EXPECT_TRUE(vec != old_vec);
}

TEST(RadixSortTest, Can_Find_Unsorted_Array) {
  // Arrange
  std::vector<std::int32_t> vec = {1, 4, 2};

  // Act
  bool result = IsSorted(vec);

  // Assert
  EXPECT_FALSE(result);
}

TEST(RadixSortTest, Can_Find_Sorted_Array) {
  // Arrange
  std::vector<std::int32_t> vec = {1, 2, 4};

  // Act
  bool result = IsSorted(vec);

  // Assert
  EXPECT_TRUE(result);
}

TEST(RadixSortTest, Can_Sort_Sorted_Array) {
  // Arrange
  std::vector<std::int32_t> vec = {1, 2, 4};
  std::vector<std::int32_t> expected_vec = {1, 2, 4};

  // Act
  RadixSort(&vec);

  // Assert
  EXPECT_EQ(expected_vec, vec);
}

TEST(RadixSortTest, Can_Sort_Unsorted_Array) {
  // Arrange
  std::vector<std::int32_t> vec = {1, 2, 4};
  std::vector<std::int32_t> expected_vec = {1, 2, 4};

  // Act
  RadixSort(&vec);

  // Assert
  EXPECT_EQ(expected_vec, vec);
}

TEST(RadixSortTest, Can_Sort_Unsorted_Array_With_Negative_Numbers) {
  // Arrange
  std::vector<std::int32_t> vec = {
      -32, 332, 1 << 28, -8, 1 << 26, -(1 << 26), -24, -(1 << 27), 1111};
  std::vector<std::int32_t> expected_vec = {
      -(1 << 27), -(1 << 26), -32, -24, -8, 332, 1111, 1 << 26, 1 << 28};

  // Act
  RadixSort(&vec);

  // Assert
  EXPECT_EQ(expected_vec, vec);
}

TEST(RadixSortTest, Can_Sort_Unsorted_Array_With_Random_Numbers) {
  // Arrange
  std::vector<std::int32_t> vec(100, 0);
  FillRandom(&vec);

  // Act
  RadixSort(&vec);
  bool result = IsSorted(vec);

  // Assert
  EXPECT_TRUE(result);
}

TEST(SortArrayTEST, Can_Create_Default_SortArray_Class_Without_Throws) {
    // Arrange & Assert
    ASSERT_NO_THROW(SortArray());
}

TEST(SortArrayTEST, Can_Create_Default_SortArray_Correct) {
    // Arrange
    SortArray array;
    size_t res = 0;

    // Act & Assert
    EXPECT_EQ(res, array.size());
}

TEST(SortArrayTEST, Can_Create_SortArray_With_Some_Size_Without_Throws) {
    // Arrange & Assert
    ASSERT_NO_THROW(SortArray(5));
}

TEST(SortArrayTEST, Can_Create_SortArray_With_Some_Size_Correct) {
    // Arrange
    SortArray array(5);
    size_t res = 5;

    // Act & Assert
    EXPECT_EQ(res, array.size());
}

TEST(SortArrayTEST, Can_Create_Copy_Of_SortArray_Without_Throws) {
    // Arrange
    SortArray a(5);

    // Assert
    ASSERT_NO_THROW(SortArray(a));
}

TEST(SortArrayTEST, Can_Create_Copy_Of_SortArray_Correct_1) {
    // Arrange
    SortArray array(5);
    SortArray copy(array);
    size_t res = 5;

    // Act & Assert
    EXPECT_EQ(res, copy.size());
}

TEST(SortArrayTEST, Can_Create_Copy_Of_SortArray_Correct_2) {
    // Arrange
    SortArray array(5);
    SortArray copy(array);
    int32_t res = 0;

    // Assert
    EXPECT_EQ(res, copy[0]);
    EXPECT_EQ(res, copy[2]);
}

TEST(SortArrayTEST, Can_Create_SortArray_From_Vector_Without_Throws) {
    // Arrange
    std::vector<int32_t> vec = { 3, 10, -5, 1 };

    // Assert
    ASSERT_NO_THROW(SortArray(vec));
}

TEST(SortArrayTEST, Can_Create_SortArray_From_Vector_Correct_1) {
    // Arrange
    std::vector<int32_t> vec = { 3, 10, -5, 1 };
    SortArray a(vec);
    size_t res = 4;

    // Act & Assert
    EXPECT_EQ(res, a.size());
}

TEST(SortArrayTEST, Can_Create_SortArray_From_Vector_Correct_2) {
    // Arrange
    std::vector<int32_t> vec = { 3, 10, -5, 1 };
    SortArray a(vec);
    int32_t res1 = 1, res2 = 10;

    // Assert
    EXPECT_EQ(res1, a[1]);
    EXPECT_EQ(res2, a[3]);
}

TEST(SortArrayTEST, Can_Push_Element_In_SortArray_Without_Throws) {
    // Arrange
    std::vector<int32_t> vec = { 3, 10, -5, 1 };
    SortArray array(vec);

    // Act & Assert
    ASSERT_NO_THROW(array.push(2));
}

TEST(SortArrayTEST, Can_Push_Element_In_SortArray_Without_Throws_2) {
    // Arrange
    SortArray array(4);

    // Act & Assert
    ASSERT_NO_THROW(array.push(2));
}

TEST(SortArrayTEST, Can_Push_Element_In_SortArray_Correct) {
    // Arrange
    std::vector<int32_t> vec = { 3, 10, -5, 1 };
    SortArray a(vec);
    int32_t res = 2;

    // Act
    a.push(2);

    // Assert
    EXPECT_EQ(res, a[2]);
}

TEST(SortArrayTEST, Can_Resize_SortArray_Without_Throws) {
    // Arrange
    SortArray array({ 3, 10, 2, 12, -3, -5, 1 });

    // Act & Assert
    ASSERT_NO_THROW(array.resize(4));
}

TEST(SortArrayTEST, Can_Resize_SortArray_Correct) {
    // Arrange
    SortArray array({ 3, 10, 2, 12, -3, -5, 1 });
    int32_t res = 4;

    // Act
    array.resize(4);

    // Assert
    EXPECT_EQ(res, array.size());
}

TEST(SortArrayTEST, Can_Push_Vector_In_SortArray_Without_Throws) {
    // Arrange
    SortArray a({ 3, 10, -5, 1 });

    // Act & Assert
    ASSERT_NO_THROW(a.pushVector({ 2, -1, 4 }));
}

TEST(SortArrayTEST, Can_Push_Vector_In_SortArray_Correct_1) {
    // Arrange
    SortArray a({ 3, 10, -5, 1 });
    int32_t res = 7;

    // Act
    a.pushVector({ 2, -1, 4 });

    // Assert
    EXPECT_EQ(res, a.size());
}

TEST(SortArrayTEST, Can_Push_Vector_In_SortArray_Correct_2) {
    // Arrange
    SortArray a({ 3, 10, -5, 1 });
    int32_t res1 = -1, index1 = 1;
    int32_t res2 = 4, index2 = 5;

    // Act
    a.pushVector({ 2, -1, 4, 15, 20});

    // Assert
    EXPECT_EQ(res1, a[index1]);
    EXPECT_EQ(res2, a[index2]);
}

TEST(SortArrayTEST, Can_Change_Element_In_SortArray_Without_Throws) {
    // Arrange
    SortArray a({ 3, 10, -5, 1, 7 });

    // Act & Assert
    ASSERT_NO_THROW(a.changeElement(2, 15));
}

TEST(SortArrayTEST, Can_Change_Element_In_SortArray_Correct_1) {
    // Arrange
    SortArray a({ 3, 10, -5, 1, 7 });
    int32_t res = 15, index = 4;

    // Act
    a.changeElement(1, res);

    // Assert
    EXPECT_EQ(res, a[index]);
}

TEST(SortArrayTEST, Can_Change_Element_In_SortArray_Correct_2) {
    // Arrange
    SortArray a({ 3, 10, -5, 1, 7 });
    int32_t res = -10, index = 0;

    // Act
    a.changeElement(3, res);

    // Assert
    EXPECT_EQ(res, a[index]);
}

TEST(SortArrayTEST, Can_Change_Element_In_SortArray_Correct_3) {
    // Arrange
    SortArray a({ 3, 10, -5, 1, 7 });
    int32_t res = 4, index = 2;

    // Act
    a.changeElement(index, res);

    // Assert
    EXPECT_EQ(res, a[index]);
}

TEST(SortArrayTEST, Can_Remove_Element_In_SortArray_Without_Throws) {
    // Arrange
    SortArray a({ 3, 10, -5, 1, 7 });

    // Act & Assert
    a.remove(2);
}

TEST(SortArrayTEST, Can_Remove_Element_In_SortArray_Correct_1) {
    // Arrange
    SortArray a({ 3, 10, -5, 1, 7 });
    int32_t res = 7, index = 2;

    // Act
    a.remove(index);

    // Assert
    EXPECT_EQ(res, a[index]);
}

TEST(SortArrayTEST, Can_Remove_Element_In_SortArray_Correct_2) {
    // Arrange
    SortArray a({ 3, 10, -5, 1, 7 });
    int32_t res = 1, index = 0;

    // Act
    a.remove(index);

    // Assert
    EXPECT_EQ(res, a[index]);
}

TEST(SortArrayTEST, Can_Search_In_SortArray_Without_Throws) {
    // Arrange
    SortArray a({ 3, 10, 2, 12, -3, -5, 1 });

    // Act & Assert
    ASSERT_NO_THROW(a.search(1));
}

TEST(SortArrayTEST, Can_Search_Element_In_SortArray_Correct_1) {
    // Arrange
    SortArray a({ 3, 10, 2, 12, -3, -5, 1 });
    int32_t res1 = 6, elem = 12, res2;

    // Act
    res2 = a.search(elem);

    // Assert
    EXPECT_EQ(res1, res2);
}

TEST(SortArrayTEST, Can_Search_Element_In_SortArray_Correct_2) {
    // Arrange
    SortArray a({ 3, 10, 2, 12, -3, -5, 1 });
    int32_t res1 = 0, elem = -5, res2;

    // Act
    res2 = a.search(elem);

    // Assert
    EXPECT_EQ(res1, res2);
}

TEST(SortArrayTEST, Can_Search_Element_In_SortArray_Correct_3) {
    // Arrange
    SortArray a({ 3, 10, 2, 12, -3, -5, 1 });
    int32_t res1 = -1, elem = 16, res2;

    // Act
    res2 = a.search(elem);

    // Assert
    EXPECT_EQ(res1, res2);
}

TEST(SortArrayTEST, Can_Return_False_If_SortArray_Not_Empty) {
    // Arrange
    SortArray a({ 3, 10, 2, 12, -3, -5, 1 });

    // Act & Assert
    EXPECT_FALSE(a.isEmpty());
}

TEST(SortArrayTEST, Can_Return_True_If_SortArray_Empty) {
    // Arrange
    SortArray a;

    // Act & Assert
    EXPECT_TRUE(a.isEmpty());
}

TEST(SortArrayTEST, Can_Sort_Some_Array) {
    // Arrange
    SortArray a;
    std::vector<int32_t> vec = { 3, 10, 2, 12, -3, -5, 1 };

    // Assert
    ASSERT_NO_THROW(a(&vec));
}
