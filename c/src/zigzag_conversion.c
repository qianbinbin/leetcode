#include "zigzag_conversion.h"

#include <stdlib.h>
#include <string.h>

char *convert_6_1(char *s, int numRows) {
    const size_t len = strlen(s), row = numRows;
    char *ret = (char *) malloc(len + 1);
    ret[len] = '\0';
    if (row == 1 || row >= len) {
        strcpy(ret, s);
        return ret;
    }

    char *p = ret;
    size_t index, cycle = 2 * (row - 1);
    for (index = 0; index < len; index += cycle)
        *p++ = s[index];
    for (size_t i = 1, offset; i < row - 1; ++i) {
        offset = 2 * (row - i - 1);
        for (index = i; index < len; index += cycle) {
            *p++ = s[index];
            if (index + offset < len)
                *p++ = s[index + offset];
        }
    }
    for (index = row - 1; index < len; index += cycle)
        *p++ = s[index];
    return ret;
}
