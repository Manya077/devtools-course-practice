// Copyright 2020 Myshkin Andrey & Pauzin Leonid

#include "include/AVL_Tree.h"
#include <stdexcept>

int AVL_Tree::BalanceFactor(Node* top) {
    return GetHeight(top->rightNode) - GetHeight(top->leftNode);
}

void AVL_Tree::fixHeight(Node* top) {
    unsigned char h_left = GetHeight(top->leftNode);
    unsigned char h_right = GetHeight(top->rightNode);
    if (h_left > h_right) {
        top->height = h_left + 1;
    } else {
        top->height = h_right + 1;
    }
}

Node* AVL_Tree::rotateRight(Node* top) {  // private
    Node* q = top->leftNode;
    top->leftNode = q->rightNode;
    q->rightNode = top;
    fixHeight(top);
    fixHeight(q);
    return q;
}

Node* AVL_Tree::rotateLeft(Node* top) {  // private
    Node* p = top->rightNode;
    top->rightNode = p->leftNode;
    p->leftNode = top;
    fixHeight(top);
    fixHeight(p);
    return p;
}

Node* AVL_Tree::Balance(Node* top) {  // private
    fixHeight(top);
    if (BalanceFactor(top) == 2) {
        if (BalanceFactor(top->rightNode) < 0)
            top->rightNode = rotateRight(top->rightNode);
        return rotateLeft(top);
    }
    if (BalanceFactor(top) == -2) {
        if (BalanceFactor(top->leftNode) > 0)
            top->leftNode = rotateLeft(top->leftNode);
        return rotateRight(top);
    }
    return top;
}

Node* AVL_Tree::Insert(Node* top, const int& key_) {
    if (!top) return new Node(key_);
    if (key_ < top->key) {
        top->leftNode = Insert(top->leftNode, key_);
    } else {
        top->rightNode = Insert(top->rightNode, key_);
    }
    return Balance(top);
}


Node* AVL_Tree::FindMin(Node* top) {  // maybe private
    if (top->leftNode) {
        return FindMin(top->leftNode);
    } else {
        return top;
    }
}

Node* AVL_Tree::FindMax(Node* top) {  // maybe private
    if (top->rightNode) {
        return FindMax(top->rightNode);
    } else {
        return top;
    }
}

Node* AVL_Tree::RemoveMin(Node* top) {  // private
    if (top->leftNode == 0)
        return top->rightNode;
    top->leftNode = RemoveMin(top->leftNode);
    return Balance(top);
}

Node* AVL_Tree::Remove(Node* top, const int& key_) {
    if (!top) return 0;
    if (key_ < top->key) {
        top->leftNode = Remove(top->leftNode, key_);
    } else if (key_ > top->key) {
        top->rightNode = Remove(top->rightNode, key_);
    } else {
        Node* q = top->leftNode;
        Node* r = top->rightNode;
        delete top;
        if (!r) return q;
        Node* min = FindMin(r);
        min->rightNode = RemoveMin(r);
        min->leftNode = q;
        return Balance(min);
    }
    return Balance(top);
}

AVL_Tree::AVL_Tree(void) {
    RootNode = nullptr;
}

AVL_Tree::~AVL_Tree(void) {
    if (RootNode != nullptr) DeleteTree(RootNode);
}

void AVL_Tree::DeleteTree(Node* top) {
    if (top->leftNode) { DeleteTree(top->leftNode); }
    if (top->rightNode) { DeleteTree(top->rightNode); }

    if (top) { free(top); top = nullptr; }
}

Node* AVL_Tree::InitRoot(const int& key_) {
    RootNode = new Node(key_);
    return RootNode;
}

Node* AVL_Tree::GetRootNode(void) {
    return RootNode;
}

int AVL_Tree::GetRootKey(void) {
    return RootNode->key;
}

int AVL_Tree::GetHeight(Node* top) {
    if (top) {
        return top->height;
    } else {
        return 0;
    }
}

Node* AVL_Tree::GetLeftSubtree(Node* top) {
    return top->leftNode;
}

Node* AVL_Tree::GetRightSubtree(Node* top) {
    return top->rightNode;
}

int AVL_Tree::GetKey(Node* top) {
    return top->key;
}

int AVL_Tree::FindMin(void) {
    if (RootNode == nullptr)
      throw std::invalid_argument("No data in tree");
    Node* ptr = FindMin(RootNode);
    return ptr->key;
}

int AVL_Tree::FindMax(void) {
    if (RootNode == nullptr)
      throw std::invalid_argument("No data in tree");
    Node* ptr = FindMax(RootNode);
    return ptr->key;
}

Status AVL_Tree::Insert(const int& key_) {
    if (RootNode == nullptr) return STATUS_ERR_NULL_PTR_ROOT;
    RootNode = Insert(RootNode, key_);
    return STATUS_OK;
}

Status AVL_Tree::Remove(const int& key_) {
    if (RootNode == nullptr)
      throw std::invalid_argument("No that data in tree");
    RootNode = Remove(RootNode, key_);
    return STATUS_OK;
}

Status AVL_Tree::FindNode(const int& key_) {
    if (RootNode == nullptr) return STATUS_ERR_NULL_PTR_ROOT;
    Node* tmp = GetRootNode();
    int KeySearch = 0;  // if not found
    while (tmp != nullptr) {
        if (key_ == tmp->key) {
            KeySearch = key_;
            tmp = nullptr;
        } else if (key_ < tmp->key) {
            tmp = tmp->leftNode;
        } else if (key_ > tmp->key) {
            tmp = tmp->rightNode;
        }
    }

    if (KeySearch == key_) {
        return STATUS_OK;
    } else {
        return STATUS_WAR_NODE_NOT_FOUND;
    }
}
