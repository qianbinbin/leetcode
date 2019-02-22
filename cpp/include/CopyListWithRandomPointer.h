// A linked list is given such that each node contains an additional random
// pointer which could point to any node in the list or null.
//
// Return a deep copy of the list.

#ifndef LEETCODECPP_COPYLISTWITHRANDOMPOINTER_H
#define LEETCODECPP_COPYLISTWITHRANDOMPOINTER_H

#include "RandomListNode.h"

namespace lcpp {

class Solution138_1 {
public:
  RandomListNode *copyRandomList(RandomListNode *head);
};

}

#endif //LEETCODECPP_COPYLISTWITHRANDOMPOINTER_H
