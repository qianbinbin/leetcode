#include <gtest/gtest.h>

extern "C" {
#include <partition-list.h>
}

TEST(leetcode_86, normal) {
    int nums[] = {1, 4, 3, 2, 5, 2};
    struct ListNode *head = list_from_array(nums, 6);
    list_print(head);
    head = partition_86(head, 3);
    list_print(head);
    list_free(head);
}