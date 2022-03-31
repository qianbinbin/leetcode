package io.binac.leetcode;

import java.util.*;

/**
 * <p>There are a total of <code>numCourses</code> courses you have to take, labeled from <code>0</code> to <code>numCourses - 1</code>. You are given an array <code>prerequisites</code> where <code>prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that you <strong>must</strong> take course <code>b<sub>i</sub></code> first if you want to take course <code>a<sub>i</sub></code>.</p>
 *
 * <ul>
 * 	<li>For example, the pair <code>[0, 1]</code>, indicates that to take course <code>0</code> you have to first take course <code>1</code>.</li>
 * </ul>
 *
 * <p>Return <code>true</code> if you can finish all courses. Otherwise, return <code>false</code>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> numCourses = 2, prerequisites = [[1,0]]
 * <strong>Output:</strong> true
 * <strong>Explanation:</strong> There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> numCourses = 2, prerequisites = [[1,0],[0,1]]
 * <strong>Output:</strong> false
 * <strong>Explanation:</strong> There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= numCourses &lt;= 10<sup>5</sup></code></li>
 * 	<li><code>0 &lt;= prerequisites.length &lt;= 5000</code></li>
 * 	<li><code>prerequisites[i].length == 2</code></li>
 * 	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; numCourses</code></li>
 * 	<li>All the pairs prerequisites[i] are <strong>unique</strong>.</li>
 * </ul>
 */
public class CourseSchedule {
    public static class Solution1 {
        public boolean canFinish(int numCourses, int[][] prerequisites) {
            Map<Integer, List<Integer>> graph = new HashMap<>();
            int[] inDegrees = new int[numCourses];
            for (int[] pre : prerequisites) {
                graph.computeIfAbsent(pre[1], k -> new ArrayList<>()).add(pre[0]);
                ++inDegrees[pre[0]];
            }
            Queue<Integer> queue = new ArrayDeque<>();
            for (int i = 0; i < numCourses; ++i) {
                if (inDegrees[i] == 0)
                    queue.add(i);
            }
            int count = 0;
            while (!queue.isEmpty()) {
                ++count;
                List<Integer> neighbors = graph.get(queue.remove());
                if (neighbors == null)
                    continue;
                for (int n : neighbors) {
                    if (--inDegrees[n] == 0)
                        queue.offer(n);
                }
                neighbors.clear();
            }
            return count == numCourses;
        }
    }

    public static class Solution2 {
        private boolean canFinish(Map<Integer, List<Integer>> graph, int i,
                                  boolean[] permanentMarks, boolean[] temporaryMarks) {
            if (permanentMarks[i])
                return true;
            if (temporaryMarks[i])
                return false;
            temporaryMarks[i] = true;
            List<Integer> neighbors = graph.get(i);
            if (neighbors != null) {
                for (int n : neighbors) {
                    if (!canFinish(graph, n, permanentMarks, temporaryMarks))
                        return false;
                }
            }
            temporaryMarks[i] = false;
            permanentMarks[i] = true;
            return true;
        }

        public boolean canFinish(int numCourses, int[][] prerequisites) {
            Map<Integer, List<Integer>> graph = new HashMap<>();
            for (int[] pre : prerequisites)
                graph.computeIfAbsent(pre[1], k -> new ArrayList<>()).add(pre[0]);
            boolean[] permanentMarks = new boolean[numCourses];
            for (int i = 0; i < numCourses; ++i) {
                if (!canFinish(graph, i, permanentMarks, new boolean[numCourses]))
                    return false;
            }
            return true;
        }
    }
}
