#include <gtest/gtest.h>

extern "C" {
#include <swap_nodes_in_pairs.h>
}

TEST(leetcode_24, normal) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *head = list_from_array(nums, 5);
    list_print(head);
    head = swapPairs_24(head);
    list_print(head);
    list_free(head);
}
