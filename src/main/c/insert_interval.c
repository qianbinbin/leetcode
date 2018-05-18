#include <insert_interval.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct Interval interval;

struct Interval *insert_57(struct Interval *intervals, int intervalsSize, struct Interval newInterval, int *returnSize) {
    if (intervals == NULL || intervalsSize < 0 || returnSize == NULL) return NULL;

    interval *ret = (interval *) malloc((intervalsSize + 1) * sizeof(interval));
    *returnSize = 0;

    int i = 0;
    for (; i < intervalsSize && intervals[i].end < newInterval.start; ++i) {
        ret[(*returnSize)++] = intervals[i];
    }
    interval merge = newInterval;
    for (; i < intervalsSize && intervals[i].start <= newInterval.end; ++i) {
        merge.start = MIN(merge.start, intervals[i].start);
        merge.end = MAX(merge.end, intervals[i].end);
    }
    ret[(*returnSize)++] = merge;
    for (; i < intervalsSize; ++i) {
        ret[(*returnSize)++] = intervals[i];
    }

    ret = (interval *) realloc(ret, (*returnSize) * sizeof(interval));
    return ret;
}
