#include <unique-paths.h>

int uniquePaths_62_1(int m, int n) {
    if (m < 1 || n < 1) return 0;
    if (m == 1 || n == 1) return 1;
    return uniquePaths_62_1(m - 1, n) + uniquePaths_62_1(m, n - 1);
}
