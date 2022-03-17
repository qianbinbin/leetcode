#include <gtest/gtest.h>

extern "C" {
#include "sort_list.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(sort_list_test, sortList_148_1) {
    int nums1[] = {4, 2, 1, 3};
    struct ListNode *head1 = list_create(nums1, ARR_SIZE(nums1));
    list_print(head1);
    head1 = sortList_148_1(head1);
    list_print(head1);
    list_free(head1);

    int nums2[] = {-1, 5, 3, 4, 0};
    struct ListNode *head2 = list_create(nums2, ARR_SIZE(nums2));
    list_print(head2);
    head2 = sortList_148_1(head2);
    list_print(head2);
    list_free(head2);

    struct ListNode *head3 = NULL;
    list_print(head3);
    head3 = sortList_148_1(head3);
    list_print(head3);
    list_free(head3);
}
