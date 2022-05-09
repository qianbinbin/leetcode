package io.binac.leetcode;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Objects;
import java.util.PriorityQueue;

/**
 * <p>You are given an array of integers&nbsp;<code>nums</code>, there is a sliding window of size <code>k</code> which is moving from the very left of the array to the very right. You can only see the <code>k</code> numbers in the window. Each time the sliding window moves right by one position.</p>
 *
 * <p>Return <em>the max sliding window</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [1,3,-1,-3,5,3,6,7], k = 3
 * <strong>Output:</strong> [3,3,5,5,6,7]
 * <strong>Explanation:</strong>
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       <strong>3</strong>
 *  1 [3  -1  -3] 5  3  6  7       <strong>3</strong>
 *  1  3 [-1  -3  5] 3  6  7      <strong> 5</strong>
 *  1  3  -1 [-3  5  3] 6  7       <strong>5</strong>
 *  1  3  -1  -3 [5  3  6] 7       <strong>6</strong>
 *  1  3  -1  -3  5 [3  6  7]      <strong>7</strong>
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> nums = [1], k = 1
 * <strong>Output:</strong> [1]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
 * 	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>1 &lt;= k &lt;= nums.length</code></li>
 * </ul>
 */
public class SlidingWindowMaximum {
    public static class Solution1 {
        public int[] maxSlidingWindow(int[] nums, int k) {
            int[] result = new int[nums.length - k + 1];
            int size = 0;
            PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> b[0] - a[0]);
            int i;
            for (i = 0; i < k - 1; ++i)
                heap.add(new int[]{nums[i], i});
            for (; i < nums.length; ++i) {
                heap.add(new int[]{nums[i], i});
                while (Objects.requireNonNull(heap.peek())[1] <= i - k) heap.remove();
                result[size++] = Objects.requireNonNull(heap.peek())[0];
            }
            return result;
        }
    }

    public static class Solution2 {
        public int[] maxSlidingWindow(int[] nums, int k) {
            int[] result = new int[nums.length - k + 1];
            int size = 0;
            Deque<Integer> deque = new ArrayDeque<>();
            int i;
            for (i = 0; i < k - 1; ++i) {
                while (!deque.isEmpty() && nums[i] >= nums[deque.getLast()])
                    deque.removeLast();
                deque.addLast(i);
            }
            for (; i < nums.length; ++i) {
                while (!deque.isEmpty() && deque.getFirst() <= i - k)
                    deque.removeFirst();
                while (!deque.isEmpty() && nums[i] >= nums[deque.getLast()])
                    deque.removeLast();
                deque.addLast(i);
                result[size++] = nums[deque.getFirst()];
            }
            return result;
        }
    }

    public static class Solution3 {
        public int[] maxSlidingWindow(int[] nums, int k) {
            final int n = nums.length;
            int[] leftMax = new int[n], rightMax = new int[n];
            leftMax[0] = nums[0];
            for (int i = 1; i < n; ++i)
                leftMax[i] = i % k == 0 ? nums[i] : Math.max(leftMax[i - 1], nums[i]);
            rightMax[n - 1] = nums[n - 1];
            for (int i = n - 2; i >= 0; --i)
                rightMax[i] = (i + 1) % k == 0 ? nums[i] : Math.max(rightMax[i + 1], nums[i]);

            int[] result = new int[n - k + 1];
            for (int i = 0; i <= n - k; ++i)
                result[i] = Math.max(rightMax[i], leftMax[i + k - 1]);
            return result;
        }
    }
}
