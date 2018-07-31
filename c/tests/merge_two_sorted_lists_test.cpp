#include <gtest/gtest.h>

extern "C" {
#include "merge_two_sorted_lists.h"
}

TEST(merge_two_sorted_lists_test, mergeTwoLists_21_1) {
    int nums1[] = {1, 2, 4};
    struct ListNode *l1 = list_create(nums1, 3);
    list_print(l1);
    int nums2[] = {1, 3, 4};
    struct ListNode *l2 = list_create(nums2, 3);
    list_print(l2);
    struct ListNode *l = mergeTwoLists_21_1(l1, l2);
    list_print(l);
    list_free(l);
    list_free(l1);
    list_free(l2);
}
