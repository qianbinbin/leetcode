#include <gtest/gtest.h>

extern "C" {
#include <group_anagrams.h>
}

TEST(leetcode_49, normal) {
    char a[] = "ate";
    char b[] = "eat";
    char c[] = "tea";
    char d[] = "nat";
    char e[] = "tan";
    char f[] = "bat";
    char *strs[] = {a, b, c, d, e, f};
    int size = 0;
    int **columnSizes = (int **) malloc(sizeof(int *));
    char ***ret = groupAnagrams_49(strs, 6, columnSizes, &size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < (*columnSizes)[i]; ++j) {
            printf("%s ", ret[i][j]);
            free(ret[i][j]);
        }
        printf("\n");
        free(ret[i]);
    }
    free(ret);
    free(columnSizes);
}
