#include <scramble-string.h>
#include <string.h>

static bool is_scramble(char *s1, char *s2, size_t len) {
    if (len == 1) return *s1 == *s2;

    int map[26];
    memset(map, 0, 26 * sizeof(int));
    for (size_t i = 0; i < len; ++i) {
        ++map[s1[i] - 'a'];
        --map[s2[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) if (map[i] != 0) return false;

    for (size_t i = 1; i < len; ++i) {
        if ((is_scramble(s1, s2, i) && is_scramble(s1 + i, s2 + i, len - i)) ||
            (is_scramble(s1, s2 + len - i, i) && is_scramble(s1 + i, s2, len - i))) {
            return true;
        }
    }
    return false;
}

bool isScramble_87_1(char *s1, char *s2) {
    if (s1 == NULL || s2 == NULL) return false;

    const size_t len = strlen(s1);
    if (strlen(s2) != len) return false;
    return is_scramble(s1, s2, len);
}
