#include <pascals_triangle_ii.h>
#include <stdlib.h>

int *getRow_119(int rowIndex, int *returnSize) {
    if (rowIndex < 0 || returnSize == NULL) return NULL;
    *returnSize = rowIndex + 1;

    int *ret = (int *) malloc((rowIndex + 1) * sizeof(int));

    for (int i = 0; i <= rowIndex; ++i) {
        ret[i] = 1;
        for (int j = i - 1; j > 0; --j) {
            ret[j] = ret[j - 1] + ret[j];
        }
    }
    return ret;
}
