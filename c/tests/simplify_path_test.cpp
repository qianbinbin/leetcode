#include <gtest/gtest.h>

extern "C" {
#include "simplify_path.h"
}

TEST(simplify_path_test, simplifyPath_71_1) {
    char *actual1 = simplifyPath_71_1("/home/");
    EXPECT_STREQ("/home", actual1);
    free(actual1);

    char *actual2 = simplifyPath_71_1("/../");
    EXPECT_STREQ("/", actual2);
    free(actual2);

    char *actual3 = simplifyPath_71_1("/home//foo/");
    EXPECT_STREQ("/home/foo", actual3);
    free(actual3);
}
