// Copyright 2020 Pauzin Leonid

#ifndef MODULES_AVL_TREE_INCLUDE_AVL_ACTIONS_H_
#define MODULES_AVL_TREE_INCLUDE_AVL_ACTIONS_H_

#include <string>
#include <vector>
#include "include/AVL_Tree.h"

class Operation {
 public:
    explicit Operation(const int _argc) : argc(_argc) {}
    virtual ~Operation() = default;
    static Operation* makeOperation(std::string op);
    virtual std::string operator()(AVL_Tree* tree,
      const std::vector<int>& arg) = 0;
    int getArgc() { return argc; }
 private:
    int argc;
};


class InsertOperation: public Operation {
 public:
    InsertOperation(): Operation(2) {}
    std::string operator()(AVL_Tree* tree,
      const std::vector<int>& arg) override;
};

class RemoveOperation: public Operation {
 public:
    RemoveOperation(): Operation(2) {}
    std::string operator()(AVL_Tree* tree,
      const std::vector<int>& arg) override;
};

#endif  // MODULES_AVL_TREE_INCLUDE_AVL_ACTIONS_H_
