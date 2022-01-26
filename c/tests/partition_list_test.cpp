#include <gtest/gtest.h>

extern "C" {
#include "partition_list.h"
}

TEST(partition_list_test, partition_86_1) {
    int nums1[] = {1, 4, 3, 2, 5, 2};
    struct ListNode *head1 = list_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    int const x1 = 3;
    list_print(head1);
    head1 = partition_86_1(head1, x1);
    list_print(head1);
    list_free(head1);

    int nums2[] = {2, 1};
    struct ListNode *head2 = list_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    int const x2 = 2;
    list_print(head2);
    head2 = partition_86_1(head2, x2);
    list_print(head2);
    list_free(head2);
}