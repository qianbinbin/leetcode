#include "CloneGraph.h"
#include <unordered_map>

using namespace lcpp;

typedef UndirectedGraphNode Node;

static Node *cloneGraph(Node *UGNode,
                        std::unordered_map<int, Node *> &Visited) {
  auto &Copy = Visited[UGNode->val];
  if (Copy != nullptr)
    return Copy;
  Copy = new Node();
  Copy->val = UGNode->val;
  for (const auto &Neighbor : UGNode->neighbors)
    Copy->neighbors.push_back(cloneGraph(Neighbor, Visited));
  return Copy;
}

Node *Solution133_1::cloneGraph(Node *node) {
  if (node == nullptr)
    return nullptr;
  std::unordered_map<int, Node *> Visited;
  return ::cloneGraph(node, Visited);
}
