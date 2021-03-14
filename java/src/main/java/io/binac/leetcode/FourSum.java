package io.binac.leetcode;

import java.util.*;

/**
 * <p>Given an array <code>nums</code> of <em>n</em> integers and an integer <code>target</code>, are there elements <em>a</em>, <em>b</em>, <em>c</em>, and <em>d</em> in <code>nums</code> such that <em>a</em> + <em>b</em> + <em>c</em> + <em>d</em> = <code>target</code>? Find all unique quadruplets in the array which gives the sum of <code>target</code>.</p>
 *
 * <p><strong>Notice</strong>&nbsp;that&nbsp;the solution set must not contain duplicate quadruplets.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <pre><strong>Input:</strong> nums = [1,0,-1,0,-2,2], target = 0
 * <strong>Output:</strong> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * </pre><p><strong>Example 2:</strong></p>
 * <pre><strong>Input:</strong> nums = [], target = 0
 * <strong>Output:</strong> []
 * </pre>
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= nums.length &lt;= 200</code></li>
 * 	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
 * 	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
 * </ul>
 */
public class FourSum {
    public static class Solution1 {
        public List<List<Integer>> fourSum(int[] nums, int target) {
            Arrays.sort(nums);
            List<List<Integer>> result = new ArrayList<>();
            for (int i1 = 0, i2, i3, i4, sum; i1 < nums.length - 3; ) {
                for (i2 = i1 + 1; i2 < nums.length - 2; ) {
                    i3 = i2 + 1;
                    i4 = nums.length - 1;
                    sum = target - nums[i1] - nums[i2];
                    while (i3 < i4) {
                        if (nums[i3] + nums[i4] < sum) {
                            do {
                                ++i3;
                            } while (i3 < i4 && nums[i3] == nums[i3 - 1]);
                        } else if (nums[i3] + nums[i4] > sum) {
                            do {
                                --i4;
                            } while (i3 < i4 && nums[i4] == nums[i4 + 1]);
                        } else {
                            result.add(Arrays.asList(nums[i1], nums[i2], nums[i3], nums[i4]));
                            do {
                                ++i3;
                            } while (i3 < i4 && nums[i3] == nums[i3 - 1]);
                            do {
                                --i4;
                            } while (i3 < i4 && nums[i4] == nums[i4 + 1]);
                        }
                    }
                    do {
                        ++i2;
                    } while (i2 < nums.length - 2 && nums[i2] == nums[i2 - 1]);
                }
                do {
                    ++i1;
                } while (i1 < nums.length - 2 && nums[i1] == nums[i1 - 1]);
            }
            return result;
        }
    }


    public static class Solution2 {
        public List<List<Integer>> fourSum(int[] nums, int target) {
            Set<List<Integer>> set = new HashSet<>();
            Map<Integer, List<int[]>> map = new HashMap<>();
            for (int i = 0; i < nums.length; ++i) {
                for (int j = i + 1; j < nums.length; ++j) {
                    List<int[]> list = map.computeIfAbsent(nums[i] + nums[j], k -> new ArrayList<>());
                    list.add(new int[]{i, j});
                }
            }
            for (Integer key : map.keySet()) {
                List<int[]> list1 = map.get(key), list2 = map.get(target - key);
                if (list2 == null) continue;
                for (int[] a : list1) {
                    for (int[] b : list2) {
                        if (a[0] == b[0] || a[0] == b[1] || a[1] == b[0] || a[1] == b[1])
                            continue;
                        List<Integer> quadruplet = new ArrayList<>();
                        quadruplet.add(nums[a[0]]);
                        quadruplet.add(nums[a[1]]);
                        quadruplet.add(nums[b[0]]);
                        quadruplet.add(nums[b[1]]);
                        quadruplet.sort(Comparator.comparingInt(o -> o));
                        set.add(quadruplet);
                    }
                }
            }
            return new ArrayList<>(set);
        }
    }
}
