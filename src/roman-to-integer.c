#include <roman-to-integer.h>
#include <string.h>

int map(char c) {
    switch (c) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
    }
}

int romanToInt_13(char *s) {
    if (s == NULL) return -1;

    int num = 0, idx = 0;
    while (idx < strlen(s)) {
        if (map(s[idx]) < map(s[idx + 1])) {
            num += map(s[idx + 1]) - map(s[idx]);
            idx += 2;
        } else {
            num += map(s[idx]);
            ++idx;
        }
    }
    return num;
}
