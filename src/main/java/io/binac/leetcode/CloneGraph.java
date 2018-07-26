package io.binac.leetcode;

import io.binac.leetcode.util.UndirectedGraphNode;

import java.util.*;

/**
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 * <p>
 * <p>
 * <p>OJ's undirected graph serialization:
 * <p>Nodes are labeled uniquely.
 * <p>
 * <p>We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 * <p>As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 * <p>
 * <p>The graph has a total of three nodes, and therefore contains three parts as separated by #.
 * <p>
 * <p>1. First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * <p>2. Second node is labeled as 1. Connect node 1 to node 2.
 * <p>3. Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 * <p>
 * <p>Visually, the graph looks like the following:
 * <blockquote><pre>
 *            1
 *           / \
 *          /   \
 *         0 --- 2
 *              / \
 *              \_/
 * </blockquote></pre>
 */
public class CloneGraph {
    public static class Solution1 {
        private UndirectedGraphNode cloneGraph(UndirectedGraphNode node, Map<Integer, UndirectedGraphNode> visited) {
            UndirectedGraphNode clone = visited.get(node.label);
            if (clone != null) return clone;

            clone = new UndirectedGraphNode(node.label);
            visited.put(clone.label, clone);
            for (UndirectedGraphNode n : node.neighbors)
                clone.neighbors.add(cloneGraph(n, visited));
            return clone;
        }

        public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
            if (node == null)
                return null;
            Map<Integer, UndirectedGraphNode> visited = new HashMap<>();
            return cloneGraph(node, visited);
        }
    }
}
