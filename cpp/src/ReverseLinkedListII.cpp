#include "ReverseLinkedListII.h"
#include <cassert>

using namespace lcpp;

ListNode *Solution92_1::reverseBetween(ListNode *head, int m, int n) {
  assert(1 <= m && m <= n);
  ListNode Dummy(0), *Tail = &Dummy;
  Dummy.next = head;
  int I = 1;
  for (; I != m; ++I)
    Tail = Tail->next;
  auto First = Tail->next, P = First->next;
  for (; I != n; ++I) {
    First->next = P->next;
    P->next = Tail->next;
    Tail->next = P;
    P = First->next;
  }
  return Dummy.next;
}
