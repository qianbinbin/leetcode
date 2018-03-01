#include <gtest/gtest.h>

extern "C" {
#include <linked-list-cycle-ii.h>
}

TEST(leetcode_142, normal) {
    int nums[] = {1, 2, 3};
    struct ListNode *head = array_to_list(nums, 3);
    print_list(head);
    EXPECT_TRUE(detectCycle_142(head) == NULL);
    head->next->next->next = head->next;
    EXPECT_TRUE(detectCycle_142(head) == head->next);
    head->next->next->next = NULL;
    free_list(head);
}
