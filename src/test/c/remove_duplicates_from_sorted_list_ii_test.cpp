#include <gtest/gtest.h>

extern "C" {
#include <remove_duplicates_from_sorted_list_ii.h>
}

TEST(leetcode_82, normal) {
    int nums[] = {1, 1, 1, 2, 2, 2, 3, 4, 5, 5, 5};
    struct ListNode *head = list_create(nums, 11);
    list_print(head);
    head = deleteDuplicates_82(head);
    list_print(head);
    list_free(head);
}