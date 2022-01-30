#include "ReverseLinkedListII.h"

using namespace lcpp;

ListNode *Solution92_1::reverseBetween(ListNode *head, int left, int right) {
  ListNode Dummy(0, head), *Tail = &Dummy;
  for (int I = 1; I != left; ++I)
    Tail = Tail->next;
  ListNode *First = Tail->next, *P;
  for (int I = left; I != right; ++I) {
    P = First->next;
    First->next = P->next;
    P->next = Tail->next;
    Tail->next = P;
  }
  return Dummy.next;
}
