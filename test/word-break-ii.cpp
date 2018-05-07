#include <gtest/gtest.h>

extern "C" {
#include <word-break-ii.h>
}

TEST(leetcode_140, normal) {
    int size1 = 0;
    char *dict1[] = {"cat", "cats", "and", "sand", "dog"};
    char **breaks1 = wordBreak_140("catsanddog", dict1, 5, &size1);
    for (int i = 0; i < size1; ++i) {
        puts(breaks1[i]);
        free(breaks1[i]);
    }
    free(breaks1);

    int size2 = 0;
    char *dict2[] = {"apple", "pen", "applepen", "pine", "pineapple"};
    char **breaks2 = wordBreak_140("pineapplepenapple", dict2, 5, &size2);
    for (int i = 0; i < size2; ++i) {
        puts(breaks2[i]);
        free(breaks2[i]);
    }
    free(breaks2);

    int size3 = 0;
    char *dict3[] = {"cats", "dog", "sand", "and", "cat"};
    char **breaks3 = wordBreak_140("catsandog", dict3, 5, &size3);
    for (int i = 0; i < size3; ++i) {
        puts(breaks3[i]);
        free(breaks3[i]);
    }
    free(breaks3);

    int size4 = 0;
    char *dict4[] = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    char **breaks4 = wordBreak_140(
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
            dict4,
            sizeof(dict4) / sizeof(dict4[0]), &size4);
    for (int i = 0; i < size4; ++i) {
        puts(breaks4[i]);
        free(breaks4[i]);
    }
    free(breaks4);
}
