#include <gtest/gtest.h>

extern "C" {
#include <reverse_nodes_in_k_group.h>
}

TEST(leetcode_25, normal) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = list_create(nums, 5);
    list_print(head);
    head = reverseKGroup_25(head, 2);
    list_print(head);
    list_free(head);
}
