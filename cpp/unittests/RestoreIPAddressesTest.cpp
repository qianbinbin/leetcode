#include "RestoreIPAddresses.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RestoreIPAddresses, Solution93_1) {
  const std::string S = "25525511135";
  const std::vector<std::string> Expected{
      "255.255.11.135", "255.255.111.35"
  };
  EXPECT_EQ(Expected, Solution93_1().restoreIpAddresses(S));
}