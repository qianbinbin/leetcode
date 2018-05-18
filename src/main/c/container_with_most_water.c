#include <container_with_most_water.h>
#include <stddef.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxArea_11(int *height, int heightSize) {
    if (height == NULL || heightSize < 0) return -1;
    if (heightSize < 2) return 0;

    int max_area = 0;
    int start = 0, end = heightSize - 1;
    while (start < end) {
        int area = (end - start) * MIN(height[start], height[end]);
        max_area = MAX(area, max_area);
        if (height[start] < height[end]) {
            ++start;
        } else {
            --end;
        }
    }
    return max_area;
}
