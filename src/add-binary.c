#include <add-binary.h>
#include <string.h>
#include <stdlib.h>

char *addBinary_67(char *a, char *b) {
    if (a == NULL || b == NULL) return NULL;

    int i = strlen(a), j = strlen(b);
    const int size = (i > j ? i : j) + 2;
    char *binary = (char *) malloc(size);
    memset(binary, 0, size);
    int val = 0, carry = 0;
    int k = size - 2;
    --i;
    --j;
    while (i >= 0 && j >= 0) {
        val = (a[i] - '0') + (b[j] - '0') + carry;
        carry = val / 2;
        val = val % 2;
        binary[k--] = val + '0';
        --i;
        --j;
    }
    while (i >= 0) {
        val = a[i] - '0' + carry;
        carry = val / 2;
        val = val % 2;
        binary[k--] = val + '0';
        --i;
    }
    while (j >= 0) {
        val = b[j] - '0' + carry;
        carry = val / 2;
        val = val % 2;
        binary[k--] = val + '0';
        --j;
    }
    char *ret;
    if (carry == 1) {
        binary[0] = '1';
        ret = binary;
    } else {
        binary[0] = '0';
        while (k < size - 2 && binary[k] == '0') ++k;
        int size_ret = size - k;
        ret = (char *) malloc(size_ret);
        memcpy(ret, binary + k, size_ret);
        free(binary);
    }
    return ret;
}
