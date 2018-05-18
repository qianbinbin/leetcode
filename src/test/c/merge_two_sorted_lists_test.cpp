#include <gtest/gtest.h>

extern "C" {
#include <merge_two_sorted_lists.h>
}

TEST(leetcode_21, normal) {
    int nums1[] = {1, 2, 4};
    struct ListNode *l1 = list_from_array(nums1, 3);
    list_print(l1);
    int nums2[] = {1, 3, 4};
    struct ListNode *l2 = list_from_array(nums2, 3);
    list_print(l2);
    struct ListNode *l = mergeTwoLists_21(l1, l2);
    list_print(l);
    list_free(l);
}
