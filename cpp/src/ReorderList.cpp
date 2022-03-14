#include "ReorderList.h"

using namespace lcpp;

void Solution143_1::reorderList(ListNode *head) {
  if (head == nullptr)
    return;
  ListNode *Slow = head, *Fast = head;
  while (Fast != nullptr && Fast->next != nullptr) {
    Slow = Slow->next;
    Fast = Fast->next->next;
  }
  ListNode Dummy(0, Slow);
  for (auto P = Slow->next; P != nullptr; P = Slow->next) {
    Slow->next = P->next;
    P->next = Dummy.next;
    Dummy.next = P;
  }
  ListNode *Tail = &Dummy, *P1 = head, *P2 = Dummy.next;
  while (P1 != Slow) {
    Tail = Tail->next = P1;
    P1 = P1->next;
    Tail = Tail->next = P2;
    P2 = P2->next;
  }
}
