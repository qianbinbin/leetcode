#ifndef LEETCODECPP_RANDOMLISTNODE_H
#define LEETCODECPP_RANDOMLISTNODE_H

namespace lcpp {

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  explicit RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

}

#endif //LEETCODECPP_RANDOMLISTNODE_H
