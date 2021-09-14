#include "merge_intervals.h"

#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) >= (b) ? (a) : (b))

static int compare(const void *a, const void *b) {
    return **((int **) a) - **((int **) b);
}

int *copy_interval(int *i) {
    int *ret = (int *) malloc(2 * sizeof(int));
    memcpy(ret, i, 2 * sizeof(int));
    return ret;
}

int **merge_56_1(int **intervals, int intervalsSize, int *intervalsColSize,
                 int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    int **ret = (int **) malloc(intervalsSize * sizeof(int *));
    *returnColumnSizes = (int *) malloc(intervalsSize * sizeof(int));
    if (intervalsSize == 0) return ret;

    qsort(intervals, intervalsSize, sizeof(int *), compare);
    int *last;
    last = ret[(*returnSize)++] = copy_interval(intervals[0]);
    (*returnColumnSizes)[0] = 2;
    for (int i = 1; i < intervalsSize; ++i) {
        if (last[1] >= intervals[i][0]) {
            last[1] = MAX(last[1], intervals[i][1]);
        } else {
            last = ret[*returnSize] = copy_interval(intervals[i]);
            (*returnColumnSizes)[*returnSize] = 2;
            ++(*returnSize);
        }
    }
    ret = (int **) realloc(ret, (*returnSize) * sizeof(int *));
    *returnColumnSizes = (int *) realloc(*returnColumnSizes,
                                         (*returnSize) * sizeof(int));
    return ret;
}
