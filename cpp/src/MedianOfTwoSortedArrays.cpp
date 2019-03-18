#include "MedianOfTwoSortedArrays.h"
#include <cassert>

using namespace lcpp;

/// Size of Nums1 must be greater than or equal to size of Nums2.
static double findMedian(const std::vector<int> &Nums1,
                         const std::vector<int> &Nums2) {
  const auto &M = Nums1.size(), &N = Nums2.size();
  assert(M + N + 1 > M && "Size overflow!");
  const auto Sum = (M + N + 1) / 2;
  std::vector<int>::size_type Low = 0, High = M, I = 0, J = 0;
  while (Low <= High) {
    I = (Low + High) / 2;
    J = Sum - I;
    if (I > 0 && J < N && Nums1[I - 1] > Nums2[J]) {
      High = I;
    } else if (J > 0 && I < M && Nums2[J - 1] > Nums1[I]) {
      Low = I + 1;
    } else {
      break;
    }
  }

  int Left = I == 0 ? Nums2[J - 1] :
             (J == 0 ? Nums1[I - 1] : std::max(Nums1[I - 1], Nums2[J - 1]));
  if ((M + N) % 2 != 0)
    return Left;
  int Right = I == M ? Nums2[J] :
              (J == N ? Nums1[I] : std::min(Nums1[I], Nums2[J]));
  return (Left + Right) / 2.0;
}

double Solution4_1::findMedianSortedArrays(std::vector<int> &nums1,
                                           std::vector<int> &nums2) {
  assert(!nums1.empty() || !nums2.empty());
  if (nums1.size() > nums2.size())
    return findMedian(nums2, nums1);
  return findMedian(nums1, nums2);
}
