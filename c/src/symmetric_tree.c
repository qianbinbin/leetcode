#include "symmetric_tree.h"

#include <stdlib.h>
#include <string.h>

static bool is_symmetric(struct TreeNode *p, struct TreeNode *q) {
    if (p == q) return true;
    if (p == NULL || q == NULL) return p == q;
    if (p->val != q->val)
        return false;
    return is_symmetric(p->left, q->right) &&
           is_symmetric(p->right, q->left);
}

bool isSymmetric_101_1(struct TreeNode *root) {
    return is_symmetric(root->left, root->right);
}

typedef struct Queue {
    void **elements;
    int capacity;
    int head;
    int tail;
} queue;

static queue *queue_create() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->capacity = 16;
    q->head = 0;
    q->tail = 0;
    q->elements = (void **) calloc(16, sizeof(void *));
    return q;
}

static void queue_offer(queue *q, void *e) {
    int t = q->tail;
    q->elements[t] = e;
    q->tail = (t + 1) & (q->capacity - 1);
    if (q->tail == q->head) {
        int n = q->capacity;
        int new_cap = n << 1;
        void **a = (void **) malloc(new_cap * sizeof(void *));
        int left = q->head, right = n - q->head;
        memcpy(a, q->elements + left, right * sizeof(void *));
        memcpy(a + right, q->elements, left * sizeof(void *));
        free(q->elements);
        q->elements = a;
        q->capacity = new_cap;
        q->head = 0;
        q->tail = n;
    }
}

static void *queue_poll(queue *q) {
    int h = q->head;
    if (h == q->tail) return NULL;
    void *ret = q->elements[h];
    q->head = (h + 1) & (q->capacity - 1);
    return ret;
}

static bool queue_empty(queue *q) {
    return q->head == q->tail;
}

static void queue_free(queue *q) {
    free(q->elements);
    free(q);
}

bool isSymmetric_101_2(struct TreeNode *root) {
    queue *q = queue_create();
    queue_offer(q, root->left);
    queue_offer(q, root->right);
    struct TreeNode *p1, *p2;
    bool ret = true;
    while (!queue_empty(q)) {
        p1 = queue_poll(q);
        p2 = queue_poll(q);
        if (p1 == NULL && p2 == NULL) continue;
        if (p1 == NULL || p2 == NULL || p1->val != p2->val) {
            ret = false;
            break;
        }
        queue_offer(q, p1->left);
        queue_offer(q, p2->right);
        queue_offer(q, p1->right);
        queue_offer(q, p2->left);
    }
    queue_free(q);
    return ret;
}
