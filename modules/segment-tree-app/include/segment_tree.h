// Copyright 2020 Boganov Sergei

#ifndef MODULES_SEGMENT_TREE_APP_INCLUDE_SEGMENT_TREE_H_
#define MODULES_SEGMENT_TREE_APP_INCLUDE_SEGMENT_TREE_H_

#include <vector>
#include <string>

class SegmentTree {
 private:
    std::vector<int> tree;
    std::string _operation;
    int _size;
    void build(const std::vector<int>& arr, int index, int left, int right);
    void update(int index, int l, int r, int change_index, int value);
    int query(int index, int l, int r, int left, int right) const;
    int op(int x, int y) const;
    int gcd(int x, int y) const;

 public:
    explicit SegmentTree(int size = 1);
    explicit SegmentTree(const std::vector<int>& input, std::string operation);
    int query(int left, int right) const;
    void update(int change_index, int value);
    std::vector<int> Get() const;
};

#endif  // MODULES_SEGMENT_TREE_APP_INCLUDE_SEGMENT_TREE_H_
