package io.binac.leetcode;

import java.util.*;

/**
 * <p>There are a total of <code>numCourses</code> courses you have to take, labeled from <code>0</code> to <code>numCourses - 1</code>. You are given an array <code>prerequisites</code> where <code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that you <strong>must</strong> take course <code>b<sub>i</sub></code> first if you want to take course <code>a<sub>i</sub></code>.</p>
 *
 * <ul>
 * 	<li>For example, the pair <code>[0, 1]</code>, indicates that to take course <code>0</code> you have to first take course <code>1</code>.</li>
 * </ul>
 *
 * <p>Return <em>the ordering of courses you should take to finish all courses</em>. If there are many valid answers, return <strong>any</strong> of them. If it is impossible to finish all courses, return <strong>an empty array</strong>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> numCourses = 2, prerequisites = [[1,0]]
 * <strong>Output:</strong> [0,1]
 * <strong>Explanation:</strong> There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * <strong>Output:</strong> [0,2,1,3]
 * <strong>Explanation:</strong> There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> numCourses = 1, prerequisites = []
 * <strong>Output:</strong> [0]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= numCourses &lt;= 2000</code></li>
 * 	<li><code>0 &lt;= prerequisites.length &lt;= numCourses * (numCourses - 1)</code></li>
 * 	<li><code>prerequisites[i].length == 2</code></li>
 * 	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; numCourses</code></li>
 * 	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
 * 	<li>All the pairs <code>[a<sub>i</sub>, b<sub>i</sub>]</code> are <strong>distinct</strong>.</li>
 * </ul>
 */
public class CourseScheduleII {
    public static class Solution1 {
        public int[] findOrder(int numCourses, int[][] prerequisites) {
            Map<Integer, List<Integer>> graph = new HashMap<>();
            int[] inDegrees = new int[numCourses];
            for (int[] pre : prerequisites) {
                graph.computeIfAbsent(pre[1], k -> new ArrayList<>()).add(pre[0]);
                ++inDegrees[pre[0]];
            }
            Queue<Integer> queue = new ArrayDeque<>();
            for (int i = 0; i < numCourses; ++i) {
                if (inDegrees[i] == 0)
                    queue.offer(i);
            }
            int[] result = new int[numCourses];
            int i = 0;
            int j;
            while (!queue.isEmpty()) {
                j = queue.remove();
                result[i++] = j;
                List<Integer> neighbors = graph.get(j);
                if (neighbors == null)
                    continue;
                for (int n : neighbors) {
                    if (--inDegrees[n] == 0)
                        queue.offer(n);
                }
                neighbors.clear();
            }
            return i == numCourses ? result : new int[0];
        }
    }

    public static class Solution2 {
        private boolean findOrder(Map<Integer, List<Integer>> graph, int i,
                                  boolean[] permanentMarks, List<Integer> result, boolean[] temporaryMarks) {
            if (permanentMarks[i])
                return true;
            if (temporaryMarks[i])
                return false;
            temporaryMarks[i] = true;
            List<Integer> neighbors = graph.get(i);
            if (neighbors != null) {
                for (int n : neighbors) {
                    if (!findOrder(graph, n, permanentMarks, result, temporaryMarks))
                        return false;
                }
            }
            temporaryMarks[i] = false;
            permanentMarks[i] = true;
            result.add(i);
            return true;
        }

        public int[] findOrder(int numCourses, int[][] prerequisites) {
            Map<Integer, List<Integer>> graph = new HashMap<>();
            for (int[] pre : prerequisites)
                graph.computeIfAbsent(pre[1], k -> new ArrayList<>()).add(pre[0]);
            boolean[] permanentMarks = new boolean[numCourses];
            List<Integer> stack = new ArrayList<>();
            for (int i = 0; i < numCourses; ++i) {
                if (!findOrder(graph, i, permanentMarks, stack, new boolean[numCourses]))
                    return new int[0];
            }
            Collections.reverse(stack);
            return stack.stream().mapToInt(Integer::intValue).toArray();
        }
    }
}
