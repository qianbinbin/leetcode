#include <multiply-strings.h>
#include <stdlib.h>
#include <string.h>

char *multiply_43(char *num1, char *num2) {
    if (num1 == NULL || num2 == NULL) return NULL;

    const int len1 = strlen(num1), len2 = strlen(num2);
    const size_t max_len = len1 + len2;
    int *result = (int *) calloc(max_len, sizeof(int));
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int tmp = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
            result[i + j + 1] = tmp % 10;
            result[i + j] += tmp / 10;
        }
    }
    size_t offset = 0;
    while (offset < max_len - 1 && result[offset] == 0) ++offset;
    const size_t size = max_len - offset;

    char *ret = (char *) malloc(size + 1);
    ret[size] = '\0';
    for (size_t i = 0; i < size; ++i) ret[i] = (char) (result[i + offset] + '0');

    free(result);
    return ret;
}
