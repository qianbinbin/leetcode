#include "pascals_triangle.h"

#include <stdlib.h>

int **generate_118_1(int numRows, int *returnSize, int **returnColumnSizes) {
    int **ret = (int **) malloc(numRows * sizeof(int *));
    ret[0] = (int *) malloc(sizeof(int));
    ret[0][0] = 1;
    *returnColumnSizes = (int *) malloc(numRows * sizeof(int));
    (*returnColumnSizes)[0] = 1;

    for (int i = 1, j; i < numRows; ++i) {
        ret[i] = (int *) malloc((i + 1) * sizeof(int));
        ret[i][0] = ret[i][i] = 1;
        for (j = 1; j < i; ++j)
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        (*returnColumnSizes)[i] = i + 1;
    }
    *returnSize = numRows;
    return ret;
}
