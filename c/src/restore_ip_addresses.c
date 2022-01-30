#include "restore_ip_addresses.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool is_valid_ip_segment(char const *s, size_t n) {
    if (n == 0 || n > 3)
        return false;
    if (s[0] == '0')
        return n == 1;
    int val = 0;
    for (size_t i = 0; i < n; ++i)
        val = val * 10 + s[i] - '0';
    return val < 256;
}

static void restore_ip_dfs(char *s, size_t len, size_t index, int level,
                           char **results, int *size, char *path,
                           size_t path_size) {
    if (level == 4 || index == len) {
        if (level == 4 && index == len)
            results[(*size)++] = strndup(path, path_size - 1);
        return;
    }
    path[path_size] = s[index];
    path[path_size + 1] = '.';
    restore_ip_dfs(s, len, index + 1, level + 1, results, size, path,
                   path_size + 2);
    if (s[index] == '0')
        return;
    if (index + 1 < len) {
        path[path_size] = s[index];
        path[path_size + 1] = s[index + 1];
        path[path_size + 2] = '.';
        restore_ip_dfs(s, len, index + 2, level + 1, results, size, path,
                       path_size + 3);
    }
    if (index + 2 < len && is_valid_ip_segment(s + index, 3)) {
        path[path_size] = s[index];
        path[path_size + 1] = s[index + 1];
        path[path_size + 2] = s[index + 2];
        path[path_size + 3] = '.';
        restore_ip_dfs(s, len, index + 3, level + 1, results, size, path,
                       path_size + 4);
    }
}

char **restoreIpAddresses_93_1(char *s, int *returnSize) {
    const size_t len = strlen(s);
    const size_t capacity = 27;
    char **ret = (char **) malloc(capacity * sizeof(char *));
    *returnSize = 0;

    char path[16];

    restore_ip_dfs(s, len, 0, 0, ret, returnSize, path, 0);

    ret = (char **) realloc(ret, (*returnSize) * sizeof(char *));
    return ret;
}

char **restoreIpAddresses_93_2(char *s, int *returnSize) {
    const size_t len = strlen(s);
    const size_t capacity = 27;
    char **ret = (char **) malloc(capacity * sizeof(char *));
    *returnSize = 0;

    for (size_t a = 1; a <= 3; ++a) {
        for (size_t b = 1; b <= 3; ++b) {
            for (size_t c = 1; c <= 3; ++c) {
                if (a + b + c >= len || a + b >= len) break;
                if (is_valid_ip_segment(s, a) &&
                    is_valid_ip_segment(s + a, b) &&
                    is_valid_ip_segment(s + a + b, c) &&
                    is_valid_ip_segment(s + a + b + c, len - a - b - c)) {
                    char *ip = (char *) malloc(len + 4);
                    size_t size = 0;
                    memcpy(ip, s, a);
                    size += a;
                    ip[size++] = '.';
                    memcpy(ip + size, s + a, b);
                    size += b;
                    ip[size++] = '.';
                    memcpy(ip + size, s + a + b, c);
                    size += c;
                    ip[size++] = '.';
                    strcpy(ip + size, s + a + b + c);
                    ret[(*returnSize)++] = ip;
                }
            }
        }
    }

    ret = (char **) realloc(ret, (*returnSize) * sizeof(char *));
    return ret;
}
