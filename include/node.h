#ifndef _NODE_H_
#define _NODE_H_

typedef int KeyType;

struct Node {
    KeyType key_;
    int *pNext_;
};

#endif