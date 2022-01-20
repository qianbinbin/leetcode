#include "SimplifyPath.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SimplifyPath, Solution71_1) {
  auto S71_1 = Solution71_1();

  EXPECT_EQ("/home", S71_1.simplifyPath("/home/"));
  EXPECT_EQ("/", S71_1.simplifyPath("/../"));
  EXPECT_EQ("/home/foo", S71_1.simplifyPath("/home//foo/"));
}
