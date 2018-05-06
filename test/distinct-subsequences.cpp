#include <gtest/gtest.h>

extern "C" {
#include <distinct-subsequences.h>
}

TEST(leetcode_115_1, normal) {
    EXPECT_EQ(numDistinct_115_1("rabbbit", "rabbit"), 3);
    EXPECT_EQ(numDistinct_115_1("babgbag", "bag"), 5);
    EXPECT_EQ(numDistinct_115_1(
            "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc",
            "bcddceeeebecbc"), 700531452);
}
