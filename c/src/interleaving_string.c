#include "interleaving_string.h"

#include <stdlib.h>
#include <string.h>

bool isInterleave_97_1(char *s1, char *s2, char *s3) {
    size_t m = strlen(s1), n = strlen(s2);
    if (m + n != strlen(s3)) return false;

    bool *dp = (bool *) malloc((n + 1) * sizeof(bool));

    dp[0] = true;
    for (int j = 1; j <= n; ++j)
        dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];

    for (int i = 1; i <= m; ++i) {
        dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
        for (int j = 1; j <= n; ++j) {
            dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                    (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }

    bool ret = dp[n];
    free(dp);
    return ret;
}