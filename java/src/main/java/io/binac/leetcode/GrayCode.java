package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 * <p>
 * <p>Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: 2
 *     Output: [0,1,3,2]
 *     Explanation:
 *     00 - 0
 *     01 - 1
 *     11 - 3
 *     10 - 2
 *
 *     For a given n, a gray code sequence may not be uniquely defined.
 *     For example, [0,2,3,1] is also a valid gray code sequence.
 *
 *     00 - 0
 *     10 - 2
 *     11 - 3
 *     01 - 1
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: 0
 *     Output: [0]
 *     Explanation: We define the gray code sequence to begin with 0.
 *                  A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
 *                  Therefore, for n = 0 the gray code sequence is [0].
 * </blockquote></pre>
 */
public class GrayCode {
    public static class Solution1 {
        public List<Integer> grayCode(int n) {
            if (n < 0 || n >= 31)
                throw new IllegalArgumentException();

            final int size = 1 << n;
            List<Integer> result = new ArrayList<>(size);
            for (int i = 0; i < size; ++i)
                result.add(i ^ (i >> 1));
            return result;
        }
    }

    public static class Solution2 {
        public List<Integer> grayCode(int n) {
            if (n < 0 || n >= 31)
                throw new IllegalArgumentException();

            final int size = 1 << n;
            List<Integer> result = new ArrayList<>(size);
            result.add(0);
            for (int i = 0; i < n; ++i) {
                final int highest_bit = 1 << i;
                final int len = result.size();
                for (int j = len - 1; j >= 0; --j)
                    result.add(result.get(j) | highest_bit);
            }
            return result;
        }
    }
}
