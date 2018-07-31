#include <gtest/gtest.h>

extern "C" {
#include "insert_interval.h"
}

TEST(insert_interval_test, insert_57_1) {
    struct Interval intervals1[2];
    intervals1[0].start = 1;
    intervals1[0].end = 3;
    intervals1[1].start = 6;
    intervals1[1].end = 9;
    int size1 = 0;
    struct Interval new_interval1;
    new_interval1.start = 2;
    new_interval1.end = 5;
    struct Interval *inserted_intervals1 = insert_57_1(intervals1, 2, new_interval1, &size1);
    printf("[");
    for (int i = 0; i < size1; ++i) {
        printf("[%d,%d]", inserted_intervals1[i].start, inserted_intervals1[i].end);
        if (i < size1 - 1) printf(",");
    }
    printf("]\n");

    struct Interval intervals2[5];
    intervals2[0].start = 1;
    intervals2[0].end = 2;
    intervals2[1].start = 3;
    intervals2[1].end = 5;
    intervals2[2].start = 6;
    intervals2[2].end = 7;
    intervals2[3].start = 8;
    intervals2[3].end = 10;
    intervals2[4].start = 12;
    intervals2[4].end = 16;
    struct Interval new_interval2;
    new_interval2.start = 4;
    new_interval2.end = 8;
    int size2 = 0;
    struct Interval *merged_intervals2 = insert_57_1(intervals2, 5, new_interval2, &size2);
    printf("[");
    for (int i = 0; i < size2; ++i) {
        printf("[%d,%d]", merged_intervals2[i].start, merged_intervals2[i].end);
        if (i < size2 - 1) printf(",");
    }
    printf("]\n");
}
