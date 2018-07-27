#include <gtest/gtest.h>

extern "C" {
#include <word_break_ii.h>
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

char *s1 = "catsanddog";
char *dict1[] = {"cat", "cats", "and", "sand", "dog"};

char *s2 = "pineapplepenapple";
char *dict2[] = {"apple", "pen", "applepen", "pine", "pineapple"};

char *s3 = "catsandog";
char *dict3[] = {"cats", "dog", "sand", "and", "cat"};

TEST(word_break_ii_test, wordBreak_140_1) {
    int size1 = 0;
    char **sentences1 = wordBreak_140_1(s1, dict1, ARR_SIZE(dict1), &size1);
    for (int i = 0; i < size1; ++i) {
        puts(sentences1[i]);
        free(sentences1[i]);
    }
    free(sentences1);

    int size2 = 0;
    char **sentences2 = wordBreak_140_1(s2, dict2, ARR_SIZE(dict2), &size2);
    for (int i = 0; i < size2; ++i) {
        puts(sentences2[i]);
        free(sentences2[i]);
    }
    free(sentences2);

    int size3 = 0;
    char **sentences3 = wordBreak_140_1(s3, dict3, ARR_SIZE(dict3), &size3);
    for (int i = 0; i < size3; ++i) {
        puts(sentences3[i]);
        free(sentences3[i]);
    }
    free(sentences3);
}
