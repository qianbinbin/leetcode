#include <gtest/gtest.h>

extern "C" {
#include <remove-duplicates-from-sorted-list.h>
}

TEST(leetcode_83, normal) {
    int nums[] = {1, 1, 2, 3, 3};
    struct ListNode *head = array_to_list(nums, 5);
    print_list(head);
    deleteDuplicates_83(head);
    print_list(head);
    free_list(head);
}
