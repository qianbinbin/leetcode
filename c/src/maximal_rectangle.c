#include "maximal_rectangle.h"

#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maximalRectangle_85_1(char **matrix, int matrixRowSize, int matrixColSize) {
    if (matrix == NULL || matrixRowSize < 0 || matrixColSize < 0) return -1;
    const int row = matrixRowSize, col = matrixColSize;

    int *height = (int *) calloc(col, sizeof(int));
    int *start = (int *) calloc(col, sizeof(int));
    int *end = (int *) malloc(col * sizeof(int));
    for (int i = 0; i < col; ++i) end[i] = col;

    int max = 0;
    for (int i = 0; i < row; ++i) {
        int start1 = 0;
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == '1') {
                start[j] = MAX(start[j], start1);
                ++height[j];
            } else {
                start[j] = 0;
                start1 = j + 1;
                height[j] = 0;
            }
        }
        int end1 = col;
        for (int j = col - 1; j >= 0; --j) {
            if (matrix[i][j] == '1') {
                end[j] = MIN(end[j], end1);
                int area = height[j] * (end[j] - start[j]);
                max = MAX(max, area);
            } else {
                end[j] = col;
                end1 = j;
            }
        }
    }
    free(height);
    free(start);
    free(end);
    return max;
}

int maximalRectangle_85_2(char **matrix, int matrixRowSize, int matrixColSize) {
    if (matrix == NULL || matrixRowSize < 0 || matrixColSize < 0) return -1;
    const int row = matrixRowSize, col = matrixColSize;

    int *stack = (int *) malloc(col * sizeof(int));
    int top = -1;
    int *heights = (int *) calloc(col, sizeof(int));
    int max = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == '1')
                ++heights[j];
            else
                heights[j] = 0;
            while (top != -1 && heights[stack[top]] > heights[j]) {
                int index = stack[top--];
                int area = heights[index] * (top == -1 ? j : j - stack[top] - 1);
                max = MAX(max, area);
            }
            stack[++top] = j;
        }
        while (top != -1) {
            int index = stack[top--];
            int area = heights[index] * (top == -1 ? col : col - stack[top] - 1);
            max = MAX(max, area);
        }
    }
    free(stack);
    free(heights);
    return max;
}
