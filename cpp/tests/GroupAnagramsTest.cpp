#include "GroupAnagrams.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(GroupAnagrams, Solution49_1) {
  auto S49_1 = Solution49_1();

  std::vector<std::string> Strs1{"eat", "tea", "tan", "ate", "nat", "bat"};
  std::vector<std::vector<std::string>> const Expected1{
      {"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}};
  EXPECT_EQ(Expected1, S49_1.groupAnagrams(Strs1));

  std::vector<std::string> Strs2{""};
  std::vector<std::vector<std::string>> const Expected2{{""}};
  EXPECT_EQ(Expected2, S49_1.groupAnagrams(Strs2));

  std::vector<std::string> Strs3{"a"};
  std::vector<std::vector<std::string>> const Expected3{{"a"}};
  EXPECT_EQ(Expected3, S49_1.groupAnagrams(Strs3));
}
