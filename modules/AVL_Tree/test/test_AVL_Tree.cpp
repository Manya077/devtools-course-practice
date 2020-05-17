// Copyright 2020 Myshkin Andrey

#include <gtest/gtest.h>

#include "include/AVL_Tree.h"

TEST(Myshkin_Andrey_AVL_Tree, Test_Can_Create_Node) {
    // Arrange & Act
    int key = 9;
    Node tmp(key);

    // Assert
    ASSERT_EQ(key, tmp.key);
}

TEST(Myshkin_Andrey_AVL_Tree, Test_Can_Create_Root_Node) {
    // Arrange & Act
    AVL_Tree tree;

    // Assert
    ASSERT_EQ(nullptr, tree.GetRootNode());
}

TEST(Myshkin_Andrey_AVL_Tree, Test_Get_Root_Height) {
    // Arrange
    int key = 100;
    AVL_Tree tree;

    // Act
    tree.InitRoot(key);

    // Assert
    ASSERT_EQ(1, tree.GetHeight(tree.GetRootNode()));
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Get_Key) {
    // Arrange
    int key = 100;
    AVL_Tree tree;

    // Act
    tree.InitRoot(key);

    // Assert
    ASSERT_EQ(key, tree.GetKey(tree.GetRootNode()));
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Get_Root_Key) {
    // Arrange
    int key = 10;
    AVL_Tree tree;

    // Act
    tree.InitRoot(key);
    int tmp = tree.GetRootKey();

    // Assert
    ASSERT_EQ(key, tmp);
}

TEST(Myshkin_Andrey_AVL_Tree, Test_Get_Left_And_Right_Subtree) {
    // Arrange
    int key = 22;
    AVL_Tree tree;

    // Act
    tree.InitRoot(key);

    // Assert
    EXPECT_EQ(nullptr, tree.GetLeftSubtree(tree.GetRootNode()));
    EXPECT_EQ(nullptr, tree.GetRightSubtree(tree.GetRootNode()));
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Small_Tree_Insert) {
    // Arrange
    int KeyArrays[] = { 10, 20, 30, 40, 50 };
    int sts = 0;
    AVL_Tree tree;

    // Act
    tree.InitRoot(KeyArrays[0]);

    for (int i = 1; i < 5; i++) {
        tree.Insert(KeyArrays[i]);
    }

    for (int i = 0; i < 5; i++) {
        if (tree.FindNode(KeyArrays[i]) != STATUS_OK) {
            sts = -1;
        }
        // Assert
        EXPECT_EQ(0, sts);
    }
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Small_Tree_Found) {
    // Arrange
    int KeyArrays[] = { 150, 120, 90, 60, 30, 200 };
    int sts = 0;
    AVL_Tree tree;

    // Act
    tree.InitRoot(KeyArrays[0]);

    for (int i = 1; i < 6; i++) {
        tree.Insert(KeyArrays[i]);
    }

    for (int i = 0; i < 6; i++) {
        if (tree.FindNode(KeyArrays[i]) != STATUS_OK) {
            sts = -1;
        }
        // Assert
        EXPECT_EQ(0, sts);
    }
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_War_Found) {
    // Arrange
    int KeyArrays[] = { 150, 120, 90, 60, 30, 200 };
    int sts = -1;
    AVL_Tree tree;

    // Act
    tree.InitRoot(KeyArrays[0]);

    for (int i = 1; i < 6; i++) {
        tree.Insert(KeyArrays[i]);
    }

    Status status = tree.FindNode(1000);

    // Assert
    EXPECT_EQ(1, status);
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Find_Max_Two_Nodes) {
    // Arrange
    int KeyArrays[] = { 100, 90 };
    AVL_Tree tree;

    // Act
    tree.InitRoot(KeyArrays[0]);
    tree.Insert(KeyArrays[1]);

    // Assert
    EXPECT_EQ(100, tree.FindMax());
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Find_Max_Eight_Nodes) {
    // Arrange
    int KeyArrays[] = { 100, 90, 200, 400, 500, 300, 250, 330 };
    AVL_Tree tree;

    // Act
    tree.InitRoot(KeyArrays[0]);

    for (int i = 1; i < 8; i++) {
        tree.Insert(KeyArrays[i]);
    }

    // Assert
    EXPECT_EQ(500, tree.FindMax());
}


TEST(Myshkin_Andrey_AVL_Tree, Test_With_Find_Min) {
    // Arrange
    int KeyArrays[] = { 100, 90, 110, 200, 80, 300 };
    AVL_Tree tree;

    // Act
    tree.InitRoot(KeyArrays[0]);

    for (int i = 0; i < 6; i++) {
        tree.Insert(KeyArrays[i]);
    }

    // Assert
    EXPECT_EQ(80, tree.FindMin());
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Remove_Nodes_Balance_Right) {
    // Arrange
    int KeyArrays[] = { 300, 200, 100, 250, 90, 110 };
    int status = 0;
    AVL_Tree tree;

    // Act
    tree.InitRoot(KeyArrays[0]);

    for (int i = 1; i < 6; i++) {
        tree.Insert(KeyArrays[i]);
    }

    status = tree.Remove(250);
    status = tree.Remove(110);
    status = tree.Remove(200);

    // Assert
    EXPECT_EQ(0, status);
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Remove_Nodes_Balance_Left) {
    // Arrange
    int KeyArrays[] = { 500, 800, 600, 900, 660, 700, 500 };
    int status = 0;
    AVL_Tree tree;

    // Act
    tree.InitRoot(KeyArrays[0]);

    for (int i = 1; i < 7; i++) {
        tree.Insert(KeyArrays[i]);
    }

    status = tree.Remove(500);
    status = tree.Remove(600);

    // Assert
    EXPECT_EQ(0, status);
}

TEST(Myshkin_Andrey_AVL_Tree, Test_With_Remove_Node) {
    // Arrange
    int KeyArrays[] = { 500, 300, 200, 400, 600, 700, 800, 100, 220,
                        330, 410, 560, 650, 790, 820 };
    int status = 0;
    AVL_Tree tree;

    // Act
    tree.InitRoot(KeyArrays[0]);

    for (int i = 1; i < 15; i++) {
        tree.Insert(KeyArrays[i]);
    }

    status = tree.Remove(700);

    // Assert
    EXPECT_EQ(0, status);
}
