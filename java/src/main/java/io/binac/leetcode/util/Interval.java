package io.binac.leetcode.util;

public class Interval {
    public int start;
    public int end;

    public Interval() {
        start = 0;
        end = 0;
    }

    public Interval(int s, int e) {
        start = s;
        end = e;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj instanceof Interval) {
            Interval another = (Interval) obj;
            return start == another.start && end == another.end;
        }
        return false;
    }
}
