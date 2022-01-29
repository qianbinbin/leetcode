package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>An <strong>n-bit gray code sequence</strong> is a sequence of <code>2<sup>n</sup></code> integers where:</p>
 *
 * <ul>
 * 	<li>Every integer is in the <strong>inclusive</strong> range <code>[0, 2<sup>n</sup> - 1]</code>,</li>
 * 	<li>The first integer is <code>0</code>,</li>
 * 	<li>An integer appears <strong>no more than once</strong> in the sequence,</li>
 * 	<li>The binary representation of every pair of <strong>adjacent</strong> integers differs by <strong>exactly one bit</strong>, and</li>
 * 	<li>The binary representation of the <strong>first</strong> and <strong>last</strong> integers differs by <strong>exactly one bit</strong>.</li>
 * </ul>
 *
 * <p>Given an integer <code>n</code>, return <em>any valid <strong>n-bit gray code sequence</strong></em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 2
 * <strong>Output:</strong> [0,1,3,2]
 * <strong>Explanation:</strong>
 * The binary representation of [0,1,3,2] is [00,01,11,10].
 * - 0<u>0</u> and 0<u>1</u> differ by one bit
 * - <u>0</u>1 and <u>1</u>1 differ by one bit
 * - 1<u>1</u> and 1<u>0</u> differ by one bit
 * - <u>1</u>0 and <u>0</u>0 differ by one bit
 * [0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
 * - <u>0</u>0 and <u>1</u>0 differ by one bit
 * - 1<u>0</u> and 1<u>1</u> differ by one bit
 * - <u>1</u>1 and <u>0</u>1 differ by one bit
 * - 0<u>1</u> and 0<u>0</u> differ by one bit
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 1
 * <strong>Output:</strong> [0,1]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= n &lt;= 16</code></li>
 * </ul>
 */
public class GrayCode {
    public static class Solution1 {
        public List<Integer> grayCode(int n) {
            List<Integer> result = new ArrayList<>();
            result.add(0);
            int highest_bit;
            for (int i = 0, j; i < n; ++i) {
                highest_bit = 1 << i;
                for (j = result.size() - 1; j >= 0; --j)
                    result.add(result.get(j) | highest_bit);
            }
            return result;
        }
    }

    public static class Solution2 {
        public List<Integer> grayCode(int n) {
            final int size = 1 << n;
            List<Integer> result = new ArrayList<>(size);
            for (int i = 0; i < size; ++i)
                result.add(i ^ (i >> 1));
            return result;
        }
    }
}
