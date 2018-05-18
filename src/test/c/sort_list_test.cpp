#include <gtest/gtest.h>

extern "C" {
#include <sort_list.h>
}

TEST(leetcode_148, normal) {
    int nums[] = {7, 5, 1, 3, 5, 9, 1, 2};
    struct ListNode *list = list_from_array(nums, 8);
    list_print(list);
    list = sortList_148(list);
    list_print(list);
    list_free(list);
}
