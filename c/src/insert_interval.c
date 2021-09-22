#include "insert_interval.h"

#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int *copy_interval(int const *i) {
    int *ret = (int *) malloc(sizeof(int) * 2);
    ret[0] = i[0];
    ret[1] = i[1];
    return ret;
}

int **insert_57_1(int **intervals, int intervalsSize, int *intervalsColSize,
                  int *newInterval, int newIntervalSize, int *returnSize,
                  int **returnColumnSizes) {
    int **ret = (int **) malloc((intervalsSize + 1) * sizeof(int *));
    *returnSize = 0;

    int i = 0;
    for (; i < intervalsSize && intervals[i][1] < newInterval[0]; ++i)
        ret[(*returnSize)++] = copy_interval(intervals[i]);
    int *merge = copy_interval(newInterval);
    for (; i < intervalsSize && intervals[i][0] <= newInterval[1]; ++i) {
        merge[0] = MIN(merge[0], intervals[i][0]);
        merge[1] = MAX(merge[1], intervals[i][1]);
    }
    ret[(*returnSize)++] = merge;
    merge = NULL;
    for (; i < intervalsSize; ++i)
        ret[(*returnSize)++] = copy_interval(intervals[i]);
    ret = (int **) realloc(ret, (*returnSize) * sizeof(int *));
    *returnColumnSizes = (int *) malloc((*returnSize) * sizeof(int));
    for (int j = 0; j < *returnSize; ++j)
        (*returnColumnSizes)[j] = 2;
    return ret;
}
