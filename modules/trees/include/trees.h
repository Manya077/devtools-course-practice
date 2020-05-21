// Copyright 2020 Yasakova Anastasia & Sinitsina Maria

#ifndef MODULES_TREES_INCLUDE_TREES_H_
#define MODULES_TREES_INCLUDE_TREES_H_

#include <initializer_list>

class TreeNode {
 protected:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
 public:
    TreeNode(int data_ = 0, TreeNode* left_ = nullptr,
        TreeNode* right_ = nullptr, TreeNode* parent_ = nullptr);
    int GetData() const;
    TreeNode* GetLeft() const;
    TreeNode* GetRight() const;
    TreeNode* GetParent() const;
    void SetLeft(TreeNode* tmp);
    void SetRight(TreeNode* tmp);
    void SetParent(TreeNode* tmp);
};

class Tree {
    TreeNode* root;
    int amount;
 public:
    explicit Tree(int data_ = 0);
    Tree(std::initializer_list<int> l);
    Tree(const Tree& tree);
    ~Tree();
    bool operator==(const Tree& tree);
    int GetDataRoot() const;
    int GetAmount() const;
    void AddElem(int data_);
    void AddElem(TreeNode* tmp);
    bool FindElemData(int data_) const;
    TreeNode* FindElemNode(int data_) const;
    void DelElem(int data_);
};

#endif  // MODULES_TREES_INCLUDE_TREES_H_
