#include "GroupAnagrams.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(GroupAnagrams, Solution49_1) {
  std::vector<std::string> Strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  const std::vector<std::vector<std::string>> Expected{
      {"tan", "nat"},
      {"eat", "tea", "ate"},
      {"bat"}
  };
  EXPECT_EQ(Expected, Solution49_1().groupAnagrams(Strs));
}