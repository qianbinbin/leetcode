#include <gtest/gtest.h>

extern "C" {
#include <reorder_list.h>
}

TEST(leetcode_143, normal) {
    int nums[] = {1, 2, 3, 4};
    struct ListNode *head = list_create(nums, 4);
    list_print(head);
    reorderList_143(head);
    list_print(head);
    list_free(head);
}
