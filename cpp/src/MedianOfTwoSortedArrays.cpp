#include "MedianOfTwoSortedArrays.h"

using namespace lcpp;

/// Size of Nums1 must be less than or equal to size of Nums2.
static double findMedian(const std::vector<int> &Nums1,
                         const std::vector<int> &Nums2) {
  const auto &M = Nums1.size(), &N = Nums2.size();
  const auto Sum = (M + N + 1) / 2;
  std::vector<int>::size_type Low = 0, High = M, I = 0, J = 0;
  while (Low <= High) {
    I = Low + (High - Low) / 2;
    J = Sum - I;
    if (I > 0 && J < N && Nums1[I - 1] > Nums2[J]) {
      High = I - 1;
    } else if (J > 0 && I < M && Nums2[J - 1] > Nums1[I]) {
      Low = I + 1;
    } else {
      break;
    }
  }

  int Left;
  if (I == 0)
    Left = Nums2[J - 1];
  else if (J == 0)
    Left = Nums1[I - 1];
  else
    Left = std::max(Nums1[I - 1], Nums2[J - 1]);
  if ((M + N) % 2 != 0)
    return Left;
  int Right;
  if (I == M)
    Right = Nums2[J];
  else if (J == N)
    Right = Nums1[I];
  else
    Right = std::min(Nums1[I], Nums2[J]);
  return (Left + Right) / 2.0;
}

double Solution4_1::findMedianSortedArrays(std::vector<int> &nums1,
                                           std::vector<int> &nums2) {
  return nums1.size() <= nums2.size() ? findMedian(nums1, nums2)
                                      : findMedian(nums2, nums1);
}
