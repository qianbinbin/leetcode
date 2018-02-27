#include <gtest/gtest.h>

extern "C" {
#include <common.h>
#include <add-two-numbers.h>
}

TEST(leetcode_2, normal) {
    int nums1[] = {2, 4, 3};
    struct ListNode *l1 = array_to_list(nums1, 3);
    print_list(l1);

    int nums2[] = {5, 6, 4};
    struct ListNode *l2 = array_to_list(nums2, 3);
    print_list(l2);

    struct ListNode *l = addTwoNumbers_2(l1, l2);
    print_list(l);

    free_list(l1);
    free_list(l2);
    free_list(l);
}
