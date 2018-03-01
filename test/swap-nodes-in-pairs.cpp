#include <gtest/gtest.h>

extern "C" {
#include <swap-nodes-in-pairs.h>
}

TEST(leetcode_24, normal) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = array_to_list(nums, 5);
    print_list(head);
    head = swapPairs_24(head);
    print_list(head);
    free_list(head);
}
