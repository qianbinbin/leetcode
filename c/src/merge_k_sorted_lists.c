#include "merge_k_sorted_lists.h"

#include <stdlib.h>

static struct ListNode *
merge_two_sorted_lists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy = {0, NULL}, *tail = &dummy;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }
    tail->next = l1 != NULL ? l1 : l2;
    return dummy.next;
}

struct ListNode *mergeKLists_23_1(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;

    for (int interval = 1, i, step; interval < listsSize; interval *= 2) {
        for (i = 0, step = interval * 2; i < listsSize - interval; i += step)
            lists[i] = merge_two_sorted_lists(lists[i], lists[i + interval]);
    }
    return lists[0];
}

typedef struct {
    int capacity;
    int size;
    void **data;

    int (*compare)(void const *a, void const *b);
} heap;

static heap *
heap_create(int capacity, int (*compare)(const void *, const void *)) {
    heap *h = (heap *) malloc(sizeof(heap));
    h->data = (void **) malloc(capacity * sizeof(void *));
    h->capacity = capacity;
    h->size = 0;
    h->compare = compare;
    return h;
}

static void heap_push(heap *h, void *e) {
    if (h->size >= h->capacity) {
        h->capacity *= 2;
        h->data = (void **) realloc(h->data, (h->capacity) * sizeof(void *));
    }
    int i = h->size;
    h->data[h->size++] = e;
    if (i == 0)
        return;

    void **data = h->data;
    for (int parent; i > 0; i = parent) {
        parent = (i - 1) / 2;
        void *p = data[parent];
        if (h->compare(p, e) <= 0)
            break;
        data[i] = p;
    }
    data[i] = e;
}

static void *heap_pop(heap *h) {
    int const size = --h->size;
    void **data = h->data;
    void *ret = data[0];
    void *p = data[size];
    data[size] = NULL;
    if (size == 0)
        return ret;

    data[0] = p;
    int const half = size / 2;
    int i = 0;
    for (int child, right; i < half; i = child) {
        child = i * 2 + 1;
        right = child + 1;
        if (right < size && h->compare(data[child], data[right]) > 0)
            child = right;
        void *c = data[child];
        if (h->compare(p, c) <= 0)
            break;
        data[i] = c;
    }
    data[i] = p;
    return ret;
}

static void heap_free(heap *h) {
    free(h->data);
    free(h);
}

typedef struct ListNode node;

static int compare(void const *a, void const *b) {
    return ((node *) a)->val - ((node *) b)->val;
}

struct ListNode *mergeKLists_23_2(struct ListNode **lists, int listsSize) {
    heap *h = heap_create(listsSize, compare);
    for (int i = 0; i < listsSize; ++i)
        if (lists[i] != NULL)
            heap_push(h, lists[i]);

    node dummy = {0, NULL}, *tail = &dummy, *n;
    while (h->size > 0) {
        n = heap_pop(h);
        tail->next = n;
        tail = n;
        if (n->next != NULL)
            heap_push(h, n->next);
    }
    heap_free(h);
    return dummy.next;
}
