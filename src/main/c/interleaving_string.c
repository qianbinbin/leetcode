#include <interleaving_string.h>
#include <stdlib.h>
#include <string.h>

bool isInterleave_97(char *s1, char *s2, char *s3) {
    if (s1 == NULL || s2 == NULL || s3 == NULL) return false;

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t len3 = strlen(s3);
    if (len1 + len2 != len3) return false;
    if (len1 < len2) {
        char *tmp = s1;
        s1 = s2;
        s2 = tmp;
        size_t t = len1;
        len1 = len2;
        len2 = t;
    }

    bool *dp = (bool *) malloc((len2 + 1) * sizeof(bool));

    dp[0] = true;
    for (int j = 1; j <= len2; ++j) {
        dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
    }

    for (int i = 1; i <= len1; ++i) {
        dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
        for (int j = 1; j <= len2; ++j) {
            dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }

    bool ret = dp[len2];
    free(dp);
    return ret;
}