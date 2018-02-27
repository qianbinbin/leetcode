#include <gtest/gtest.h>

extern "C" {
#include <reverse-linked-list-ii.h>
}

TEST(leetcode_92, normal) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *l = array_to_list(nums, 5);
    print_list(l);
    l = reverseBetween_92(l, 2, 4);
    print_list(l);
    free_list(l);
}
