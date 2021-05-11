#include "trapping_rain_water.h"

#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int trap_42_1(int *height, int heightSize) {
    if (heightSize < 3) return 0;

    int ret = 0;

    int *left_max = (int *) malloc(heightSize * sizeof(int));
    left_max[0] = 0;
    for (int i = 1; i < heightSize - 1; ++i)
        left_max[i] = MAX(left_max[i - 1], height[i - 1]);

    int *right_max = (int *) malloc(heightSize * sizeof(int));
    right_max[heightSize - 1] = 0;
    for (int i = heightSize - 2, h; i > 0; --i) {
        right_max[i] = MAX(right_max[i + 1], height[i + 1]);
        h = MIN(left_max[i], right_max[i]) - height[i];
        if (h > 0) ret += h;
    }
    free(left_max);
    free(right_max);
    return ret;
}

int trap_42_2(int *height, int heightSize) {
    if (heightSize < 3) return 0;

    int *stack = (int *) malloc(heightSize * sizeof(int));
    int top = -1;
    int ret = 0;
    for (int i = 0, j, left_bound; i < heightSize; ++i) {
        while (top != -1 && height[j = stack[top]] < height[i]) {
            if (--top == -1) break;
            left_bound = stack[top];
            ret += (MIN(height[left_bound], height[i]) - height[j]) *
                   (i - left_bound - 1);
        }
        stack[++top] = i;
    }
    free(stack);
    return ret;
}

int trap_42_3(int *height, int heightSize) {
    if (heightSize < 3) return 0;

    int ret = 0;
    int i = 0, j = heightSize - 1;
    int left_max = 0, right_max = 0;
    while (i < j) {
        if (height[i] <= height[j]) {
            if (left_max <= height[i])
                left_max = height[i];
            else
                ret += left_max - height[i];
            ++i;
        } else {
            if (right_max <= height[j])
                right_max = height[j];
            else
                ret += right_max - height[j];
            --j;
        }
    }
    return ret;
}
