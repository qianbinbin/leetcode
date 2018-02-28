#include <gtest/gtest.h>

extern "C" {
#include <remove-duplicates-from-sorted-list-ii.h>
}

TEST(leetcode_82, normal) {
    int nums[] = {1, 1, 1, 2, 2, 2, 3, 4, 5, 5, 5};
    struct ListNode *head = array_to_list(nums, 11);
    print_list(head);
    head = deleteDuplicates_82(head);
    print_list(head);
    free_list(head);
}
