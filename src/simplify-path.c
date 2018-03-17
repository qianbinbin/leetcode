#include <simplify-path.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char *simplifyPath_71(char *path) {
    if (path == NULL) return NULL;

    assert(path[0] == '/');

    char *ret = (char *) malloc(strlen(path) + 1);
    int index = -1;
    int start = 1, end = 1;
    while (path[end] != '\0') {
        while (path[end] != '/' && path[end] != '\0') ++end;
        if (start == end || (start + 1 == end && path[start] == '.')) {
            // skip
        } else if (start + 2 == end && path[start] == '.' && path[start + 1] == '.') {
            while (index >= 0 && ret[index] != '/') --index;
            if (index >= 0) --index;
        } else {
            ret[++index] = '/';
            memcpy(ret + index + 1, path + start, end - start);
            index += end - start;
        }

        if (path[end] == '\0') break;
        start = end + 1;
        end = start;
    }
    if (index == -1) {
        ret = (char *) realloc(ret, 2);
        ret[++index] = '/';
    } else {
        ret = (char *) realloc(ret, index + 2);
    }
    ret[index + 1] = '\0';
    return ret;
}
