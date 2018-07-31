#include "decode_ways.h"

#include <string.h>

int numDecodings_91_1(char *s) {
    if (s == NULL) return -1;
    const size_t len = strlen(s);

    int prev = 1, cur = s[0] == '0' ? 0 : 1, tmp;
    for (int i = 1; i < len && cur != 0; ++i) {
        tmp = cur;
        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
            if (s[i] == '0') {
                cur = prev;
            } else {
                cur += prev;
            }
        } else if (s[i] == '0') {
            cur = 0;
        }
        prev = tmp;
    }
    return cur;
}
