"""
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

1. First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
2. Second node is labeled as 1. Connect node 1 to node 2.
3. Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
"""
from queue import Queue
from typing import Optional, Dict

from .utils import UndirectedGraphNode


class Solution1:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node: Optional[UndirectedGraphNode]) -> Optional[UndirectedGraphNode]:
        if node is None:
            return None
        new_node = UndirectedGraphNode(node.label)
        visited = {node: new_node}
        q = Queue()
        q.put(node)
        while not q.empty():
            node = q.get()
            copy = visited[node]
            for neighbor in node.neighbors:
                if neighbor not in visited:
                    visited[neighbor] = UndirectedGraphNode(neighbor.label)
                    q.put(neighbor)
                copy.neighbors.append(visited[neighbor])
        return new_node


class Solution2:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node: Optional[UndirectedGraphNode]) -> Optional[UndirectedGraphNode]:
        if node is None:
            return None
        return self.clone_graph(node, {})

    def clone_graph(self, node: UndirectedGraphNode,
                    visited: Dict[UndirectedGraphNode, UndirectedGraphNode]) -> UndirectedGraphNode:
        if node in visited:
            return visited[node]
        copy = UndirectedGraphNode(node.label)
        visited[node] = copy
        for neighbor in node.neighbors:
            copy.neighbors.append(self.clone_graph(neighbor, visited))
        return copy
