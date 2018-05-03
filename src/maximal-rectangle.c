#include <maximal-rectangle.h>
#include <limits.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximalRectangle_85(char **matrix, int matrixRowSize, int matrixColSize) {
    if (matrix == NULL || matrixRowSize < 0 || matrixColSize < 0) return -1;

    int *start = (int *) malloc(matrixColSize * sizeof(int));
    int *end = (int *) malloc(matrixColSize * sizeof(int));
    for (int i = 0; i < matrixColSize; ++i) {
        start[i] = INT_MIN;
        end[i] = INT_MAX;
    }
    int *height = (int *) calloc(matrixColSize, sizeof(int));

    int max = 0;

    for (int i = 0; i < matrixRowSize; ++i) {
        int start_1 = 0;
        for (int j = 0; j < matrixColSize; ++j) {
            if (matrix[i][j] == '1') {
                start[j] = MAX(start[j], start_1);
                ++height[j];
            } else {
                start[j] = INT_MIN;
                start_1 = j + 1;
                height[j] = 0;
            }
        }
        int end_1 = matrixColSize;
        for (int j = matrixColSize - 1; j >= 0; --j) {
            if (matrix[i][j] == '1') {
                end[j] = MIN(end[j], end_1);
                int area = height[j] * (end[j] - start[j]);
                max = MAX(max, area);
            } else {
                end[j] = INT_MAX;
                end_1 = j;
            }
        }
    }
    free(height);
    free(end);
    free(start);

    return max;
}
