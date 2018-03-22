#include <largest-rectangle-in-histogram.h>
#include <stdlib.h>

int largestRectangleArea_84(int *heights, int heightsSize) {
    if (heights == NULL || heightsSize < 1) return 0;

    int largest = 0;
    int *stack = (int *) malloc(heightsSize * sizeof(int));
    int top = -1;
    int h, start, width;
    int area;
    int i = 0;
    while (i < heightsSize) {
        if (top == -1 || heights[i] >= heights[stack[top]]) {
            stack[++top] = i;
            ++i;
        } else {
            h = heights[stack[top--]];
            start = top == -1 ? 0 : stack[top] + 1;
            width = i - start;
            area = width * h;
            if (area > largest) largest = area;
        }
    }
    while (top != -1) {
        h = heights[stack[top--]];
        start = top == -1 ? 0 : stack[top] + 1;
        width = heightsSize - start;
        area = width * h;
        if (area > largest) largest = area;
    }
    free(stack);
    return largest;
}
