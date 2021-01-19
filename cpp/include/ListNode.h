#ifndef LEETCODECPP_LISTNODE_H
#define LEETCODECPP_LISTNODE_H

#include <initializer_list>

namespace lcpp {

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *newLinkedList(std::initializer_list<int> List);

void deleteLinkedList(ListNode *Head);

inline bool listEqual(const ListNode *Head1, const ListNode *Head2) {
  if (Head1 == Head2)
    return true;
  while (Head1 != nullptr && Head2 != nullptr && Head1->val == Head2->val) {
    Head1 = Head1->next;
    Head2 = Head2->next;
  }
  return Head1 == nullptr && Head2 == nullptr;
}

inline bool operator==(const ListNode &Head1, const ListNode &Head2) {
  return listEqual(&Head1, &Head2);
}

} // namespace lcpp

#endif // LEETCODECPP_LISTNODE_H
