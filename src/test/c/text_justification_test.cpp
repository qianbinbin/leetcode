#include <gtest/gtest.h>

extern "C" {
#include <text_justification.h>
}

TEST(leetcode_68, normal_1) {
    char *words[] = {"This", "is", "an", "example", "of", "text", "justification."};
    int size = 0;
    char **out = fullJustify_68(words, sizeof(words) / sizeof(words[0]), 16, &size);
    for (int i = 0; i < size; ++i) {
        puts(out[i]);
        free(out[i]);
    }
    free(out);
}

TEST(leetcode_68, normal_2) {
    char *words[] = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int size = 0;
    char **out = fullJustify_68(words, sizeof(words) / sizeof(words[0]), 16, &size);
    for (int i = 0; i < size; ++i) {
        puts(out[i]);
        free(out[i]);
    }
    free(out);
}

TEST(leetcode_68, normal_3) {
    char *words[] = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
                     "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int size = 0;
    char **out = fullJustify_68(words, sizeof(words) / sizeof(words[0]), 20, &size);
    for (int i = 0; i < size; ++i) {
        puts(out[i]);
        free(out[i]);
    }
    free(out);
}
