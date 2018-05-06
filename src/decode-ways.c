#include <decode-ways.h>
#include <string.h>

int numDecodings_91(char *s) {
    if (s == NULL) return -1;
    const size_t len = strlen(s);

    int prev = 1, tmp, ret = s[0] == '0' ? 0 : 1;
    for (int i = 1; i < len && ret != 0; ++i) {
        tmp = ret;
        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
            if (s[i] == '0') {
                ret = prev;
            } else {
                ret += prev;
            }
        } else if (s[i] == '0') {
            ret = 0;
        }
        prev = tmp;
    }
    return ret;
}
