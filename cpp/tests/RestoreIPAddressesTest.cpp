#include "RestoreIPAddresses.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(RestoreIPAddresses, Solution93_1) {
  auto S93_1 = Solution93_1();

  std::string S1 = "25525511135";
  std::vector<std::string> const Expected1{"255.255.11.135", "255.255.111.35"};
  EXPECT_EQ(Expected1, S93_1.restoreIpAddresses(S1));

  std::string S2 = "0000";
  std::vector<std::string> const Expected2{"0.0.0.0"};
  EXPECT_EQ(Expected2, S93_1.restoreIpAddresses(S2));

  std::string S3 = "101023";
  std::vector<std::string> const Expected3{
      "1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"};
  EXPECT_EQ(Expected3, S93_1.restoreIpAddresses(S3));
}

TEST(RestoreIPAddresses, Solution93_2) {
  auto S93_2 = Solution93_2();

  std::string S1 = "25525511135";
  std::vector<std::string> const Expected1{"255.255.11.135", "255.255.111.35"};
  EXPECT_EQ(Expected1, S93_2.restoreIpAddresses(S1));

  std::string S2 = "0000";
  std::vector<std::string> const Expected2{"0.0.0.0"};
  EXPECT_EQ(Expected2, S93_2.restoreIpAddresses(S2));

  std::string S3 = "101023";
  std::vector<std::string> const Expected3{
      "1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"};
  EXPECT_EQ(Expected3, S93_2.restoreIpAddresses(S3));
}
