package io.binac.leetcode;

import java.util.*;

/**
 * <p>Given a reference of a node in a <strong><a href="https://en.wikipedia.org/wiki/Connectivity_(graph_theory)#Connected_graph" target="_blank">connected</a></strong> undirected graph.</p>
 *
 * <p>Return a <a href="https://en.wikipedia.org/wiki/Object_copying#Deep_copy" target="_blank"><strong>deep copy</strong></a> (clone) of the graph.</p>
 *
 * <p>Each node in the graph contains a value (<code>int</code>) and a list (<code>List[Node]</code>) of its neighbors.</p>
 *
 * <pre>class Node {
 *     public int val;
 *     public List&lt;Node&gt; neighbors;
 * }
 * </pre>
 *
 * <p>&nbsp;</p>
 *
 * <p><strong>Test case format:</strong></p>
 *
 * <p>For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with <code>val == 1</code>, the second node with <code>val == 2</code>, and so on. The graph is represented in the test case using an adjacency list.</p>
 *
 * <p><b>An adjacency list</b> is a collection of unordered <b>lists</b> used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.</p>
 *
 * <p>The given node will always be the first node with <code>val = 1</code>. You must return the <strong>copy of the given node</strong> as a reference to the cloned graph.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2019/11/04/133_clone_graph_question.png" style="width: 454px; height: 500px;">
 * <pre><strong>Input:</strong> adjList = [[2,4],[1,3],[2,4],[1,3]]
 * <strong>Output:</strong> [[2,4],[1,3],[2,4],[1,3]]
 * <strong>Explanation:</strong> There are 4 nodes in the graph.
 * 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
 * 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
 * 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
 * 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/01/07/graph.png" style="width: 163px; height: 148px;">
 * <pre><strong>Input:</strong> adjList = [[]]
 * <strong>Output:</strong> [[]]
 * <strong>Explanation:</strong> Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> adjList = []
 * <strong>Output:</strong> []
 * <strong>Explanation:</strong> This an empty graph, it does not have any nodes.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the graph is in the range <code>[0, 100]</code>.</li>
 * 	<li><code>1 &lt;= Node.val &lt;= 100</code></li>
 * 	<li><code>Node.val</code> is unique for each node.</li>
 * 	<li>There are no repeated edges and no self-loops in the graph.</li>
 * 	<li>The Graph is connected and all nodes can be visited starting from the given node.</li>
 * </ul>
 */
public class CloneGraph {
    public static class Node {
        public int val;
        public List<Node> neighbors;

        public Node() {
            val = 0;
            neighbors = new ArrayList<>();
        }

        public Node(int _val) {
            val = _val;
            neighbors = new ArrayList<>();
        }

        public Node(int _val, ArrayList<Node> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    }

    public static class Solution1 {
        private Node cloneGraph(Node node, Map<Integer, Node> visited) {
            Node clone = visited.get(node.val);
            if (clone != null) return clone;

            clone = new Node(node.val);
            visited.put(clone.val, clone);
            for (Node n : node.neighbors)
                clone.neighbors.add(cloneGraph(n, visited));
            return clone;
        }

        public Node cloneGraph(Node node) {
            if (node == null)
                return null;
            return cloneGraph(node, new HashMap<>());
        }
    }

    public static class Solution2 {
        public Node cloneGraph(Node node) {
            if (node == null) return null;

            Map<Integer, Node> visited = new HashMap<>();
            Node newNode = new Node(node.val);
            visited.put(newNode.val, newNode);

            Queue<Node> queue = new ArrayDeque<>();
            queue.offer(node);
            while (!queue.isEmpty()) {
                node = Objects.requireNonNull(queue.poll());
                Node clonedNode = visited.get(node.val);
                for (Node neighbor : node.neighbors) {
                    Node clonedNeighbor = visited.get(neighbor.val);
                    if (clonedNeighbor == null) {
                        clonedNeighbor = new Node(neighbor.val);
                        visited.put(clonedNeighbor.val, clonedNeighbor);
                        queue.offer(neighbor);
                    }
                    clonedNode.neighbors.add(clonedNeighbor);
                }
            }
            return newNode;
        }
    }
}
