#include "PalindromeLinkedList.h"
#include <vector>

using namespace lcpp;

template <typename T> static bool isPalindrome(const std::vector<T> &Values) {
  for (typename std::vector<T>::size_type I = 0, E = Values.size(), H = E / 2;
       I != H; ++I) {
    if (Values[I] != Values[E - I - 1])
      return false;
  }
  return true;
}

bool Solution234_1::isPalindrome(ListNode *head) {
  std::vector<int> Values;
  for (auto Node = head; Node != nullptr; Node = Node->next)
    Values.push_back(Node->val);
  return ::isPalindrome(Values);
}

static bool isPalindrome(ListNode *Last, ListNode *&First) {
  if (Last == nullptr)
    return true;
  bool Result = isPalindrome(Last->next, First) && Last->val == First->val;
  First = First->next;
  return Result;
}

bool Solution234_2::isPalindrome(ListNode *head) {
  ListNode *First = head;
  return ::isPalindrome(head, First);
}
