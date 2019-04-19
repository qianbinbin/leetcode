#include "ReverseLinkedList.h"

using namespace lcpp;

ListNode *Solution206_1::reverseList(ListNode *head) {
  ListNode Dummy(0), *Node;
  while (head != nullptr) {
    Node = head->next;
    head->next = Dummy.next;
    Dummy.next = head;
    head = Node;
  }
  return Dummy.next;
}
