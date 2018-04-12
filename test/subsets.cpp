#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <subsets.h>
}

TEST(leetcode_78, normal) {
    int nums[] = {1,2,3};
    int *cols = NULL;
    int size = 0;
    int **subsets = subsets_78(nums, 3, &cols, &size);
    for (int i = 0; i < size; ++i) {
        array_print(subsets[i], cols[i]);
        free(subsets[i]);
    }
    free(cols);
    free(subsets);
}
