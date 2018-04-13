#include <letter-combinations-of-a-phone-number.h>
#include <stdlib.h>
#include <string.h>

static void letter_combinations_dfs(char **map, int *digits, int digits_size, int depth,
                                    char **combinations, int *c_size, char *path) {
    if (depth == digits_size) {
        combinations[*c_size] = (char *) malloc(depth + 1);
        memcpy(combinations[*c_size], path, depth);
        combinations[*c_size][depth] = '\0';
        ++(*c_size);
        return;
    }
    char *letters = map[digits[depth]];
    int len = strlen(letters);
    for (int i = 0; i < len; ++i) {
        path[depth] = letters[i];
        letter_combinations_dfs(map, digits, digits_size, depth + 1, combinations, c_size, path);
    }
}

char **letterCombinations_17(char *digits, int *returnSize) {
    if (digits == NULL || returnSize == NULL) return NULL;

    int d_size = strlen(digits);
    if (d_size == 0) {
        char **ret = (char **) malloc(0);
        *returnSize = 0;
        return ret;
    }

    char *map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int *int_digits = (int *) malloc(d_size * sizeof(int));
    for (int i = 0; i < d_size; ++i)
        int_digits[i] = digits[i] - '0';

    int capacity = 1 << (2 * d_size);
    char **combinations = (char **) malloc(capacity * sizeof(char *));
    *returnSize = 0;

    char *path = (char *) malloc(d_size);

    letter_combinations_dfs(map, int_digits, d_size, 0, combinations, returnSize, path);

    free(path);
    combinations = (char **) realloc(combinations, (*returnSize) * sizeof(char *));
    return combinations;
}
