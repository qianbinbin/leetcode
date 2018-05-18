#include <surrounded_regions.h>
#include <stdlib.h>
#include <stdbool.h>

static void mark_dfs(char **board, int i, int j, int row, int col) {
    if (board[i][j] == 'O') {
        board[i][j] = 'M';
        if (i > 0)
            mark_dfs(board, i - 1, j, row, col);
        if (i < row - 1)
            mark_dfs(board, i + 1, j, row, col);
        if (j > 0)
            mark_dfs(board, i, j - 1, row, col);
        if (j < col - 1)
            mark_dfs(board, i, j + 1, row, col);

    }
}

void solve_130_1(char **board, int boardRowSize, int boardColSize) {
    if (board == NULL || boardRowSize < 1 || boardColSize < 1) return;

    for (int i = 0; i < boardRowSize; ++i) {
        mark_dfs(board, i, 0, boardRowSize, boardColSize);
        if (boardColSize > 1)
            mark_dfs(board, i, boardColSize - 1, boardRowSize, boardColSize);
    }
    for (int j = 1; j < boardColSize - 1; ++j) {
        mark_dfs(board, 0, j, boardRowSize, boardColSize);
        if (boardRowSize > 1)
            mark_dfs(board, boardRowSize - 1, j, boardRowSize, boardColSize);
    }
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < boardColSize; ++j) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'M')
                board[i][j] = 'O';
        }
    }
}

typedef struct {
    int i;
    int j;
} pair;

static pair *pair_create(int i, int j) {
    pair *p = (pair *) malloc(sizeof(pair));
    p->i = i;
    p->j = j;
    return p;
}

typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} node;

typedef struct {
    node *head;
    node *tail;
} queue;

static queue *queue_create() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->head = (node *) malloc(sizeof(node));
    q->head->data = NULL;
    q->tail = (node *) malloc(sizeof(node));
    q->tail->data = NULL;
    q->head->prev = NULL;
    q->head->next = q->tail;
    q->tail->prev = q->head;
    q->tail->next = NULL;
    return q;
}

static void queue_push(queue *q, void *p) {
    node *new = (node *) malloc(sizeof(node));
    new->data = p;
    new->next = q->tail;
    new->prev = q->tail->prev;
    q->tail->prev->next = new;
    q->tail->prev = new;
}

static void *queue_pop(queue *q) {
    node *n = q->head->next;
    if (n != q->tail) {
        q->head->next = n->next;
        n->next->prev = q->head;
        void *ret = n->data;
        free(n);
        return ret;
    }
    return NULL;
}

static bool queue_empty(queue *q) {
    return q->head->next == q->tail;
}

static void queue_free(queue *q) {
    node *n = q->head->next;
    while (n != NULL) {
        q->head->next = n->next;
        free(n);
        n = q->head->next;
    }
    free(q->head);
    free(q);
}

static void mark_bfs(char **board, int i, int j, int row, int col) {
    if (board[i][j] != 'O') return;

    queue *q = queue_create();
    queue_push(q, pair_create(i, j));
    while (!queue_empty(q)) {
        pair *p = queue_pop(q);
        board[p->i][p->j] = 'M';
        if (p->i > 0 && board[p->i - 1][p->j] == 'O')
            queue_push(q, pair_create(p->i - 1, p->j));
        if (p->i < row - 1 && board[p->i + 1][p->j] == 'O')
            queue_push(q, pair_create(p->i + 1, p->j));
        if (p->j > 0 && board[p->i][p->j - 1] == 'O')
            queue_push(q, pair_create(p->i, p->j - 1));
        if (p->j < col - 1 && board[p->i][p->j + 1] == 'O')
            queue_push(q, pair_create(p->i, p->j + 1));
        free(p);
    }
    queue_free(q);
}

void solve_130_2(char **board, int boardRowSize, int boardColSize) {
    if (board == NULL || boardRowSize < 1 || boardColSize < 1) return;

    for (int i = 0; i < boardRowSize; ++i) {
        mark_bfs(board, i, 0, boardRowSize, boardColSize);
        if (boardColSize > 1)
            mark_bfs(board, i, boardColSize - 1, boardRowSize, boardColSize);
    }
    for (int j = 1; j < boardColSize - 1; ++j) {
        mark_bfs(board, 0, j, boardRowSize, boardColSize);
        if (boardRowSize > 1)
            mark_bfs(board, boardRowSize - 1, j, boardRowSize, boardColSize);
    }
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < boardColSize; ++j) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'M')
                board[i][j] = 'O';
        }
    }
}
