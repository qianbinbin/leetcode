#include <gtest/gtest.h>

extern "C" {
#include <linked_list_cycle.h>
}

TEST(leetcode_141, normal) {
    int nums[] = {1, 2, 3};
    struct ListNode *head = list_create(nums, 3);
    list_print(head);
    EXPECT_FALSE(hasCycle_141(head));
    head->next->next->next = head->next;
    EXPECT_TRUE(hasCycle_141(head));
    head->next->next->next = NULL;
    list_free(head);
}
