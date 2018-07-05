#include "search_a_2d_matrix.h"

#include <stddef.h>

bool searchMatrix_74_1(int **matrix, int matrixRowSize, int matrixColSize, int target) {
    if (matrix == NULL || matrixRowSize < 1 || matrixColSize < 1) return false;

    int begin = 0, end = matrixRowSize * matrixColSize - 1, mid, row, col;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        row = mid / matrixColSize;
        col = mid % matrixColSize;
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}
