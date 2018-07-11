#include "restore_ip_addresses.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool is_valid_byte(const char *s, size_t offset, size_t count) {
    if (count == 0 || count > 3)
        return false;
    if (s[offset] == '0')
        return count == 1;
    int val = 0;
    for (size_t i = 0; i < count; ++i)
        val = val * 10 + s[offset + i] - '0';
    return val < 256;
}

static char *new_str(char *s, size_t offset, size_t count) {
    char *ret = (char *) malloc(count + 1);
    memcpy(ret, s + offset, count);
    ret[count] = '\0';
    return ret;
}

static void restore_ip_dfs(char *s, size_t len, size_t offset, int level,
                           char **results, int *size, char *path, size_t path_size) {
    if (level == 4 || offset == len) {
        if (level == 4 && offset == len)
            results[(*size)++] = new_str(path, 0, path_size - 1);
        return;
    }
    const size_t end = offset + 3 < len ? offset + 3 : len;
    for (size_t i = offset; i < end; ++i) {
        const size_t count = i - offset + 1;
        if (is_valid_byte(s, offset, count)) {
            memcpy(path + path_size, s + offset, count);
            path_size += count;
            path[path_size++] = '.';
            restore_ip_dfs(s, len, i + 1, level + 1, results, size, path, path_size);
            path_size -= count + 1;
        }
    }
}

char **restoreIpAddresses_93_1(char *s, int *returnSize) {
    if (s == NULL || returnSize == NULL) return NULL;

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
    if (s == NULL || returnSize == NULL) return NULL;

    const size_t len = strlen(s);
    if (len < 4 || len > 12) return NULL;

    const size_t capacity = 27;
    char **ret = (char **) malloc(capacity * sizeof(char *));
    *returnSize = 0;

    for (size_t a = 1; a <= 3; ++a) {
        for (size_t b = 1; b <= 3; ++b) {
            for (size_t c = 1; c <= 3; ++c) {
                if (a + b + c >= len || a + b >= len) continue;
                if (is_valid_byte(s, 0, a) && is_valid_byte(s, a, b) &&
                    is_valid_byte(s, a + b, c) && is_valid_byte(s, a + b + c, len - a - b - c)) {
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
