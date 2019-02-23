#include "SimplifyPath.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SimplifyPath, Solution71_1) {
  EXPECT_EQ("/home", Solution71_1().simplifyPath("/home/"));
  EXPECT_EQ("/", Solution71_1().simplifyPath("/../"));
  EXPECT_EQ("/home/foo", Solution71_1().simplifyPath("/home//foo/"));
  EXPECT_EQ("/c", Solution71_1().simplifyPath("/a/./b/../../c/"));
  EXPECT_EQ("/c", Solution71_1().simplifyPath("/a/../../b/../c//.//"));
  EXPECT_EQ("/a/b/c", Solution71_1().simplifyPath("/a//b////c/d//././/.."));
}
