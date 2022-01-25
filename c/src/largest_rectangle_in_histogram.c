#include "largest_rectangle_in_histogram.h"

#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largestRectangleArea_84_1(int *heights, int heightsSize) {
    int result = 0;
    int *stack = (int *) malloc(heightsSize * sizeof(int));
    int top = -1;
    int j, left, area;
    for (int i = 0; i < heightsSize; ++i) {
        while (top != -1 && heights[i] <= heights[stack[top]]) {
            j = stack[top--];
            left = top == -1 ? 0 : stack[top] + 1;
            area = heights[j] * (i - left);
            result = MAX(result, area);
        }
        stack[++top] = i;
    }
    while (top != -1) {
        j = stack[top--];
        left = top == -1 ? 0 : stack[top] + 1;
        area = heights[j] * (heightsSize - left);
        result = MAX(result, area);
    }
    free(stack);
    return result;
}
