#include <gtest/gtest.h>

extern "C" {
#include <reorder-list.h>
}

TEST(leetcode_143, normal) {
    int nums[] = {1, 2, 3, 4};
    struct ListNode *head = array_to_list(nums, 4);
    print_list(head);
    reorderList_143(head);
    print_list(head);
    free_list(head);
}
