#include <stddef.h>
#include <trapping_rain_water.h>

int trap_42_1(int *height, int heightSize) {
    if (height == NULL || heightSize < 0) return -1;
    if (heightSize == 0) return 0;

    int left_max[heightSize];
    left_max[0] = 0;
    for (int i = 1; i < heightSize; ++i) {
        left_max[i] = left_max[i - 1] > height[i - 1] ? left_max[i - 1] : height[i - 1];
    }
    int right_max[heightSize];
    right_max[heightSize - 1] = 0;
    for (int i = heightSize - 2; i >= 0; --i) {
        right_max[i] = right_max[i + 1] > height[i + 1] ? right_max[i + 1] : height[i + 1];
    }
    int min_max[heightSize];
    for (int i = 0; i < heightSize; ++i) {
        min_max[i] = left_max[i] < right_max[i] ? left_max[i] : right_max[i];
    }

    int capacity, sum = 0;
    for (int i = 0; i < heightSize; ++i) {
        capacity = min_max[i] - height[i];
        if (capacity > 0) sum += capacity;
    }
    return sum;
}

int trap_42_2(int *height, int heightSize) {
    if (height == NULL || heightSize < 0) return -1;
    if (heightSize == 0) return 0;

    int peak = 0;
    for (int i = 0; i < heightSize; ++i) {
        if (height[i] > height[peak]) peak = i;
    }

    int left_max = height[0];
    int capacity, sum = 0;
    for (int i = 1; i < peak; ++i) {
        capacity = left_max - height[i];
        if (capacity > 0) sum += capacity;
        left_max = left_max > height[i] ? left_max : height[i];
    }
    int right_max = height[heightSize - 1];
    for (int i = heightSize - 2; i > peak; --i) {
        capacity = right_max - height[i];
        if (capacity > 0) sum += capacity;
        right_max = right_max > height[i] ? right_max : height[i];
    }
    return sum;
}
