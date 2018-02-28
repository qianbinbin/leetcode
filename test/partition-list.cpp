#include <gtest/gtest.h>

extern "C" {
#include <partition-list.h>
}

TEST(leetcode_86, normal) {
    int nums[] = {1, 4, 3, 2, 5, 2};
    struct ListNode *head = array_to_list(nums, 6);
    print_list(head);
    head = partition_86(head, 3);
    print_list(head);
    free_list(head);
}