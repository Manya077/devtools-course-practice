// Copyright 2020 Boganov Sergei

#include "include/segment_tree.h"
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

SegmentTree::SegmentTree(int size) {
    if (size <= 0) {
        throw std::string("Cannot be negative or zero size");
    } else {
        _size = size;
        tree.resize(4*size);
    }
}

SegmentTree::SegmentTree(const std::vector<int>& input,
                         std::string operation) {
    int size = static_cast<int>(input.size());
    if (size <= 0) {
        throw std::string("Cannot be negative or zero size");
    } else {
        _size = size;
        _operation = operation;
        tree.resize(4*size);
        build(input, 1, 0, size - 1);
    }
}

int SegmentTree::gcd(int x, int y) const {
    while (x > 0 && y > 0) {
        if (x >= y) {
            x %= y;
        } else {
            y %= x;
        }
    }
    return x + y;
}

int SegmentTree::op(int x, int y) const {
    if (_operation == "+") {
        return x + y;
    } else if (_operation == "max") {
        return std::max(x, y);
    } else if (_operation == "min") {
        return std::min(x, y);
    } else if (_operation == "gcd") {
        return gcd(x, y);
    } else {
        throw std::string("Cannot be this operation");
    }
}

void SegmentTree::build(const std::vector<int>& arr, int index,
                        int left, int right) {
    if (left == right) {
        tree[index] = arr[left];
    } else {
        int mid = left + (right - left)/2;
        build(arr, 2*index, left, mid);
        build(arr, 2*index + 1, mid + 1, right);
        tree[index] = op(tree[2*index], tree[2*index + 1]);
    }
}

std::vector<int> SegmentTree::Get() const {
    return tree;
}

int SegmentTree::query(int index, int l, int r, int left, int right) const {
    if (left > right) {
        return (_operation == "min" ? INT_MAX : 0);
    } else if (left == l && right == r) {
        return tree[index];
    } else {
        int mid = l + (r - l)/2;
        return op(query(2*index, l, mid, left, std::min(right, mid)),
            query(2*index + 1, mid + 1, r, std::max(left, mid + 1), right));
    }
}

int SegmentTree::query(int left, int right) const {
    if (left < 0 || right < 0) {
        throw std::string("left or right interval cannot be negative");
    }
    if (right < left) {
        throw std::string("left interval cannot be > than right");
    }
    if (right >= _size) {
        throw std::string("right interval cannot be > that size");
    }
    return query(1, 0, _size - 1, left, right);
}

void SegmentTree::update(int index, int l, int r, int change_index, int value) {
    if (l == r) {
        tree[index] = value;
        return;
    }
    int mid = l + (r - l)/2;
    if (change_index <= mid) {
        update(2*index, l, mid, change_index, value);
    } else {
        update(2*index + 1, mid + 1, r, change_index, value);
    }
    tree[index] = op(tree[2*index], tree[2*index + 1]);
}

void SegmentTree::update(int change_index, int value) {
    if (change_index < 0 || change_index >= _size) {
        throw std::string("Index cannot be zero or > size");
    }
    update(1, 0, _size - 1, change_index, value);
}
