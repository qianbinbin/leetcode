#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <add-two-numbers.h>
}

TEST(leetcode_2, normal) {
    int nums1[] = {2, 4, 3};
    struct ListNode *l1 = list_from_array(nums1, 3);
    list_print(l1);

    int nums2[] = {5, 6, 4};
    struct ListNode *l2 = list_from_array(nums2, 3);
    list_print(l2);

    struct ListNode *l = addTwoNumbers_2(l1, l2);
    list_print(l);

    list_free(l1);
    list_free(l2);
    list_free(l);
}
