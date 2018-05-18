#include <gtest/gtest.h>

extern "C" {
#include <merge_k_sorted_lists.h>
}

TEST(leetcode_23, normal) {
    struct ListNode *lists[5];
    int nums1[] = {0, 2, 4, 6};
    int nums2[] = {1, 3, 5, 7, 9};
    int nums3[] = {2, 5, 7};
    lists[0] = list_from_array(nums1, 4);
    lists[1] = list_from_array(nums2, 5);
    lists[2] = list_from_array(nums3, 3);
    struct ListNode *list = mergeKLists_23(lists, 3);
    list_print(list);
    list_free(list);
}
