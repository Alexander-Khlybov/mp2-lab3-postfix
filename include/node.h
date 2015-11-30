#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <cstdlib>

using namespace std;
  typedef char KeyType;

  struct Node {
      KeyType key_;
      Node*   next_;

      Node() { next_ = 0; };
      Node(const KeyType& key) { key_ = key; next_ = 0; };
      Node(const Node* node) { key_ = node->key_;  next_ = node->next_; };
      ~Node(void) { delete next_; };
  };

#endif