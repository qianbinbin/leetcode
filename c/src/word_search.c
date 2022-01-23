#include "word_search.h"

#include <stdlib.h>
#include <string.h>

static bool
exist_dfs(char **board, int m, int n, bool **visited, int i, int j,
          char *word, size_t len, size_t index) {
    if (index == len)
        return true;

    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] ||
        board[i][j] != word[index])
        return false;

    visited[i][j] = true;
    bool exist = exist_dfs(board, m, n, visited, i - 1, j, word, len,
                           index + 1) ||
                 exist_dfs(board, m, n, visited, i + 1, j, word, len,
                           index + 1) ||
                 exist_dfs(board, m, n, visited, i, j - 1, word, len,
                           index + 1) ||
                 exist_dfs(board, m, n, visited, i, j + 1, word, len,
                           index + 1);
    visited[i][j] = false;
    return exist;
}

bool exist_79_1(char **board, int boardSize, int *boardColSize, char *word) {
    int const m = boardSize, n = boardColSize[0];
    bool **visited = (bool **) malloc(m * sizeof(bool *));
    for (int i = 0; i < m; ++i)
        visited[i] = (bool *) calloc(n, sizeof(bool));

    bool ret = false;

    const size_t len = strlen(word);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (exist_dfs(board, m, n, visited, i, j, word, len, 0)) {
                ret = true;
                goto ret;
            }
        }
    }

    ret:
    for (int i = 0; i < m; ++i) free(visited[i]);
    free(visited);
    return ret;
}
