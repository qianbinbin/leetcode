#include <gtest/gtest.h>

extern "C" {
#include "reorder_list.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(reorder_list_test, reorderList_143_1) {
    int nums1[] = {1, 2, 3, 4};
    struct ListNode *head1 = list_create(nums1, ARR_SIZE(nums1));
    list_print(head1);
    reorderList_143_1(head1);
    list_print(head1);
    list_free(head1);

    int nums2[] = {1, 2, 3, 4, 5};
    struct ListNode *head2 = list_create(nums2, ARR_SIZE(nums2));
    list_print(head2);
    reorderList_143_1(head2);
    list_print(head2);
    list_free(head2);
}
