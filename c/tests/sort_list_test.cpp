#include <gtest/gtest.h>

extern "C" {
#include "sort_list.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

int list1[] = {4, 2, 1, 3};

int list2[] = {-1, 5, 3, 4, 0};

TEST(sort_list_test, sortList_148_1) {
    struct ListNode *head1 = list_create(list1, ARR_SIZE(list1));
    list_print(head1);
    head1 = sortList_148_1(head1);
    list_print(head1);
    list_free(head1);

    struct ListNode *head2 = list_create(list2, ARR_SIZE(list2));
    list_print(head2);
    head2 = sortList_148_1(head2);
    list_print(head2);
    list_free(head2);
}
