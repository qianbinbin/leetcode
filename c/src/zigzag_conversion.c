#include "zigzag_conversion.h"

#include <stdlib.h>
#include <string.h>

char *convert_6_1(char *s, int numRows) {
    if (s == NULL || numRows < 1) return NULL;

    const size_t len = strlen(s);
    char *ret = (char *) malloc(len + 1);
    ret[len] = '\0';
    if (numRows == 1) {
        strcpy(ret, s);
        return ret;
    }

    size_t size = 0;
    const int cycle = 2 * numRows - 2;
    for (int index = 0; index < len; index += cycle)
        ret[size++] = s[index];
    for (int i = 1; i < numRows - 1; ++i) {
        const int offset = (numRows - i - 1) * 2;
        for (int index = i; index < len; index += cycle) {
            ret[size++] = s[index];
            if (index + offset < len)
                ret[size++] = s[index + offset];
        }
    }
    for (int index = numRows - 1; index < len; index += cycle)
        ret[size++] = s[index];
    return ret;
}
