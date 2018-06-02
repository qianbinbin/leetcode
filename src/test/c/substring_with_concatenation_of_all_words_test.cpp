#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "substring_with_concatenation_of_all_words.h"
}

TEST(substring_with_concatenation_of_all_words_test, findSubstring_30_1) {
    char *words1[] = {"foo", "bar"};
    int size1 = 0;
    int *result1 = findSubstring_30_1("barfoothefoobarman", words1, 2, &size1);
    array_print(result1, size1);
    free(result1);

    char *words2[] = {"word", "student"};
    int size2 = 0;
    int *result2 = findSubstring_30_1("wordgoodstudentgoodword", words2, 2, &size2);
    array_print(result2, size2);
    free(result2);
}
