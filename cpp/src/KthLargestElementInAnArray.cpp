#include "KthLargestElementInAnArray.h"
#include <algorithm>

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

int Solution215_2::findKthLargest(std::vector<int> &nums, int k) {
  auto N = nums.size();
  assert(0 < k && k <= N);
  if (N - k >= k) {
    std::make_heap(nums.begin(), nums.end());
    for (auto HeapEnd = nums.end(); k != 1; --k)
      std::pop_heap(nums.begin(), HeapEnd--);
  } else {
    std::make_heap(nums.begin(), nums.end(), std::greater<int>());
    for (auto HeapEnd = nums.end(); N != k; --N)
      std::pop_heap(nums.begin(), HeapEnd--, std::greater<int>());
  }
  return nums[0];
}
