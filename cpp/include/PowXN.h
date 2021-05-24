// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
//
//
//
// Example 1:
//
// Input: x = 2.00000, n = 10
// Output: 1024.00000
//
// Example 2:
//
// Input: x = 2.10000, n = 3
// Output: 9.26100
//
// Example 3:
//
// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
//
//
// Constraints:
//
//  -100.0 < x < 100.0
//  -2^31 <= n <= 2^31-1
//  -10^4 <= x^n <= 10^4

#ifndef LEETCODECPP_POWXN_H
#define LEETCODECPP_POWXN_H

namespace lcpp {

class Solution50_1 {
public:
  double myPow(double x, int n);
};

} // namespace lcpp

#endif // LEETCODECPP_POWXN_H
