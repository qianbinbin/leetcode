#include <utility>

#ifndef LEETCODECPP_UNDIRECTEDGRAPHNODE_H
#define LEETCODECPP_UNDIRECTEDGRAPHNODE_H

#include <vector>

namespace lcpp {

class UndirectedGraphNode {
public:
  int val{};
  std::vector<UndirectedGraphNode *> neighbors;

  UndirectedGraphNode() = default;

  UndirectedGraphNode(int _val, std::vector<UndirectedGraphNode *> _neighbors) {
    val = _val;
    neighbors = std::move(_neighbors);
  }
};

}

#endif //LEETCODECPP_UNDIRECTEDGRAPHNODE_H
