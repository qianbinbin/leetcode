#include <gtest/gtest.h>

extern "C" {
#include "reverse_nodes_in_k_group.h"
}

TEST(reverse_nodes_in_k_group_test, reverseKGroup_25_1) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head1 = list_create(nums, 5);
    list_print(head1);
    head1 = reverseKGroup_25_1(head1, 2);
    list_print(head1);
    list_free(head1);

    struct ListNode *head2 = list_create(nums, 5);
    list_print(head2);
    head2 = reverseKGroup_25_1(head2, 3);
    list_print(head2);
    list_free(head2);
}
