#include "letter_combinations_of_a_phone_number.h"

#include <stdlib.h>
#include <string.h>

static void letter_combinations_dfs(char **map, int *digits, size_t digits_size, size_t index,
                                    char ***combinations, size_t *size, size_t *capacity, char *path) {
    if (index == digits_size) {
        if (*size >= *capacity) {
            *capacity *= 2;
            *combinations = (char **) realloc(*combinations, (*capacity) * sizeof(char *));
        }
        (*combinations)[*size] = (char *) malloc(digits_size + 1);
        strcpy((*combinations)[*size], path);
        ++(*size);
        return;
    }
    char *letters = map[digits[index]];
    size_t len = strlen(letters);
    for (size_t i = 0; i < len; ++i) {
        path[index] = letters[i];
        letter_combinations_dfs(map, digits, digits_size, index + 1, combinations, size, capacity, path);
    }
}

char **letterCombinations_17_1(char *digits, int *returnSize) {
    if (digits == NULL || returnSize == NULL) return NULL;

    const size_t len = strlen(digits);
    if (len == 0) {
        char **ret = (char **) malloc(0);
        *returnSize = 0;
        return ret;
    }

    char *map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int *int_digits = (int *) malloc(len * sizeof(int));
    for (size_t i = 0; i < len; ++i)
        int_digits[i] = digits[i] - '0';

    size_t capacity = 32;
    char **combinations = (char **) malloc(capacity * sizeof(char *));
    size_t size = 0;

    char *path = (char *) malloc(len + 1);
    path[len] = '\0';

    letter_combinations_dfs(map, int_digits, len, 0, &combinations, &size, &capacity, path);

    free(path);
    combinations = (char **) realloc(combinations, size * sizeof(char *));
    *returnSize = (int) size;
    return combinations;
}
