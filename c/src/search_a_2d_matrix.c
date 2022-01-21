#include "search_a_2d_matrix.h"

bool searchMatrix_74_1(int **matrix, int matrixRowSize, int matrixColSize,
                       int target) {
    int low = 0, high = matrixRowSize * matrixColSize - 1, mid;
    int i, j;
    while (low <= high) {
        mid = low + (high - low) / 2;
        i = mid / matrixColSize;
        j = mid % matrixColSize;
        if (matrix[i][j] < target)
            low = mid + 1;
        else if (matrix[i][j] > target)
            high = mid - 1;
        else
            return true;
    }
    return false;
}
