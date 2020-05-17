// Copyright 2020 Nazarov Vladislav

#include <gtest/gtest.h>

#include <random>
#include <algorithm>
#include <vector>

#include "include/rb_tree.h"

TEST(RBTreeTest, Construct_Node) {
    Node node(15);

    ASSERT_EQ(15, node.data);
}

TEST(RBTreeTest, Copy_Node) {
    Node node(15);

    Node copy(node);

    ASSERT_EQ(15, copy.data);
}

TEST(RBTreeTest, Assign_Node) {
    Node n1(5), n2(3);

    n1 = n2;

    ASSERT_EQ(3, n2.data);
}

TEST(RBTreeTest, Equals_Node) {
    Node n1(3), n2(3);

    ASSERT_TRUE(n1 == n2);
}

TEST(RBTreeTest, Not_Equals_Node) {
    Node n1(3), n2(4);

    ASSERT_FALSE(n1 == n2);
}

TEST(RBTreeTest, Not_Equals_Node_Operator) {
    Node n1(3), n2(4);

    ASSERT_TRUE(n1 != n2);
}

TEST(RBTreeTest, Default_Constructor) {
    ASSERT_NO_THROW(RBTree{});
}

TEST(RBTreeTest, Construct_From_Node) {
    Node *node = new Node{};

    ASSERT_NO_THROW(RBTree{node});
}

TEST(RBTreeTest, Construct_From_Vector) {
    std::vector<int> vec{-3, 4, 1};

    ASSERT_NO_THROW(RBTree{vec});
}

TEST(RBTreeTest, Can_Get_Root) {
    Node *node = new Node(2);

    RBTree tree{node};

    ASSERT_EQ(2, tree.getRoot()->data);
}

TEST(RBTreeTest, Can_Find_Existing_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    ASSERT_EQ(14, tree.find(14)->data);
}

TEST(RBTreeTest, Can_Not_Find_Nonexistent_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    ASSERT_EQ(0, tree.find(-14)->data);
}

TEST(RBTreeTest, Can_Insert_New_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    Node *new_node = new Node(3);

    ASSERT_NO_THROW(tree.insert(new_node));
}

TEST(RBTreeTest, Can_Not_Insert_Existing_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    Node *new_node = new Node(-20);

    ASSERT_ANY_THROW(tree.insert(new_node));
}

TEST(RBTreeTest, Can_Remove_Existing_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    ASSERT_NO_THROW(tree.remove(-10));
}

TEST(RBTreeTest, Can_Not_Remove_Nonexistent_Item) {
    std::vector<int> vec{-20, 1, -10, 14};
    RBTree tree{vec};

    ASSERT_ANY_THROW(tree.remove(10));
}

TEST(RBTreeTest, Many_Operations_With_Tree) {
    std::vector<int> vec;
    for (int elem = -100; elem < 101; ++elem)
        vec.emplace_back(elem);
    std::default_random_engine re(0);
    std::shuffle(vec.begin(), vec.end(), re);
    vec.erase(std::find(vec.begin(), vec.end(), 0));
    RBTree tree{vec};

    std::shuffle(vec.begin(), vec.end(), re);
    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
        tree.remove(*iter);

    ASSERT_EQ(Color::black, tree.getRoot()->color);
}
