#include <gtest/gtest.h>

extern "C" {
#include "remove_duplicates_from_sorted_list_ii.h"
}

TEST(remove_duplicates_from_sorted_list_ii_test, deleteDuplicates_82_1) {
    int nums1[] = {1, 2, 3, 3, 4, 4, 5};
    struct ListNode *head1 = list_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    list_print(head1);
    head1 = deleteDuplicates_82_1(head1);
    list_print(head1);
    list_free(head1);

    int nums2[] = {1, 1, 1, 2, 3};
    struct ListNode *head2 = list_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    list_print(head2);
    head2 = deleteDuplicates_82_1(head2);
    list_print(head2);
    list_free(head2);
}
