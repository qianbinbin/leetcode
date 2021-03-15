#include <gtest/gtest.h>

extern "C" {
#include "merge_k_sorted_lists.h"
}

TEST(merge_k_sorted_lists_test, mergeKLists_23_1) {
    int nums11[] = {1, 4, 5}, numsSize11 = 3;
    int nums12[] = {1, 3, 4}, numsSize12 = 3;
    int nums13[] = {2, 6}, numsSize13 = 2;
    struct ListNode *lists1[] = {
            list_create(nums11, numsSize11),
            list_create(nums12, numsSize12),
            list_create(nums13, numsSize13)
    };
    int const listSize1 = 3;
    struct ListNode *actual1 = mergeKLists_23_1(lists1, listSize1);
    list_print(actual1);
    list_free(actual1);

    struct ListNode *lists2[] = {};
    int const listSize2 = 0;
    struct ListNode *actual2 = mergeKLists_23_1(lists2, listSize2);
    EXPECT_EQ(NULL, actual2);

    struct ListNode *lists3[] = {NULL};
    int const listSize3 = 1;
    struct ListNode *actual3 = mergeKLists_23_1(lists3, listSize3);
    EXPECT_EQ(NULL, actual3);
}

TEST(merge_k_sorted_lists_test, mergeKLists_23_2) {
    int nums11[] = {1, 4, 5}, numsSize11 = 3;
    int nums12[] = {1, 3, 4}, numsSize12 = 3;
    int nums13[] = {2, 6}, numsSize13 = 2;
    struct ListNode *lists1[] = {
            list_create(nums11, numsSize11),
            list_create(nums12, numsSize12),
            list_create(nums13, numsSize13)
    };
    int const listSize1 = 3;
    struct ListNode *actual1 = mergeKLists_23_2(lists1, listSize1);
    list_print(actual1);
    list_free(actual1);

    struct ListNode *lists2[] = {};
    int const listSize2 = 0;
    struct ListNode *actual2 = mergeKLists_23_2(lists2, listSize2);
    EXPECT_EQ(NULL, actual2);

    struct ListNode *lists3[] = {NULL};
    int const listSize3 = 1;
    struct ListNode *actual3 = mergeKLists_23_2(lists3, listSize3);
    EXPECT_EQ(NULL, actual3);
}
