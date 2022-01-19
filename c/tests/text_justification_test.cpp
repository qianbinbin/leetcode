#include <gtest/gtest.h>

extern "C" {
#include "text_justification.h"
}

TEST(text_justification_test, fullJustify_68_1) {
    char *words1[] = {"This", "is", "an", "example", "of", "text",
                      "justification."};
    int const maxWidth1 = 16;
    int returnSize1 = 0;
    std::vector<std::string> expected1{
            "This    is    an",
            "example  of text",
            "justification.  "
    };
    char **actual1 = fullJustify_68_1(words1,
                                      sizeof(words1) / sizeof(words1[0]),
                                      maxWidth1, &returnSize1);
    ASSERT_EQ(expected1.size(), returnSize1);
    for (int i = 0; i < returnSize1; ++i) {
        EXPECT_EQ(expected1[i], actual1[i]);
        free(actual1[i]);
    }
    free(actual1);

    char *words2[] = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int const maxWidth2 = 16;
    int returnSize2 = 0;
    std::vector<std::string> expected2{
            "What   must   be",
            "acknowledgment  ",
            "shall be        "
    };
    char **actual2 = fullJustify_68_1(words2,
                                      sizeof(words2) / sizeof(words2[0]),
                                      maxWidth2, &returnSize2);
    ASSERT_EQ(expected2.size(), returnSize2);
    for (int i = 0; i < returnSize2; ++i) {
        EXPECT_EQ(expected2[i], actual2[i]);
        free(actual2[i]);
    }
    free(actual2);

    char *words3[] = {"Science", "is", "what", "we", "understand", "well",
                      "enough", "to", "explain",
                      "to", "a", "computer.", "Art", "is", "everything", "else",
                      "we", "do"};
    int const maxWidth3 = 20;
    int returnSize3 = 0;
    std::vector<std::string> expected3{
            "Science  is  what we",
            "understand      well",
            "enough to explain to",
            "a  computer.  Art is",
            "everything  else  we",
            "do                  "
    };
    char **actual3 = fullJustify_68_1(words3,
                                      sizeof(words3) / sizeof(words3[0]),
                                      maxWidth3, &returnSize3);
    ASSERT_EQ(expected3.size(), returnSize3);
    for (int i = 0; i < returnSize3; ++i) {
        EXPECT_EQ(expected3[i], actual3[i]);
        free(actual3[i]);
    }
    free(actual3);
}
