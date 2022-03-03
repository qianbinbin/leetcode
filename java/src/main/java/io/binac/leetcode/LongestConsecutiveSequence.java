package io.binac.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * <p>Given an unsorted array of integers <code>nums</code>, return <em>the length of the longest consecutive elements sequence.</em></p>
 *
 * <p>You must write an algorithm that runs in&nbsp;<code>O(n)</code>&nbsp;time.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [100,4,200,1,3,2]
 * <strong>Output:</strong> 4
 * <strong>Explanation:</strong> The longest consecutive elements sequence is <code>[1, 2, 3, 4]</code>. Therefore its length is 4.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [0,3,7,2,5,8,4,6,0,1]
 * <strong>Output:</strong> 9
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
 * 	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
 * </ul>
 */
public class LongestConsecutiveSequence {
    public static class Solution1 {
        public int longestConsecutive(int[] nums) {
            if (nums.length == 0) return 0;

            Set<Integer> set = new HashSet<>();
            for (int num : nums) set.add(num);
            int result = 1;
            for (int num : nums) {
                if (set.contains(num - 1))
                    continue;
                int n = num + 1;
                while (set.contains(n)) ++n;
                result = Math.max(result, n - num);
            }
            return result;
        }
    }

    public static class Solution2 {
        private static class UnionFind {
            private final int[] parent;
            private final int[] rank;

            public UnionFind(int n) {
                parent = new int[n];
                for (int i = 0; i < n; ++i) parent[i] = i;
                rank = new int[n];
            }

            public void union(int a, int b) {
                int root1 = find(a), root2 = find(b);
                if (root1 == root2)
                    return;
                if (rank[root1] > rank[root2]) {
                    parent[root2] = root1;
                } else {
                    parent[root1] = root2;
                    if (rank[root1] == rank[root2])
                        ++rank[root2];
                }
            }

            public int find(int i) {
                if (i == parent[i])
                    return i;
                return parent[i] = find(parent[i]);
            }

            public int getMaxSetSize() {
                int result = 0;
                int[] size = new int[parent.length];
                for (int i = 0, root; i < parent.length; ++i) {
                    root = find(i);
                    ++size[root];
                    result = Math.max(result, size[root]);
                }
                return result;
            }
        }

        public int longestConsecutive(int[] nums) {
            if (nums.length == 0) return 0;

            Map<Integer, Integer> map = new HashMap<>();
            UnionFind uf = new UnionFind(nums.length);
            for (int i = 0; i < nums.length; ++i) {
                if (map.containsKey(nums[i])) continue;
                map.put(nums[i], i);
                Integer left = map.get(nums[i] - 1);
                if (left != null) uf.union(i, left);
                Integer right = map.get(nums[i] + 1);
                if (right != null) uf.union(i, right);
            }
            return uf.getMaxSetSize();
        }
    }
}
