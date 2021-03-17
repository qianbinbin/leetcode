#include <gtest/gtest.h>

extern "C" {
#include "reverse_nodes_in_k_group.h"
}

TEST(reverse_nodes_in_k_group_test, reverseKGroup_25_1) {
    int nums1[] = {1, 2, 3, 4, 5};
    int const numsSize1 = 5;
    struct ListNode *head1 = list_create(nums1, numsSize1);
    int const k1 = 2;
    list_print(head1);
    struct ListNode *actual1 = reverseKGroup_25_1(head1, k1);
    list_print(actual1);
    list_free(actual1);

    int nums2[] = {1, 2, 3, 4, 5};
    int const numsSize2 = 5;
    struct ListNode *head2 = list_create(nums2, numsSize2);
    int const k2 = 3;
    list_print(head2);
    struct ListNode *actual2 = reverseKGroup_25_1(head2, k2);
    list_print(actual2);
    list_free(actual2);

    int nums3[] = {1, 2, 3, 4, 5};
    int const numsSize3 = 5;
    struct ListNode *head3 = list_create(nums3, numsSize3);
    int const k3 = 1;
    list_print(head3);
    struct ListNode *actual3 = reverseKGroup_25_1(head3, k3);
    list_print(actual3);
    list_free(actual3);

    int nums4[] = {1};
    int const numsSize4 = 1;
    struct ListNode *head4 = list_create(nums4, numsSize4);
    int const k4 = 1;
    list_print(head4);
    struct ListNode *actual4 = reverseKGroup_25_1(head4, k4);
    list_print(actual4);
    list_free(actual4);
}
