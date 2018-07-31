#include <gtest/gtest.h>

extern "C" {
#include "swap_nodes_in_pairs.h"
}

TEST(swap_nodes_in_pairs_test, swapPairs_24_1) {
    int nums[] = {1, 2, 3, 4};
    struct ListNode *head = list_create(nums, 4);
    list_print(head);
    head = swapPairs_24_1(head);
    list_print(head);
    list_free(head);
}
