#include <gtest/gtest.h>

extern "C" {
#include "swap_nodes_in_pairs.h"
}

TEST(swap_nodes_in_pairs_test, swapPairs_24_1) {
    int nums1[] = {1, 2, 3, 4};
    int const numsSize1 = 4;
    struct ListNode *head1 = list_create(nums1, numsSize1);
    list_print(head1);
    struct ListNode *actual1 = swapPairs_24_1(head1);
    list_print(actual1);
    list_free(actual1);

    EXPECT_EQ(NULL, swapPairs_24_1(NULL));

    int nums3[] = {1};
    int const numsSize3 = 1;
    struct ListNode *head3 = list_create(nums3, numsSize3);
    list_print(head3);
    struct ListNode *actual3 = swapPairs_24_1(head3);
    list_print(actual3);
    list_free(actual3);
}
