#include <gtest/gtest.h>

extern "C" {
#include <rotate-list.h>
}

TEST(leetcode_61, normal) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = list_from_array(nums, 5);
    list_print(head);
    head = rotateRight_61(head, 7);
    list_print(head);
    list_free(head);
}
