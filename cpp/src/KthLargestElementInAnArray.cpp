#include "KthLargestElementInAnArray.h"

using namespace lcpp;

typedef std::vector<int>::size_type SizeType;

static SizeType partition(std::vector<int> &Nums, SizeType I, SizeType J) {
  auto Pivot = Nums[J];
  while (I < J) {
    while (I < J && Nums[I] <= Pivot)
      ++I;
    Nums[J] = Nums[I];
    while (I < J && Nums[J] >= Pivot)
      --J;
    Nums[I] = Nums[J];
  }
  Nums[I] = Pivot;
  return I;
}

static int findKthSmallestFrom0(std::vector<int> &Nums, SizeType I, SizeType J,
                                SizeType K) {
  auto PivotIndex = partition(Nums, I, J);
  if (PivotIndex == K)
    return Nums[PivotIndex];
  if (PivotIndex > K)
    return findKthSmallestFrom0(Nums, I, PivotIndex - 1, K);
  return findKthSmallestFrom0(Nums, PivotIndex + 1, J, K);
}

int Solution215_1::findKthLargest(std::vector<int> &nums, int k) {
  const auto &Size = nums.size();
  assert(0 < k && k <= Size);
  return findKthSmallestFrom0(nums, 0, Size - 1, Size - k);
}
