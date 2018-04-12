#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <subsets-ii.h>
}

TEST(leetcode_90, normal) {
    int nums[] = {1, 2, 2};
    int size = 0;
    int *cols = NULL;
    int **subsets = subsetsWithDup_90(nums, 3, &cols, &size);
    for (int i = 0; i < size; ++i) {
        array_print(subsets[i], cols[i]);
        free(subsets[i]);
    }
    free(cols);
    free(subsets);
}
