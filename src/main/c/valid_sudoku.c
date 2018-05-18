#include <valid_sudoku.h>
#include <stddef.h>

void reset(bool *used) {
    for (int i = 0; i < 9; ++i) used[i] = false;
}

bool check(char ch, bool *used) {
    if (used == NULL) return false;
    if (ch == '.') return true;

    if ('1' <= ch && ch <= '9' && !used[ch - '1']) {
        used[ch - '1'] = true;
        return true;
    }
    return false;
}

bool isValidSudoku_36(char **board, int boardRowSize, int boardColSize) {
    if (board == NULL || boardRowSize != 9 || boardColSize != 9) return false;

    bool used[9];

    for (int i = 0; i < 9; ++i) {
        reset(used);
        for (int j = 0; j < 9; ++j) {
            if (!check(board[i][j], used)) return false;
        }
        reset(used);
        for (int j = 0; j < 9; ++j) {
            if (!check(board[j][i], used)) return false;
        }
    }

    for (int base_i = 0; base_i < 9; base_i = base_i + 3) {
        for (int base_j = 0; base_j < 9; base_j = base_j + 3) {
            reset(used);
            for (int i = base_i; i < base_i + 3; ++i) {
                for (int j = base_j; j < base_j + 3; ++j) {
                    if (!check(board[i][j], used)) return false;
                }
            }
        }
    }
    return true;
}
