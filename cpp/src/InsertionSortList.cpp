#include "InsertionSortList.h"

using namespace lcpp;

ListNode *Solution147_1::insertionSortList(ListNode *head) {
  ListNode Dummy(0), *Pre, *Node = head, *Next;
  while (Node != nullptr) {
    Next = Node->next;
    Pre = &Dummy;
    while (Pre->next != nullptr && Pre->next->val <= Node->val)
      Pre = Pre->next;
    Node->next = Pre->next;
    Pre->next = Node;
    Node = Next;
  }
  return Dummy.next;
}
