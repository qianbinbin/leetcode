package io.binac.leetcode;

import io.binac.leetcode.util.Point;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [[1,1],[2,2],[3,3]]
 *     Output: 3
 *     Explanation:
 *     ^
 *     |
 *     |        o
 *     |     o
 *     |  o
 *     +------------->
 *     0  1  2  3  4
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 *     Output: 4
 *     Explanation:
 *     ^
 *     |
 *     |  o
 *     |     o        o
 *     |        o
 *     |  o        o
 *     +------------------->
 *     0  1  2  3  4  5  6
 * </blockquote></pre>
 */
public class MaxPointsOnALine {
    public static class Solution1 {
        private static class Slope {
            final int deltaX;
            final int deltaY;
            private final int hash;

            Slope(Point p1, Point p2) {
                if (p1.x == p2.x && p1.y == p2.y)
                    throw new IllegalArgumentException();
                deltaX = p1.x - p2.x;
                deltaY = p1.y - p2.y;
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
                if (obj instanceof Slope) {
                    Slope that = (Slope) obj;
                    return (long) this.deltaX * that.deltaY ==
                            (long) this.deltaY * that.deltaX;
                }
                return false;
            }
        }

        private boolean isSamePoint(Point p1, Point p2) {
            return p1.x == p2.x && p1.y == p2.y;
        }

        public int maxPoints(Point[] points) {
            if (points.length < 3) return points.length;

            int result = 0;
            Map<Slope, AtomicInteger> map = new HashMap<>();
            for (int i = 0; i < points.length - 1; ++i) {
                Point p1 = points[i];
                int maxCount = 1, samePoints = 0;
                for (int j = i + 1; j < points.length; ++j) {
                    Point p2 = points[j];
                    if (isSamePoint(p1, p2)) {
                        ++samePoints;
                    } else {
                        Slope s = new Slope(p1, p2);
                        AtomicInteger count = map.get(s);
                        if (count == null) {
                            count = new AtomicInteger(2);
                            map.put(s, count);
                        } else {
                            count.incrementAndGet();
                        }
                        maxCount = Math.max(maxCount, count.get());
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
