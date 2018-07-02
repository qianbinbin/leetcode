#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "plus_one.h"
}

TEST(plus_one_test, plusOne_66_1) {
    int digits1[] = {1, 2, 3};
    array_print(digits1, 3);
    int size1 = 0;
    int *result1 = plusOne_66_1(digits1, 3, &size1);
    array_print(result1, size1);
    free(result1);

    int digits2[] = {4, 3, 2, 1};
    array_print(digits2, 4);
    int size2 = 0;
    int *result2 = plusOne_66_1(digits2, 4, &size2);
    array_print(result2, size2);
    free(result2);
}
