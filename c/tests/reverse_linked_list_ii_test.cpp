#include <gtest/gtest.h>

extern "C" {
#include "reverse_linked_list_ii.h"
}

TEST(reverse_linked_list_ii_test, reverseBetween_92_1) {
    int nums[] = {1, 2, 3, 4, 5};
    struct ListNode *l = list_create(nums, 5);
    list_print(l);
    l = reverseBetween_92_1(l, 2, 4);
    list_print(l);
    list_free(l);
}
