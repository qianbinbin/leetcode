#include "merge_k_sorted_lists.h"

#include <stdlib.h>

static struct ListNode *merge_two_sorted_lists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode *tail = dummy;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 != NULL ? l1 : l2;
    struct ListNode *ret = dummy->next;
    free(dummy);
    return ret;
}

struct ListNode *mergeKLists_23_1(struct ListNode **lists, int listsSize) {
    if (lists == NULL || listsSize < 1) return NULL;

    for (int interval = 1; interval < listsSize; interval *= 2) {
        for (int i = 0; i < listsSize - interval; i += interval * 2)
            lists[i] = merge_two_sorted_lists(lists[i], lists[i + interval]);
    }
    return lists[0];
}

typedef struct {
    int capacity;
    int size;
    void **data;

    int (*compare)(const void *a, const void *b);
} heap;

static heap *heap_create(int capacity, int (*compare)(const void *, const void *)) {
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
    while (i > 0) {
        int parent = (i - 1) / 2;
        void *p = data[parent];
        if (h->compare(p, e) <= 0)
            break;
        data[i] = p;
        i = parent;
    }
    data[i] = e;
}

static void *heap_pop(heap *h) {
    if (h->size == 0)
        return NULL;

    int s = --h->size;
    void *ret = h->data[0];
    void *p = h->data[s];
    h->data[s] = NULL;
    if (s == 0)
        return ret;

    void **data = h->data;
    data[0] = data[s];
    const int half = h->size / 2;
    int i = 0;
    while (i < half) {
        int child = i * 2 + 1;
        void *c = data[child];
        int right = child + 1;
        if (right < h->size && h->compare(c, data[right]) > 0) {
            child = right;
            c = data[right];
        }
        if (h->compare(p, c) <= 0)
            break;
        data[i] = c;
        i = child;
    }
    data[i] = p;
    return ret;
}

static void heap_free(heap *h) {
    free(h->data);
    free(h);
}

typedef struct ListNode node;

static int compare(const void *a, const void *b) {
    return ((node *) a)->val - ((node *) b)->val;
}

struct ListNode *mergeKLists_23_2(struct ListNode **lists, int listsSize) {
    if (lists == NULL || listsSize < 1) return NULL;

    heap *h = heap_create(listsSize, compare);
    for (int i = 0; i < listsSize; ++i)
        if (lists[i] != NULL)
            heap_push(h, lists[i]);

    node *dummy = (node *) malloc(sizeof(node));
    dummy->next = NULL;
    node *tail = dummy;
    while (h->size > 0) {
        node *n = heap_pop(h);
        tail->next = n;
        tail = tail->next;
        if (n->next != NULL)
            heap_push(h, n->next);
    }
    heap_free(h);
    node *ret = dummy->next;
    free(dummy);
    return ret;
}
