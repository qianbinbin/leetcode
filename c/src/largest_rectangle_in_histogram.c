#include "largest_rectangle_in_histogram.h"

#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largestRectangleArea_84_1(int *heights, int heightsSize) {
    if (heights == NULL || heightsSize < 1) return 0;

    int largest = 0;
    int *stack = (int *) malloc(heightsSize * sizeof(int));
    int top = -1;
    for (int i = 0; i < heightsSize;) {
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i;
            ++i;
        } else {
            int index = stack[top--];
            int area = heights[index] * (top == -1 ? i : i - stack[top] - 1);
            largest = MAX(largest, area);
        }
    }
    while (top != -1) {
        int index = stack[top--];
        int area = heights[index] * (top == -1 ? heightsSize : heightsSize - stack[top] - 1);
        largest = MAX(largest, area);
    }
    free(stack);
    return largest;
}
