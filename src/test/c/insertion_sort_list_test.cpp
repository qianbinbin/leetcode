#include <gtest/gtest.h>

extern "C" {
#include <insertion_sort_list.h>
}

TEST(leetcode_147, normal) {
    int nums[] = {7, 5, 1, 3, 5, 9, 1, 2};
    struct ListNode *list = list_create(nums, 8);
    list_print(list);
    list = insertionSortList_147(list);
    list_print(list);
    list_free(list);
}
