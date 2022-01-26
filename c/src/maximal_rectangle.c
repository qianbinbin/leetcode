#include "maximal_rectangle.h"

#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximalRectangle_85_1(char **matrix, int matrixSize, int *matrixColSize) {
    const int m = matrixSize, n = matrixColSize[0];

    int *height = (int *) calloc(n, sizeof(int));
    int *begin = (int *) calloc(n, sizeof(int));
    int *end = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) end[i] = n;
    int b, e;

    int result = 0, area;
    for (int i = 0, j; i < m; ++i) {
        b = 0;
        for (j = 0; j < n; ++j) {
            if (matrix[i][j] == '0') {
                begin[j] = 0;
                b = j + 1;
                height[j] = 0;
            } else {
                begin[j] = MAX(begin[j], b);
                ++height[j];
            }
        }
        e = n;
        for (j = n - 1; j >= 0; --j) {
            if (matrix[i][j] == '0') {
                end[j] = n;
                e = j;
            } else {
                end[j] = MIN(end[j], e);
                area = height[j] * (end[j] - begin[j]);
                result = MAX(result, area);
            }
        }
    }
    free(height);
    free(begin);
    free(end);
    return result;
}

int maximalRectangle_85_2(char **matrix, int matrixSize, int *matrixColSize) {
    const int m = matrixSize, n = matrixColSize[0];

    int *stack = (int *) malloc(n * sizeof(int));
    int top = -1;
    int *heights = (int *) calloc(n, sizeof(int));
    int result = 0, area;
    for (int i = 0, j, k, left; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            while (top != -1 && heights[j] <= heights[stack[top]]) {
                k = stack[top--];
                left = top == -1 ? 0 : stack[top] + 1;
                area = heights[k] * (j - left);
                result = MAX(result, area);
            }
            stack[++top] = j;
        }
        while (top != -1) {
            k = stack[top--];
            left = top == -1 ? 0 : stack[top] + 1;
            area = heights[k] * (n - left);
            result = MAX(result, area);
        }
    }
    free(stack);
    free(heights);
    return result;
}
