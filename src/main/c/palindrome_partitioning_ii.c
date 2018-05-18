#include <palindrome_partitioning_ii.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minCut_132(char *s) {
    if (s == NULL) return -1;

    const int len = strlen(s);
    bool **p = (bool **) malloc(len * sizeof(bool *));
    for (int i = 0; i < len; ++i)
        p[i] = (bool *) calloc(len, sizeof(bool));
    int *cut = (int *) malloc((len + 1) * sizeof(int));
    for (int i = 0; i <= len; ++i)
        cut[i] = len - 1 - i;

    for (int i = len - 1; i >= 0; --i) {
        for (int j = i; j < len; ++j) {
            if (i == j || (s[i] == s[j] && (i + 1 == j || p[i + 1][j - 1]))) {
                p[i][j] = true;
                cut[i] = MIN(cut[i], cut[j + 1] + 1);
            }
        }
    }
    int ret = cut[0];
    free(cut);
    for (int i = 0; i < len; ++i)
        free(p[i]);
    free(p);
    return ret;
}
