#include <gtest/gtest.h>

extern "C" {
#include "merge_k_sorted_lists.h"
}

TEST(merge_k_sorted_lists_test, mergeKLists_23_1) {
    struct ListNode *lists[3];
    int nums1[] = {1, 4, 5};
    int nums2[] = {1, 3, 4};
    int nums3[] = {2, 6};
    lists[0] = list_create(nums1, 3);
    lists[1] = list_create(nums2, 3);
    lists[2] = list_create(nums3, 2);
    struct ListNode *list = mergeKLists_23_1(lists, 3);
    list_print(list);
    list_free(list);
}
