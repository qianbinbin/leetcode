#include <gtest/gtest.h>

extern "C" {
#include "group_anagrams.h"
}

TEST(group_anagrams_test, groupAnagrams_49_1) {
    char *strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int size = 0;
    int *columnSizes = NULL;
    char ***ret = groupAnagrams_49_1(strs, 6, &columnSizes, &size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < columnSizes[i]; ++j) {
            printf("%s ", ret[i][j]);
        }
        printf("\n");
        free(ret[i]);
    }
    free(ret);
    free(columnSizes);
}
