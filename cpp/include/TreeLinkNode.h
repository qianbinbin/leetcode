#ifndef LEETCODECPP_NODE_H
#define LEETCODECPP_NODE_H

namespace lcpp {

class TreeLinkNode {
public:
  int val;
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;

  TreeLinkNode() = default;

  TreeLinkNode(int _val,
               TreeLinkNode *_left,
               TreeLinkNode *_right,
               TreeLinkNode *_next) {
    val = _val;
    left = _left;
    right = _right;
    next = _next;
  }
};

}

#endif //LEETCODECPP_NODE_H
