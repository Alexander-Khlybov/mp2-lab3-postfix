#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <class KeyType>
class Node {
public:
    KeyType key_;
    Node<KeyType>* next_;

    Node(void) { next_ = 0; };
    Node(const KeyType& key) { key_ = key; next_ = 0; };
    Node(const Node<KeyType>* node) { key_ = node->key_;  next_ = node->next_; };
    ~Node(void) { delete next_; };
};

#endif