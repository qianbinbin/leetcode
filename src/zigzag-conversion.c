#include <zigzag-conversion.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *convert_6(char *s, int numRows) {
    if (s == NULL || numRows < 0) return NULL;

    const size_t len = strlen(s);
    char *ret = (char *) malloc(len + 1);
    ret[len] = '\0';
    if (len <= 1 || numRows <= 1) {
        strcpy(ret, s);
        return ret;
    }

    int size = 0;

    int index;
    for (int i = 0; i < numRows; ++i) {
        int j = 0;
        while (true) {
            int tmp = j % (numRows - 1);
            if (tmp == 0 || tmp == numRows - i - 1) {
                index = 2 * j + i;
                if (index >= len) break;
                ret[size++] = s[index];
            }
            ++j;
        }
    }
    return ret;
}
