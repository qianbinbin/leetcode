#include "reverse_integer.h"

int reverse_7_1(int x) {
    int result = 0;
    for (; x != 0; x /= 10) {
        if (result > 214748364 || result < -214748364)
            return 0;
        result = result * 10 + x % 10;
    }
    return result;
}
