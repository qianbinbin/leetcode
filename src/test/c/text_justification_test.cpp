#include <gtest/gtest.h>

extern "C" {
#include "text_justification.h"
}

TEST(text_justification_test, fullJustify_68_1) {
    char *words1[] = {"This", "is", "an", "example", "of", "text", "justification."};
    int size1 = 0;
    char **out1 = fullJustify_68_1(words1, sizeof(words1) / sizeof(words1[0]), 16, &size1);
    for (int i = 0; i < size1; ++i) {
        puts(out1[i]);
        free(out1[i]);
    }
    free(out1);

    puts("");
    char *words2[] = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int size2 = 0;
    char **out2 = fullJustify_68_1(words2, sizeof(words2) / sizeof(words2[0]), 16, &size2);
    for (int i = 0; i < size2; ++i) {
        puts(out2[i]);
        free(out2[i]);
    }
    free(out2);

    puts("");
    char *words3[] = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
                      "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int size3 = 0;
    char **out3 = fullJustify_68_1(words3, sizeof(words3) / sizeof(words3[0]), 20, &size3);
    for (int i = 0; i < size3; ++i) {
        puts(out3[i]);
        free(out3[i]);
    }
    free(out3);
}
