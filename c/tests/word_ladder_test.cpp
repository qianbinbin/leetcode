#include <gtest/gtest.h>

extern "C" {
#include "word_ladder.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(word_ladder_test, ladderLength_127_1) {
    char *wordList1[] = {"hot", "dot", "dog", "lot", "log", "cog"};
    EXPECT_EQ(5,
              ladderLength_127_1("hit", "cog", wordList1, ARR_SIZE(wordList1)));

    char *wordList2[] = {"hot", "dot", "dog", "lot", "log"};
    EXPECT_EQ(0,
              ladderLength_127_1("hit", "cog", wordList2, ARR_SIZE(wordList2)));
}
