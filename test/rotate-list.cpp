#include <gtest/gtest.h>

extern "C" {
#include <rotate-list.h>
}

TEST(leetcode_61, normal) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = array_to_list(nums, 5);
    print_list(head);
    head = rotateRight_61(head, 7);
    print_list(head);
    free_list(head);
}
