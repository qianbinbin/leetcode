#include "CloneGraph.h"
#include <queue>
#include <unordered_map>

using namespace lcpp;

static Node *cloneGraph(Node *UGNode,
                        std::unordered_map<int, Node *> &Visited) {
  auto &Copy = Visited[UGNode->val];
  if (Copy != nullptr)
    return Copy;
  Copy = new Node(UGNode->val);
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

Node *Solution133_2::cloneGraph(Node *node) {
  if (node == nullptr)
    return nullptr;
  auto Copy = new Node(node->val);
  std::unordered_map<int, Node *> Visited{{Copy->val, Copy}};
  std::queue<Node *> Queue;
  Queue.push(node);
  while (!Queue.empty()) {
    node = Queue.front();
    Queue.pop();
    const auto &CopiedNode = Visited[node->val];
    for (const auto &Neighbor : node->neighbors) {
      auto &N = Visited[Neighbor->val];
      if (N == nullptr) {
        N = new Node();
        N->val = Neighbor->val;
        Queue.push(Neighbor);
      }
      CopiedNode->neighbors.push_back(N);
    }
  }
  return Copy;
}
