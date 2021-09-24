#include <gtest/gtest.h>

extern "C" {
#include "rotate_list.h"
}

TEST(rotate_list_test, list_create) {
    int nums1[] = {1, 2, 3, 4, 5};
    struct ListNode *head1 = list_create(nums1, 5);
    int const k1 = 2;
    list_print(head1);
    head1 = rotateRight_61_1(head1, k1);
    list_print(head1);
    list_free(head1);

    int nums2[] = {0, 1, 2};
    struct ListNode *head2 = list_create(nums2, 3);
    int const k2 = 4;
    list_print(head2);
    head2 = rotateRight_61_1(head2, k2);
    list_print(head2);
    list_free(head2);
}
