#include "merge_intervals.h"

#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct Interval interval;

static int compare(const void *a, const void *b) {
    return ((interval *) a)->start - ((interval *) b)->start;
}

struct Interval *merge_56_1(struct Interval *intervals, int intervalsSize, int *returnSize) {
    if (intervals == NULL || intervalsSize < 0 || returnSize == NULL) return NULL;

    *returnSize = 0;
    interval *ret = (interval *) malloc(intervalsSize * sizeof(interval));
    if (intervalsSize == 0) return ret;

    qsort(intervals, intervalsSize, sizeof(interval), compare);
    ret[(*returnSize)++] = intervals[0];
    interval *last = ret;
    for (int i = 1; i < intervalsSize; ++i) {
        if (last->end >= intervals[i].start) {
            last->end = MAX(last->end, intervals[i].end);
        } else {
            ret[(*returnSize)++] = intervals[i];
            ++last;
        }
    }
    ret = (interval *) realloc(ret, (*returnSize) * sizeof(interval));
    return ret;
}
