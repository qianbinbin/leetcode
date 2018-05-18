#include <pascals_triangle.h>
#include <stdlib.h>

int **generate_118(int numRows, int **columnSizes) {
    if (numRows < 1 || columnSizes == NULL) return NULL;

    int **ret = (int **) malloc(numRows * sizeof(int *));
    ret[0] = (int *) malloc(sizeof(int));
    ret[0][0] = 1;
    *columnSizes = (int *) malloc(numRows * sizeof(int));
    (*columnSizes)[0] = 1;

    for (int i = 1; i < numRows; ++i) {
        ret[i] = (int *) malloc((i + 1) * sizeof(int));
        ret[i][0] = 1;
        ret[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
        (*columnSizes)[i] = i + 1;
    }
    return ret;
}
