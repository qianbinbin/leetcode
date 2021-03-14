#include "letter_combinations_of_a_phone_number.h"

#include <stdlib.h>
#include <string.h>

static void
combination(char *const *map, char *digit, char *path, char *path_back,
            char ***result, size_t *result_size, size_t *result_capacity) {
    if (*digit == '\0') {
        if (*result_size >= *result_capacity) {
            *result_capacity *= 2;
            *result = (char **) realloc(*result,
                                        (*result_capacity) * sizeof(char *));
        }
        (*result)[(*result_size)++] = strdup(path);
        return;
    }
    for (char *s = map[*digit - '0']; *s; ++s) {
        *path_back = *s;
        combination(map, digit + 1, path, path_back + 1, result, result_size,
                    result_capacity);
    }
}

char **letterCombinations_17_1(char *digits, int *returnSize) {
    size_t capacity = 16, size = 0;
    char **result = (char **) malloc(capacity * sizeof(char *));

    const size_t len = strlen(digits);
    if (len == 0)
        goto ret;

    char *const map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs",
                           "tuv", "wxyz"};

    char *path = (char *) malloc(len + 1);
    path[len] = '\0';
    combination(map, digits, path, path, &result, &size, &capacity);
    free(path);

    ret:
    result = (char **) realloc(result, size * sizeof(char *));
    *returnSize = size;
    return result;
}
