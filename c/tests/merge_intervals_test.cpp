#include <gtest/gtest.h>

extern "C" {
#include "merge_intervals.h"
}

TEST(merge_intervals_test, merge_56_1) {
    struct Interval intervals1[4];
    intervals1[0].start = 1;
    intervals1[0].end = 3;
    intervals1[1].start = 2;
    intervals1[1].end = 6;
    intervals1[2].start = 8;
    intervals1[2].end = 10;
    intervals1[3].start = 15;
    intervals1[3].end = 18;
    int size1 = 0;
    struct Interval *merged_intervals1 = merge_56_1(intervals1, 4, &size1);
    printf("[");
    for (int i = 0; i < size1; ++i) {
        printf("[%d,%d]", merged_intervals1[i].start, merged_intervals1[i].end);
        if (i < size1 - 1) printf(",");
    }
    printf("]\n");

    struct Interval intervals2[2];
    intervals2[0].start = 1;
    intervals2[0].end = 4;
    intervals2[1].start = 4;
    intervals2[1].end = 5;
    int size2 = 0;
    struct Interval *merged_intervals2 = merge_56_1(intervals2, 2, &size2);
    printf("[");
    for (int i = 0; i < size2; ++i) {
        printf("[%d,%d]", merged_intervals2[i].start, merged_intervals2[i].end);
        if (i < size2 - 1) printf(",");
    }
    printf("]\n");
}
