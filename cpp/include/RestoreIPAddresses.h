// Given a string containing only digits, restore it by returning all possible
// valid IP address combinations.
//
// Example:
//
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]

#ifndef LEETCODECPP_RESTOREIPADDRESSES_H
#define LEETCODECPP_RESTOREIPADDRESSES_H

#include <string>
#include <vector>

namespace lcpp {

class Solution93_1 {
public:
  std::vector<std::string> restoreIpAddresses(std::string s);
};

}

#endif //LEETCODECPP_RESTOREIPADDRESSES_H
