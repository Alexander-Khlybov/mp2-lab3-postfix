#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <cstdlib>

  typedef char KeyType;

  struct Node {
      KeyType key_;
      int*    Next_;
  };

#endif