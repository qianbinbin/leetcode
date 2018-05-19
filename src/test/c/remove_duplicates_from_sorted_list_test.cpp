#include <gtest/gtest.h>

extern "C" {
#include <remove_duplicates_from_sorted_list.h>
}

TEST(leetcode_83, normal) {
    int nums[] = {1, 1, 2, 3, 3};
    struct ListNode *head = list_create(nums, 5);
    list_print(head);
    deleteDuplicates_83(head);
    list_print(head);
    list_free(head);
}
