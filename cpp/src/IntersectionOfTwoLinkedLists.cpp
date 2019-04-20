#include "IntersectionOfTwoLinkedLists.h"

using namespace lcpp;

ListNode *Solution160_1::getIntersectionNode(ListNode *headA, ListNode *headB) {
  auto N1 = headA, N2 = headB;
  while (N1 != N2) {
    N1 = N1 == nullptr ? headB : N1->next;
    N2 = N2 == nullptr ? headA : N2->next;
  }
  return N1;
}
