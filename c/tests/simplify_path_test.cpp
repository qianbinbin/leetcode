#include <gtest/gtest.h>

extern "C" {
#include "simplify_path.h"
}

TEST(simplify_path_test, simplifyPath_71_1) {
    char *path1 = simplifyPath_71_1("/home/");
    EXPECT_STREQ(path1, "/home");
    free(path1);

    char *path2 = simplifyPath_71_1("/a/./b/../../c/");
    EXPECT_STREQ(path2, "/c");
    free(path2);

    char *path3 = simplifyPath_71_1("/../");
    EXPECT_STREQ(path3, "/");
    free(path3);

    char *path4 = simplifyPath_71_1("/home//foo/");
    EXPECT_STREQ(path4, "/home/foo");
    free(path4);
}
