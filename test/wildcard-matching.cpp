#include <gtest/gtest.h>

extern "C" {
#include <wildcard-matching.h>
}

TEST(leetcode_44, normal) {
    EXPECT_FALSE(isMatch_44("aa", "a"));
    EXPECT_TRUE(isMatch_44("aa", "aa"));
    EXPECT_FALSE(isMatch_44("aaa", "aa"));
    EXPECT_TRUE(isMatch_44("aa", "*"));
    EXPECT_TRUE(isMatch_44("aa", "a*"));
    EXPECT_TRUE(isMatch_44("ab", "?*"));
    EXPECT_FALSE(isMatch_44("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"));
    EXPECT_FALSE(isMatch_44(
            "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
            "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"));
}