package io.binac.leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * <p>Given an array of <code>points</code> where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents a int[] on the <strong>X-Y</strong> plane, return <em>the maximum number of points that lie on the same straight line</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/plane1.jpg" style="width: 300px; height: 294px;">
 * <pre><strong>Input:</strong> points = [[1,1],[2,2],[3,3]]
 * <strong>Output:</strong> 3
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/plane2.jpg" style="width: 300px; height: 294px;">
 * <pre><strong>Input:</strong> points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * <strong>Output:</strong> 4
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= points.length &lt;= 300</code></li>
 * 	<li><code>points[i].length == 2</code></li>
 * 	<li><code>-10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
 * 	<li>All the <code>points</code> are <strong>unique</strong>.</li>
 * </ul>
 */
public class MaxPointsOnALine {
    public static class Solution1 {
        private static class Slope {
            final int deltaX;
            final int deltaY;
            private final int hash;

            Slope(int[] p1, int[] p2) {
                if (p1[0] == p2[0] && p1[1] == p2[1])
                    throw new IllegalArgumentException();
                deltaX = p1[0] - p2[0];
                deltaY = p1[1] - p2[1];
                double k;
                if (deltaX == 0)
                    k = Double.POSITIVE_INFINITY;
                else if (deltaY == 0)
                    k = 0.0;
                else
                    k = (double) deltaY / deltaX;
                hash = Double.hashCode(k);
            }

            @Override
            public int hashCode() {
                return hash;
            }

            @Override
            public boolean equals(Object obj) {
                if (obj == this) return true;
                if (!(obj instanceof Slope))
                    return false;
                Slope that = (Slope) obj;
                return (long) this.deltaX * that.deltaY ==
                        (long) this.deltaY * that.deltaX;
            }
        }

        private boolean pointEquals(int[] p1, int[] p2) {
            return p1[0] == p2[0] && p1[1] == p2[1];
        }

        public int maxPoints(int[][] points) {
            if (points.length < 3)
                return points.length;

            int result = 0;
            Map<Slope, AtomicInteger> map = new HashMap<>();
            for (int i = 0, e = points.length - 1, maxCount, samePoints, j; i < e; ++i) {
                int[] p1 = points[i];
                maxCount = 1;
                samePoints = 0;
                for (j = i + 1; j < points.length; ++j) {
                    int[] p2 = points[j];
                    if (pointEquals(p1, p2)) {
                        ++samePoints;
                    } else {
                        Slope s = new Slope(p1, p2);
                        maxCount = Math.max(maxCount, map.computeIfAbsent(s, k -> new AtomicInteger(1)).incrementAndGet());
                    }
                }
                maxCount += samePoints;
                result = Math.max(result, maxCount);
                map.clear();
            }
            return result;
        }
    }
}
