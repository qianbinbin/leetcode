#include <gtest/gtest.h>

extern "C" {
#include <remove-nth-node-from-end-of-list.h>
}

TEST(leetcode_19, normal) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = list_from_array(nums, 5);
    list_print(head);
    head = removeNthFromEnd_19(head, 5);
    list_print(head);
    free(head);
}

TEST(leetcode_19, overflow) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = list_from_array(nums, 5);
    list_print(head);
    EXPECT_TRUE(removeNthFromEnd_19(head, 6) == NULL);
    free(head);
}
