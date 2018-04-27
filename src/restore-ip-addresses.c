#include <restore-ip-addresses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <printf.h>

/**
 * @return true if value of chars is between 0 ~ 255
 */
static bool valid_ipv4(char *s, int start, int end) {
    if (s[start] == '0' && end > start)
        return false;
    int num = 0;
    for (int i = start; i <= end; ++i) {
        num = num * 10 + s[i] - '0';
    }
    return 0 <= num && num <= 255;
}

static char *new_str(char *s, int start, int end) {
    const int len = end - start + 1;
    char *ret = (char *) malloc(len + 1);
    memcpy(ret, s + start, len);
    ret[len] = '\0';
    return ret;
}

static void restore_ip_dfs(char *s, int len, int start, int depth,
                           char **results, int *size, char *path, int path_size) {
    if (depth == 4 || start == len) {
        if (depth == 4 && start == len) {
            results[(*size)++] = new_str(path, 0, path_size - 2);
        }
        return;
    }
    const int end = start + 3 < len ? start + 3 : len;
    for (int i = start; i < end; ++i) {
        if (valid_ipv4(s, start, i)) {
            const int length = i - start + 1;
            memcpy(path + path_size, s + start, length);
            path_size += length;
            path[path_size++] = '.';
            restore_ip_dfs(s, len, i + 1, depth + 1, results, size, path, path_size);
            path_size -= length + 1;
        }
    }
}

char **restoreIpAddresses_93(char *s, int *returnSize) {
    if (s == NULL || returnSize == NULL) return NULL;

    const int len = strlen(s);
    const int capacity = 165; // combination(11, 3)
    char **ret = (char **) malloc(capacity * sizeof(char *));
    *returnSize = 0;

    char path[16];

    restore_ip_dfs(s, len, 0, 0, ret, returnSize, path, 0);

    ret = (char **) realloc(ret, (*returnSize) * sizeof(char *));
    return ret;
}
