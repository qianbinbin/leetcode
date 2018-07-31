#include "trapping_rain_water.h"

#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int trap_42_1(int *height, int heightSize) {
    if (height == NULL || heightSize < 0) return -1;
    if (heightSize < 3) return 0;

    int *left_max = (int *) malloc(heightSize * sizeof(int));
    left_max[0] = 0;
    for (int i = 1; i < heightSize; ++i)
        left_max[i] = MAX(left_max[i - 1], height[i - 1]);

    int *right_max = (int *) malloc(heightSize * sizeof(int));
    right_max[heightSize - 1] = 0;
    for (int i = heightSize - 2; i >= 0; --i)
        right_max[i] = MAX(right_max[i + 1], height[i + 1]);

    int ret = 0;
    for (int i = 0; i < heightSize; ++i) {
        int h = MIN(left_max[i], right_max[i]) - height[i];
        if (h > 0) ret += h;
    }
    free(left_max);
    free(right_max);
    return ret;
}

int trap_42_2(int *height, int heightSize) {
    if (height == NULL || heightSize < 0) return -1;
    if (heightSize < 3) return 0;

    int *stack = (int *) malloc(heightSize * sizeof(int));
    int top = -1;
    int ret = 0;
    for (int i = 0; i < heightSize; ++i) {
        while (top != -1 && height[stack[top]] < height[i]) {
            int j = stack[top--];
            if (top == -1) break;
            int left_bound = stack[top];
            int length = i - left_bound - 1;
            int h = MIN(height[left_bound], height[i]) - height[j];
            ret += h * length;
        }
        stack[++top] = i;
    }
    free(stack);
    return ret;
}

int trap_42_3(int *height, int heightSize) {
    if (height == NULL || heightSize < 0) return -1;
    if (heightSize < 3) return 0;

    int left = 0, right = heightSize - 1;
    int left_max = 0, right_max = 0;
    int ret = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] < left_max)
                ret += left_max - height[left];
            else
                left_max = height[left];
            ++left;
        } else {
            if (height[right] < right_max)
                ret += right_max - height[right];
            else
                right_max = height[right];
            --right;
        }
    }
    return ret;
}
