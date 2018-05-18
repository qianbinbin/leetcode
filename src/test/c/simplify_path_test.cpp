#include <gtest/gtest.h>

extern "C" {
#include <simplify_path.h>
}

TEST(leetcode_71, normal) {
    char *ret = simplifyPath_71("/a/./b/../../c/");
    EXPECT_STREQ(ret, "/c");
    free(ret);
    ret = simplifyPath_71("/home/");
    EXPECT_STREQ(ret, "/home");
    free(ret);
    ret = simplifyPath_71("/../../..");
    EXPECT_STREQ(ret, "/");
    free(ret);
    ret = simplifyPath_71("/home//foo/");
    EXPECT_STREQ(ret, "/home/foo");
    free(ret);
}
