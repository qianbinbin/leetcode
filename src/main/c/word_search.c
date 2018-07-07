#include "word_search.h"

#include <stdlib.h>
#include <string.h>

static bool exist_dfs(char **board, int row, int col, bool **visited, int i, int j,
                      char *word, size_t len, size_t index) {
    if (index == len)
        return true;

    if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] || board[i][j] != word[index])
        return false;

    visited[i][j] = true;
    bool exist = exist_dfs(board, row, col, visited, i - 1, j, word, len, index + 1) ||
                 exist_dfs(board, row, col, visited, i + 1, j, word, len, index + 1) ||
                 exist_dfs(board, row, col, visited, i, j - 1, word, len, index + 1) ||
                 exist_dfs(board, row, col, visited, i, j + 1, word, len, index + 1);
    visited[i][j] = false;
    return exist;
}

bool exist_79_1(char **board, int boardRowSize, int boardColSize, char *word) {
    if (board == NULL || boardRowSize < 1 || boardColSize < 1 || word == NULL) return false;

    bool **visited = (bool **) malloc(boardRowSize * sizeof(bool *));
    for (int i = 0; i < boardRowSize; ++i)
        visited[i] = (bool *) calloc(boardColSize, sizeof(bool));

    bool ret = false;

    const size_t len = strlen(word);
    for (int i = 0; i < boardRowSize && !ret; ++i) {
        for (int j = 0; j < boardColSize; ++j) {
            if (exist_dfs(board, boardRowSize, boardColSize, visited, i, j, word, len, 0)) {
                ret = true;
                break;
            }
        }
    }

    for (int i = 0; i < boardRowSize; ++i) free(visited[i]);
    free(visited);
    return ret;
}
