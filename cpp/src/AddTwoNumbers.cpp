#include "AddTwoNumbers.h"

using namespace lcpp;

ListNode *Solution2_1::addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode Dummy(0), *Tail = &Dummy;
  int Sum, Carry = 0;
  for (; l1 != nullptr && l2 != nullptr; l1 = l1->next, l2 = l2->next) {
    Sum = Carry + l1->val + l2->val;
    Carry = Sum / 10;
    Tail->next = new ListNode(Sum % 10);
    Tail = Tail->next;
  }
  for (; l1 != nullptr; l1 = l1->next) {
    Sum = Carry + l1->val;
    Carry = Sum / 10;
    Tail->next = new ListNode(Sum % 10);
    Tail = Tail->next;
  }
  for (; l2 != nullptr; l2 = l2->next) {
    Sum = Carry + l2->val;
    Carry = Sum / 10;
    Tail->next = new ListNode(Sum % 10);
    Tail = Tail->next;
  }
  if (Carry != 0)
    Tail->next = new ListNode(Carry);
  return Dummy.next;
}
