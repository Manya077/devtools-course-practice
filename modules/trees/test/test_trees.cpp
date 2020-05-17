// Copyright 2020 Yasakova Anastasia & Sinitsina Maria

#include <gtest/gtest.h>
#include "include/trees.h"


TEST(TreesTest, Constructor_TreeNode) {
    // Arrange and Act
    TreeNode* node = new TreeNode(4);

    // Assert
    ASSERT_EQ(4, node->GetData());
}

TEST(TreesTest, Constructor_Tree) {
    // Arrange and Act
    Tree tree(0);

    // Assert
    ASSERT_EQ(0, tree.GetDataRoot());
}

TEST(TreesTest, Add_Element) {
    // Arrange
    Tree tree(0);

    // Act
    tree.AddElem(5);

    // Assert
    ASSERT_EQ(2, tree.GetAmount());
}

TEST(TreesTest, Initializer_List_Constructor) {
    // Arrange
    Tree tree1(10);
    tree1.AddElem(5);
    tree1.AddElem(15);
    tree1.AddElem(7);
    tree1.AddElem(20);

    // Act
    Tree tree2 = { 10, 5, 15, 7, 20 };

    // Assert
    ASSERT_EQ(1, tree1 == tree2);
}

TEST(TreesTest, Initializer_List_Constructor_Existing_Elem) {
    // Act, Arrange and Assert
    ASSERT_ANY_THROW(Tree tree({ 10, 5, 15, 7, 20, 5 }));
}

TEST(TreesTest, Equality) {
    // Arrange
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    // Act and Assert
    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Not_Equality_Amount) {
    // Arrange
    Tree tree1 = { 20, 10, 32, 5, 15, 27};
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    // Act and Assert
    ASSERT_FALSE(tree1 == tree2);
}

TEST(TreesTest, Not_Equality) {
    // Arrange
    Tree tree1 = { 20, 10, 32, 5, 15, 27, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    // Act and Assert
    ASSERT_FALSE(tree1 == tree2);
}

TEST(TreesTest, Not_Equality_Structure_1) {
    // Arrange
    Tree tree1 = { 20, 10, 30, 5, 15, 27, 35 };
    Tree tree2 = { 20, 10, 30, 15, 25, 35, 17 };

    // Act and Assert
    ASSERT_FALSE(tree1 == tree2);
}

TEST(TreesTest, Not_Equality_Structure_2) {
    // Arrange
    Tree tree1 = { 20, 10, 30, 5, 15, 27, 35, 7 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35, 40 };

    // Act and Assert
    ASSERT_FALSE(tree1 == tree2);
}

TEST(TreesTest, Add_Existing_Element) {
    // Arrange
    Tree tree = { 20, 10, 30, 5, 15, 25, 35 };

    // Act and Assert
    ASSERT_ANY_THROW(tree.AddElem(5));
}

TEST(TreesTest, Copy_Constructor_Tree) {
    // Arrange
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };

    // Act
    Tree tree2(tree1);

    // Assert
    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Find_Elem_Return_Data) {
    // Arrange
    Tree tree = { 20, 10, 30, 5, 15, 25, 35 };

    // Act and Assert
    ASSERT_TRUE(tree.FindElemData(10));
}

TEST(TreesTest, Not_Find_Elem) {
    // Arrange
    Tree tree = { 20, 10, 30, 5, 15, 25, 35 };

    // Act and Assert
    ASSERT_FALSE(tree.FindElemData(17));
}

TEST(TreesTest, Find_Elem_Return_Node) {
    // Arrange
    Tree tree = { 20, 10, 30, 5, 15, 25, 35 };

    // Act and Assert
    ASSERT_EQ(10, (tree.FindElemNode(10))->GetData());
}

TEST(TreesTest, Del_Left_Leaf) {
    // Arrange
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 35 };

    // Act
    tree1.DelElem(25);

    // Assert
    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Del_Right_Leaf) {
    // Arrange
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25 };

    // Act
    tree1.DelElem(35);

    // Assert
    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Del_Node) {
    // Arrange
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35, 22, 27, 7 };
    Tree tree2 = { 20, 7, 30, 5, 15, 25, 35, 22, 27 };

    // Act
    tree1.DelElem(10);

    // Assert
    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Del_Nonexistent_Elem) {
    // Arrange
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 20, 10, 30, 5, 15, 25, 35 };

    // Act
    tree1.DelElem(40);

    // Assert
    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Del_Root) {
    // Arrange
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35 };
    Tree tree2 = { 15, 10, 30, 5, 25, 35 };

    // Act
    tree1.DelElem(20);

    // Assert
    ASSERT_TRUE(tree1 == tree2);
}

TEST(TreesTest, Some_Tests_To_Del) {
    // Arrange
    Tree tree1 = { 20, 10, 30, 5, 15, 25, 35, 22, 32, 21, 7, 17 };
    Tree tree2 = { 20, 10, 25, 7, 17, 32, 21 };

    // Act
    tree1.DelElem(30);
    tree1.DelElem(5);
    tree1.DelElem(15);
    tree1.DelElem(22);
    tree1.DelElem(35);

    // Assert
    ASSERT_TRUE(tree1 == tree2);
}
