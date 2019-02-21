#include "RotateList.h"
#include <cassert>

using namespace lcpp;

ListNode *Solution61_1::rotateRight(ListNode *head, int k) {
  assert(k >= 0 && "k must be non-negative!");
  if (head == nullptr || k == 0)
    return head;
  int Size = 0;
  for (auto P = head; P != nullptr; P = P->next)
    ++Size;
  k %= Size;
  ListNode *Slow = head, *Fast = head;
  while (k-- != 0)
    Fast = Fast->next;
  while (Fast->next != nullptr) {
    Slow = Slow->next;
    Fast = Fast->next;
  }
  Fast->next = head;
  head = Slow->next;
  Slow->next = nullptr;
  return head;
}
