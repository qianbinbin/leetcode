#include "InsertionSortList.h"

using namespace lcpp;

ListNode *Solution147_1::insertionSortList(ListNode *head) {
  ListNode Dummy(0), *Pre, *P, *N = head, *NN;
  while (N != nullptr) {
    Pre = &Dummy;
    while ((P = Pre->next) != nullptr && P->val <= N->val)
      Pre = P;
    NN = N->next;
    N->next = P;
    Pre->next = N;
    N = NN;
  }
  return Dummy.next;
}
