// Copyright 2020 Antipin Alexander & Guschin Alexandr

#include <gtest/gtest.h>
#include <algorithm>
#include "include/d-heap.h"

TEST(Dheap, can_create_default_d_heap) {
    // Arrange Assert
    ASSERT_NO_THROW(d_heap());
}

TEST(Dheap, is_creating_default_d_heap_correct) {
    // Arrange
    d_heap a;

    // Assert
    EXPECT_EQ(2, a.getD());
}

TEST(Dheap, is_creating_default_d_heap_return_correct_values) {
    // Arrange
    d_heap a;

    // Assert
    EXPECT_EQ(-1, a[0]);
}

TEST(Dheap, can_create_d_heap_with_two_parameters) {
    // Arrange Assert
    ASSERT_NO_THROW(d_heap(2, 10));
}

TEST(Dheap, is_creating_d_heap_with_two_parameters_correct) {
    // Arrange
    d_heap a(3, 10);

    // Assert
    EXPECT_EQ(3, a.getD());
}

TEST(Dheap, is_creating_d_heap_with_two_parameters_correct_2) {
    // Arrange
    d_heap a(3, 10);

    // Assert
    EXPECT_EQ(0, a.getCount());
}

TEST(Dheap, is_creating_d_heap_with_two_parameters_correct_3) {
    // Arrange
    d_heap a(3, 10);

    // Assert
    EXPECT_EQ(10, a.getSize());
}

TEST(Dheap, can_find_index_with_value) {
  // Arrange
  d_heap a;
  a.insert(1);
  a.insert(10);

  // Act & Assert
  EXPECT_EQ(1, a.getInd(10));
}

TEST(Dheap, can_return_ULLONG_MAX_when_cannot_find_index_with_value) {
  // Arrange
  d_heap a;
  a.insert(1);

  // Act & Assert
  EXPECT_EQ(-1, a.getInd(10));
}

TEST(Dheap, is_creating_d_heap_with_two_parameters_return_correct_values) {
    // Arrange
    d_heap a(3, 10);
    size_t i = -1;

    // Assert
    EXPECT_EQ(i, a[0]);
}


TEST(Dheap, can_create_d_heap_from_copy) {
    // Arrange
    d_heap copy(2, 10);

    // Arrange Assert
    ASSERT_NO_THROW(d_heap a(copy));
}

TEST(Dheap, is_creating_d_heap_from_copy_correct_1) {
    // Arrange
    d_heap copy(3, 10);
    d_heap a(copy);

    // Assert
    EXPECT_EQ(3, a.getD());
}

TEST(Dheap, is_creating_d_heap_from_copy_correct_2) {
    // Arrange
    d_heap copy(3, 10);
    d_heap a(copy);

    // Assert
    EXPECT_EQ(0, a.getCount());
}

TEST(Dheap, is_creating_d_heap_from_copy_correct_3) {
    // Arrange
    d_heap copy(3, 10);
    d_heap a(copy);

    // Assert
    EXPECT_EQ(10, a.getSize());
}

TEST(Dheap, is_creating_d_heap_from_copy_return_correct_values) {
    // Arrange
    d_heap copy(3, 10);
    d_heap a(copy);
    size_t i = -1;

    // Assert
    EXPECT_EQ(i, a[0]);
}

TEST(Dheap, can_insert_element_without_throw) {
    // Arrange
    d_heap a(3, 10);

    // Act Assert
    ASSERT_NO_THROW(a.insert(2));
}

TEST(Dheap, can_insert_element) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2);
    a.insert(4);
    a.insert(3);

    // Assert
    EXPECT_EQ(2, a[0]);
    EXPECT_EQ(4, a[1]);
}

TEST(Dheap, is_insert_element_with_memory_relocate_correct) {
    // Arrange
    d_heap a(3, 4);

    // Act
    a.insert(2);
    a.insert(4);
    a.insert(3);
    a.insert(5);

    // Act Assert
    ASSERT_NO_THROW(a.insert(6));
}

TEST(Dheap, can_return_first_child_without_throws) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2);
    a.insert(4);
    a.insert(3);

    // Act Assert
    ASSERT_NO_THROW(a.firstChild(0));
}

TEST(Dheap, can_return_first_child_1) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2);
    a.insert(4);
    a.insert(3);

    // Act Assert
    EXPECT_EQ(1, a.firstChild(0));
}

TEST(Dheap, can_return_first_child_2) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(6);

    // Act Assert
    EXPECT_EQ(4, a.firstChild(1));
}

TEST(Dheap, can_return_first_child_3) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(6);

    // Act Assert
    EXPECT_EQ(0, a.firstChild(5));
}

TEST(Dheap, can_return_last_child_without_throws) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2);
    a.insert(4);
    a.insert(3);

    // Act Assert
    ASSERT_NO_THROW(a.lastChild(0));
}

TEST(Dheap, can_return_last_child_1) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2);
    a.insert(4);
    a.insert(3);

    // Act Assert
    EXPECT_EQ(3, a.lastChild(0));
}

TEST(Dheap, can_return_last_child_2) {
    // Arrange
    d_heap a(3, 6);

    // Act
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(6);

    // Act Assert
    EXPECT_EQ(5, a.lastChild(1));
}

TEST(Dheap, can_return_last_child_3) {
    // Arrange
    d_heap a(3, 6);

    // Act
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(6);

    // Act Assert
    EXPECT_EQ(0, a.lastChild(5));
}

TEST(Dheap, can_return_min_child_without_throws) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2);
    a.insert(4);
    a.insert(3);

    // Act Assert
    ASSERT_NO_THROW(a.minChild(0));
}

TEST(Dheap, can_return_min_child_1) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2);
    a.insert(4);
    a.insert(3);

    // Act Assert
    EXPECT_EQ(2, a.minChild(0));
}

TEST(Dheap, can_return_min_child_2) {
    // Arrange
    d_heap a(3, 6);

    // Act
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(6);

    // Act Assert
    EXPECT_EQ(4, a.minChild(1));
}

TEST(Dheap, can_return_father_without_throws) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2);
    a.insert(4);
    a.insert(3);

    // Act Assert
    ASSERT_NO_THROW(a.father(2));
}

TEST(Dheap, can_return_father_1) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2);
    a.insert(4);
    a.insert(3);

    // Act Assert
    EXPECT_EQ(0, a.father(2));
}

TEST(Dheap, can_return_father_2) {
    // Arrange
    d_heap a(3, 6);

    // Act
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(6);

    // Act Assert
    EXPECT_EQ(1, a.father(5));
}

TEST(Dheap, can_ascent_element_without_throws) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(1);

    // Act Assert
    ASSERT_NO_THROW(a.ascent(4));
}

TEST(Dheap, can_ascent_element_1) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(1); a.ascent(4);

    // Assert
    EXPECT_EQ(1, a[0]);
}

TEST(Dheap, can_ascent_element_2) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(1);

    // Assert
    EXPECT_EQ(1, a[0]);
}

TEST(Dheap, can_immersion_element_without_throws) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(5); a.insert(1);
    a.insert(3); a.insert(2);
    a.insert(4);

    // Act Assert
    ASSERT_NO_THROW(a.dive(0));
}

TEST(Dheap, can_immersion_element_1) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(5); a.insert(1);
    a.insert(3); a.insert(2);
    a.insert(4);
    a.dive(0);

    // Assert
    EXPECT_EQ(1, a[0]);
    EXPECT_EQ(5, a[4]);
}

TEST(Dheap, can_immersion_element_2) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(1);
    a.dive(1);

    // Assert
    EXPECT_EQ(4, a[5]);
}

TEST(Dheap, can_delete_element_without_throws) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(1); a.insert(4);
    a.insert(3); a.insert(2);
    a.insert(5);

    // Act Assert
    ASSERT_NO_THROW(a.del(0));
}

TEST(Dheap, can_delete_element_1) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(1); a.insert(4);
    a.insert(3); a.insert(2);
    a.insert(5);
    a.del(0);

    // Assert
    EXPECT_EQ(2, a[0]);
    EXPECT_EQ(5, a[3]);
}

TEST(Dheap, can_delete_element_2) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2); a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(1);
    a.del(5);

    // Assert
    EXPECT_EQ(2, a[1]);
}

TEST(Dheap, can_delete_element_3) {
    // Arrange
    d_heap a(2, 10);

    // Act
    a.insert(1); a.insert(10);
    a.insert(2); a.insert(15);
    a.insert(20); a.insert(5);
    a.del(3);

    // Assert
    EXPECT_EQ(5, a[1]);
}

TEST(Dheap, can_decrease_element_key_without_throws) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(1); a.insert(4);
    a.insert(3); a.insert(2);
    a.insert(5);

    // Act Assert
    ASSERT_NO_THROW(a.key_decrease(4, 4));
}

TEST(Dheap, can_decrease_element_keyt_1) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(1); a.insert(4);
    a.insert(3); a.insert(2);
    a.insert(5);
    a.key_decrease(4, 4);

    // Assert
    EXPECT_EQ(1, a[0]);
    EXPECT_EQ(1, a[1]);
}

TEST(Dheap, can_decrease_element_key_2) {
    // Arrange
    d_heap a(3, 10);

    // Act
    a.insert(2), a.insert(4);
    a.insert(3); a.insert(5);
    a.insert(5); a.insert(1);
    a.key_decrease(4, 2);

    // Assert
    EXPECT_EQ(3, a[4]);
}
