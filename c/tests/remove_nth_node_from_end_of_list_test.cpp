#include <gtest/gtest.h>

extern "C" {
#include "remove_nth_node_from_end_of_list.h"
}

TEST(remove_nth_node_from_end_of_list_test, removeNthFromEnd_19_1) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = list_create(nums, 5);
    list_print(head);
    head = removeNthFromEnd_19_1(head, 2);
    list_print(head);
    list_free(head);
}
