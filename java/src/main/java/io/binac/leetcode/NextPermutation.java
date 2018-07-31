package io.binac.leetcode;

/**
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * <p>
 * <p>If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * <p>
 * <p>The replacement must be in-place and use only constant extra memory.
 * <p>
 * <p>Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * <p>
 * <p>1,2,3 → 1,3,2
 * <p>3,2,1 → 1,2,3
 * <p>1,1,5 → 1,5,1
 */
public class NextPermutation {
    public static class Solution1 {
        private void reverse(int array[], int beginIndex, int endIndex) {
            if (beginIndex < 0 || endIndex > array.length || beginIndex >= endIndex)
                throw new IndexOutOfBoundsException();

            final int sum = beginIndex + endIndex;
            final int half = sum >>> 1;
            int tmp, i, j;
            for (i = beginIndex; i < half; ++i) {
                j = sum - 1 - i;
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }

        public void nextPermutation(int[] nums) {
            if (nums.length < 2)
                return;

            int i = nums.length - 2;
            while (i >= 0 && nums[i] >= nums[i + 1]) --i;
            if (i == -1) {
                reverse(nums, 0, nums.length);
                return;
            }

            // NOTE: binary search is slower under small array conditions
            // int low = nums.length - 1, high = i + 1;
            // while (low >= high) {
            //     int mid = (low + high) >>> 1;
            //     if (nums[mid] <= nums[i])
            //         low = mid - 1;
            //     else
            //         high = mid + 1;
            // }
            // int tmp = nums[i];
            // nums[i] = nums[low];
            // nums[low] = tmp;

            int j = i + 1;
            while (j < nums.length && nums[j] > nums[i]) ++j;
            int tmp = nums[i];
            nums[i] = nums[j - 1];
            nums[j - 1] = tmp;

            reverse(nums, i + 1, nums.length);
        }
    }
}
