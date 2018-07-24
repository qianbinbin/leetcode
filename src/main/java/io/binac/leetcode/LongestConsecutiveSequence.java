package io.binac.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * <p>
 * <p>Your algorithm should run in O(n) complexity.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: [100, 4, 200, 1, 3, 2]
 *     Output: 4
 *     Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 * </blockquote></pre>
 */
public class LongestConsecutiveSequence {
    public static class Solution1 {
        public int longestConsecutive(int[] nums) {
            if (nums.length == 0) return 0;

            Set<Integer> set = new HashSet<>();
            for (int num : nums) set.add(num);
            int result = 1;
            for (int num : nums) {
                if (!set.contains(num - 1)) {
                    int n = num + 1;
                    while (set.contains(n)) ++n;
                    result = Math.max(result, n - num);
                }
            }
            return result;
        }
    }

    public static class Solution2 {
        private static class UnionFind {
            private final int parent[];
            private final int rank[];

            public UnionFind(int n) {
                if (n <= 0)
                    throw new IllegalArgumentException();
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
                parent[i] = find(parent[i]);
                return parent[i];
            }

            public int getMaxSetSize() {
                int result = 1;
                int size[] = new int[parent.length];
                for (int i = 0; i < parent.length; ++i) {
                    int root = find(i);
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
