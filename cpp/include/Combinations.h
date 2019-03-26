// Given two integers n and k, return all possible combinations of k numbers out
// of 1 ... n.
//
// Example:
//
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#ifndef LEETCODECPP_COMBINATIONS_H
#define LEETCODECPP_COMBINATIONS_H

#include <vector>

namespace lcpp {

class Solution77_1 {
public:
  std::vector<std::vector<int>> combine(int n, int k);
};

}

#endif //LEETCODECPP_COMBINATIONS_H
