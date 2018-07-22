#include <gtest/gtest.h>

extern "C" {
#include "word_ladder_ii.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(word_ladder_ii_test, findLadders_126_1) {
    char *list1[] = {"hot", "dot", "dog", "lot", "log", "cog"};
    int size1 = 0;
    int *col_sizes1 = NULL;
    char ***ladders1 = findLadders_126_1("hit", "cog", list1, ARR_SIZE(list1), &col_sizes1, &size1);
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < col_sizes1[i]; ++j) {
            if (j == col_sizes1[i] - 1)
                printf("%s\n", ladders1[i][j]);
            else
                printf("%s, ", ladders1[i][j]);
        }
        free(ladders1[i]);
    }
    free(col_sizes1);

    char *list2[] = {"hot", "dot", "dog", "lot", "log"};
    int size2 = 0;
    int *col_sizes2 = NULL;
    char ***ladders2 = findLadders_126_1("hit", "cog", list2, 6, &col_sizes2, &size2);
    for (int i = 0; i < size2; ++i) {
        for (int j = 0; j < col_sizes2[i]; ++j) {
            if (j == col_sizes2[i] - 1)
                printf("%s\n", ladders2[i][j]);
            else
                printf("%s, ", ladders2[i][j]);
        }
        free(ladders2[i]);
    }
    free(col_sizes2);
}
