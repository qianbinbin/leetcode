#include "container_with_most_water.h"

#include <stddef.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxArea_11_1(int *height, int heightSize) {
    if (height == NULL || heightSize < 0) return -1;
    if (heightSize < 2) return 0;

    int max = 0, area;
    int i = 0, j = heightSize - 1;
    while (i < j) {
        if (height[i] < height[j]) {
            area = (j - i) * height[i];
            ++i;
        } else {
            area = (j - i) * height[j];
            --j;
        }
        max = MAX(max, area);
    }
    return max;
}
