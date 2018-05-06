#include <edit-distance.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minDistance_72(char *word1, char *word2) {
    if (word1 == NULL || word2 == NULL) return -1;

    const size_t len1 = strlen(word1), len2 = strlen(word2);
    int **dp = (int **) malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; ++i)
        dp[i] = (int *) malloc((len2 + 1) * sizeof(int));

    for (int i = 0; i <= len1; ++i) dp[i][0] = i;
    for (int i = 1; i <= len2; ++i) dp[0][i] = i;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int min = MIN(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1);
                dp[i][j] = MIN(min, dp[i][j - 1] + 1);
            }
        }
    }

    int ret = dp[len1][len2];
    for (int i = 0; i <= len1; ++i) free(dp[i]);
    free(dp);
    return ret;
}
