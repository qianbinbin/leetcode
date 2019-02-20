#include "ListNode.h"

using namespace lcpp;

ListNode *lcpp::newLinkedList(std::initializer_list<int> List) {
  if (List.size() == 0)
    return nullptr;
  auto I = List.begin(), E = List.end();
  auto Head = new ListNode(*I++), Tail = Head;
  while (I != E) {
    Tail->next = new ListNode(*I++);
    Tail = Tail->next;
  }
  return Head;
}

void lcpp::deleteLinkedList(ListNode *Head) {
  ListNode *Pre;
  while (Head != nullptr) {
    Pre = Head;
    Head = Pre->next;
    delete Pre;
  }
}
