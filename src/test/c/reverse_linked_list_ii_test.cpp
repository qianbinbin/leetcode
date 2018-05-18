#include <gtest/gtest.h>

extern "C" {
#include <reverse_linked_list_ii.h>
}

TEST(leetcode_92, normal) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *l = list_from_array(nums, 5);
    list_print(l);
    l = reverseBetween_92(l, 2, 4);
    list_print(l);
    list_free(l);
}
