#include <gtest/gtest.h>

extern "C" {
#include "add_two_numbers.h"
}

TEST(add_two_numbers_test, addTwoNumbers_2_1) {
    int nums11[] = {2, 4, 3};
    struct ListNode *l11 = list_create(nums11, 3);
    int nums12[] = {5, 6, 4};
    struct ListNode *l12 = list_create(nums12, 3);

    struct ListNode *l1 = addTwoNumbers_2_1(l11, l12);
    list_print(l1);

    list_free(l11);
    list_free(l12);
    list_free(l1);

    int nums21[] = {0};
    struct ListNode *l21 = list_create(nums21, 1);
    int nums22[] = {0};
    struct ListNode *l22 = list_create(nums22, 1);

    struct ListNode *l2 = addTwoNumbers_2_1(l21, l22);
    list_print(l2);

    list_free(l21);
    list_free(l22);
    list_free(l2);

    int nums31[] = {9, 9, 9, 9, 9, 9, 9};
    struct ListNode *l31 = list_create(nums31, 7);
    int nums32[] = {9, 9, 9, 9};
    struct ListNode *l32 = list_create(nums32, 4);

    struct ListNode *l3 = addTwoNumbers_2_1(l31, l32);
    list_print(l3);

    list_free(l31);
    list_free(l32);
    list_free(l3);
}
