#include <gtest/gtest.h>

extern "C" {
#include "word_ladder.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(word_ladder_test, ladderLength_127_1) {
    char *list1[] = {"hot", "dot", "dog", "lot", "log", "cog"};
    EXPECT_EQ(ladderLength_127_1("hit", "cog", list1, ARR_SIZE(list1)), 5);

    char *list2[] = {"hot", "dot", "dog", "lot", "log"};
    EXPECT_EQ(ladderLength_127_1("hit", "cog", list2, ARR_SIZE(list2)), 0);
}
