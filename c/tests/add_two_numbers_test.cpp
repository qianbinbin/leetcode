#include <gtest/gtest.h>

extern "C" {
#include "add_two_numbers.h"
}

TEST(add_two_numbers_test, addTwoNumbers_2_1) {
    int nums1[] = {2, 4, 3};
    struct ListNode *l1 = list_create(nums1, 3);
    list_print(l1);

    int nums2[] = {5, 6, 4};
    struct ListNode *l2 = list_create(nums2, 3);
    list_print(l2);

    struct ListNode *l = addTwoNumbers_2_1(l1, l2);
    list_print(l);

    list_free(l1);
    list_free(l2);
    list_free(l);
}
