#include "edit_distance.h"

#include <stdlib.h>
#include <string.h>

static int min(int a, int b, int c) {
    int ret = a <= b ? a : b;
    return ret <= c ? ret : c;
}

int minDistance_72_1(char *word1, char *word2) {
    const size_t len1 = strlen(word1), len2 = strlen(word2);
    int **dp = (int **) malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; ++i)
        dp[i] = (int *) malloc((len2 + 1) * sizeof(int));

    for (int j = 0; j <= len2; ++j)
        dp[0][j] = j;
    for (int i = 1, j; i <= len1; ++i) {
        dp[i][0] = i;
        for (j = 1; j <= len2; ++j) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] =
                        min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
        }
    }

    int ret = dp[len1][len2];
    for (int i = 0; i <= len1; ++i) free(dp[i]);
    free(dp);
    return ret;
}
