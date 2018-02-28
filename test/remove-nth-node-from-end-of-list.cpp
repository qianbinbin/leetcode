#include <gtest/gtest.h>

extern "C" {
#include <remove-nth-node-from-end-of-list.h>
}

TEST(leetcode_19, normal) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = array_to_list(nums, 5);
    print_list(head);
    head = removeNthFromEnd_19(head, 5);
    print_list(head);
    free(head);
}

TEST(leetcode_19, overflow) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = array_to_list(nums, 5);
    print_list(head);
    EXPECT_TRUE(removeNthFromEnd_19(head, 6) == NULL);
    free(head);
}
