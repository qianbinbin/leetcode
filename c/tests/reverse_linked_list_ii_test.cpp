#include <gtest/gtest.h>

extern "C" {
#include "reverse_linked_list_ii.h"
}

TEST(reverse_linked_list_ii_test, reverseBetween_92_1) {
    int nums1[] = {1, 2, 3, 4, 5};
    struct ListNode *head1 = list_create(nums1,
                                         sizeof(nums1) / sizeof(nums1[0]));
    list_print(head1);
    head1 = reverseBetween_92_1(head1, 2, 4);
    list_print(head1);
    list_free(head1);

    int nums2[] = {5};
    struct ListNode *head2 = list_create(nums2,
                                         sizeof(nums2) / sizeof(nums2[0]));
    list_print(head2);
    head2 = reverseBetween_92_1(head2, 1, 1);
    list_print(head2);
    list_free(head2);
}
