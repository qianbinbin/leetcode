#include "MergeSortedArray.h"

using namespace lcpp;

void Solution88_1::merge(std::vector<int> &nums1, int m,
                         std::vector<int> &nums2, int n) {
  const auto &M = nums1.size();
  auto I1 = nums1.rbegin() + M - m, E1 = nums1.rend(), I2 = nums2.rbegin(),
       E2 = nums2.rend(), I = nums1.rbegin() + M - m - n;
  while (I1 != E1 && I2 != E2) {
    if (*I1 >= *I2)
      *I++ = *I1++;
    else
      *I++ = *I2++;
  }
  if (I2 != E2)
    std::copy(I2, E2, I);
}
