#include <word-search.h>
#include <stdlib.h>
#include <string.h>

static bool exist_dfs(char **board, int board_row, int board_col,
                      char *word, int len, int index, bool **visited, int i, int j) {
    if (index == len)
        return true;

    if (i < 0 || i >= board_row || j < 0 || j >= board_col || visited[i][j] || board[i][j] != word[index])
        return false;

    visited[i][j] = true;
    bool exist = exist_dfs(board, board_row, board_col, word, len, index + 1, visited, i - 1, j) ||
                 exist_dfs(board, board_row, board_col, word, len, index + 1, visited, i + 1, j) ||
                 exist_dfs(board, board_row, board_col, word, len, index + 1, visited, i, j - 1) ||
                 exist_dfs(board, board_row, board_col, word, len, index + 1, visited, i, j + 1);
    visited[i][j] = false;
    return exist;
}

bool exist_79(char **board, int boardRowSize, int boardColSize, char *word) {
    if (board == NULL || boardRowSize < 1 || boardColSize < 1 || word == NULL) return false;

    bool **visited = (bool **) malloc(boardRowSize * sizeof(bool *));
    for (int i = 0; i < boardRowSize; ++i)
        visited[i] = (bool *) calloc(boardColSize, sizeof(bool));

    bool ret = false;

    const int len = strlen(word);
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < boardColSize; ++j) {
            if (exist_dfs(board, boardRowSize, boardColSize, word, len, 0, visited, i, j)) {
                ret = true;
                break;
            }
        }
        if (ret) break;
    }

    for (int i = 0; i < boardRowSize; ++i)
        free(visited[i]);
    free(visited);
    return ret;
}
