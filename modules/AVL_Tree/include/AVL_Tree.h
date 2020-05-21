// Copyright 2020 Myshkin Andrey & Pauzin Leonid
#ifndef MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_

#include <utility>
#include <random>

enum Status {
    STATUS_WAR_NODE_NOT_FOUND = 1,
    STATUS_OK = 0,
    STATUS_ERR_NULL_PTR_ROOT = -1
};

struct Node {
    int key;
    int height;
    Node* leftNode;
    Node* rightNode;
    explicit Node(int key_) : key(key_), height(1),
        leftNode(nullptr), rightNode(nullptr) {}
};


class AVL_Tree {
 private:
    Node* RootNode;

    int BalanceFactor(Node* top);
    void fixHeight(Node* top);

    // Balance
    Node* rotateRight(Node* top);  // right turn around top
    Node* rotateLeft(Node* top);  // left turn around top
    Node* Balance(Node* top);  // top node balancing

    Node* Insert(Node* top, const int& key_);

    Node* FindMin(Node* top);
    Node* FindMax(Node* top);

    // Delete
    Node* RemoveMin(Node* top);
    Node* Remove(Node* top, const int& key_);

    void DeleteTree(Node* top);

 public:
    AVL_Tree(void);
    ~AVL_Tree(void);

    Node* InitRoot(const int& key_);  // Init RootNode

    Node* GetRootNode(void);  // Get functions
    int GetRootKey(void);
    int GetHeight(Node* top);
    Node* GetLeftSubtree(Node* top);
    Node* GetRightSubtree(Node* top);
    int GetKey(Node* top);

    int FindMin(void);
    int FindMax(void);

    Status Insert(const int& key_);
    Status Remove(const int& key_);
    Status FindNode(const int& key_);
};

#endif  // MODULES_AVL_TREE_INCLUDE_AVL_TREE_H_
