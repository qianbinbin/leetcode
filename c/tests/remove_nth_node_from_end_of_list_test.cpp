#include <gtest/gtest.h>

extern "C" {
#include "remove_nth_node_from_end_of_list.h"
}

TEST(remove_nth_node_from_end_of_list_test, removeNthFromEnd_19_1) {
    int nums1[] = {1, 2, 3, 4, 5};
    int const numsSize1 = 5;
    int const n1 = 2;
    struct ListNode *head1 = list_create(nums1, numsSize1);
    list_print(head1);
    struct ListNode *actual1 = removeNthFromEnd_19_1(head1, n1);
    list_print(actual1);
    list_free(actual1);

    int nums2[] = {1};
    int const numsSize2 = 1;
    int const n2 = 1;
    struct ListNode *head2 = list_create(nums2, numsSize2);
    list_print(head2);
    struct ListNode *actual2 = removeNthFromEnd_19_1(head2, n2);
    EXPECT_EQ(NULL, actual2);

    int nums3[] = {1, 2};
    int const numsSize3 = 2;
    int const n3 = 1;
    struct ListNode *head3 = list_create(nums3, numsSize3);
    list_print(head3);
    struct ListNode *actual3 = removeNthFromEnd_19_1(head3, n3);
    list_print(actual3);
    list_free(actual3);
}
