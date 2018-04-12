#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <permutations.h>
}

TEST(leetcode_46, normal) {
    int nums[] = {1, 2, 3};
    int size = 0;
    int **permutations = permute_46(nums, 3, &size);
    for (int i = 0; i < size; ++i) {
        array_print(permutations[i], 3);
        free(permutations[i]);
    }
    free(permutations);
}
