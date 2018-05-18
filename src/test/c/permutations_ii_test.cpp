#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <permutations_ii.h>
}

TEST(leetcode_47, normal) {
    int nums[] = {1, 1, 2};
    int size = 0;
    int **permutations = permuteUnique_47(nums, 3, &size);
    for (int i = 0; i < size; ++i) {
        array_print(permutations[i], 3);
        free(permutations[i]);
    }
    free(permutations);
}
