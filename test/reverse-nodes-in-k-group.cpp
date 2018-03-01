#include <gtest/gtest.h>

extern "C" {
#include <reverse-nodes-in-k-group.h>
}

TEST(leetcode_25, normal) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = array_to_list(nums, 5);
    print_list(head);
    head = reverseKGroup_25(head, 2);
    print_list(head);
    free_list(head);
}
