#include <gtest/gtest.h>

extern "C" {
#include "merge_two_sorted_lists.h"
}

TEST(merge_two_sorted_lists_test, mergeTwoLists_21_1) {
    int nums11[] = {1, 2, 4}, nums12[] = {1, 3, 4};
    int const numsSize11 = 3, numsSize12 = 3;
    struct ListNode *l11 = list_create(nums11, numsSize11),
            *l12 = list_create(nums12, numsSize12);
    struct ListNode *actual1 = mergeTwoLists_21_1(l11, l12);
    list_print(l11);
    list_print(l12);
    list_print(actual1);
    list_free(actual1);

    EXPECT_EQ(NULL, mergeTwoLists_21_1(NULL, NULL));

    int nums32[] = {0};
    int const numsSize32 = 1;
    struct ListNode *l32 = list_create(nums32, numsSize32);
    struct ListNode *actual3 = mergeTwoLists_21_1(NULL, l32);
    list_print(l32);
    list_print(actual3);
    list_free(actual3);
}
