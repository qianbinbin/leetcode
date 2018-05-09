#include <merge-intervals.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct Interval interval;

static void insert_interval(interval **intervals, int *size, int *capacity, interval new_interval) {
    int i = 0;
    while (i < *size && (*intervals)[i].end < new_interval.start) ++i;
    interval merge = new_interval;
    int j = i;
    for (; j < *size && (*intervals)[j].start <= new_interval.end; ++j) {
        merge.start = MIN(merge.start, (*intervals)[j].start);
        merge.end = MAX(merge.end, (*intervals)[j].end);
    }
    if (i == j && *size >= *capacity) {
        *capacity *= 2;
        *intervals = (interval *) realloc(*intervals, (*capacity) * sizeof(interval));
    }
    if (i + 1 != j) {
        memmove(*intervals + i + 1, *intervals + j, (*size - j) * sizeof(interval));
    }
    (*intervals)[i] = merge;
    *size = i + *size - j + 1;
}

struct Interval *merge_56(struct Interval *intervals, int intervalsSize, int *returnSize) {
    if (intervals == NULL || intervalsSize < 0 || returnSize == NULL) return NULL;

    *returnSize = 0;
    int capacity = 16;
    interval *ret = (interval *) malloc(capacity * sizeof(interval));
    for (int i = 0; i < intervalsSize; ++i) {
        insert_interval(&ret, returnSize, &capacity, intervals[i]);
    }
    ret = (interval *) realloc(ret, (*returnSize) * sizeof(interval));
    return ret;
}
