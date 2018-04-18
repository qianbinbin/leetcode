#include <word-ladder-ii.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *prev;
    struct Node *next;
} node;

typedef struct {
    node *head;
    node *tail;
    int size;
} deque;

static void deque_init(deque *q) {
    q->head = (node *) malloc(sizeof(node));
    q->tail = (node *) malloc(sizeof(node));
    q->head->prev = NULL;
    q->head->next = q->tail;
    q->tail->prev = q->head;
    q->tail->next = NULL;
    q->size = 0;
}

static deque *deque_create() {
    deque *q = (deque *) malloc(sizeof(deque));
    deque_init(q);
    return q;
}

static void deque_add_first(deque *q, char *data) {
    node *next = q->head->next;
    node *new = (node *) malloc(sizeof(node));
    new->data = data;
    new->prev = q->head;
    new->next = next;
    next->prev = new;
    q->head->next = new;
    ++q->size;
}

static char *deque_remove_first(deque *q) {
    node *n = q->head->next;
    if (n != q->tail) {
        char *ret = n->data;
        q->head->next = n->next;
        n->next->prev = q->head;
        free(n);
        --q->size;
        return ret;
    }
    return NULL;
}

static void deque_add_last(deque *q, char *data) {
    node *pre = q->tail->prev;
    node *new = (node *) malloc(sizeof(node));
    new->data = data;
    new->next = q->tail;
    new->prev = pre;
    pre->next = new;
    q->tail->prev = new;
    ++q->size;
}

static char *deque_remove_last(deque *q) {
    node *n = q->tail->prev;
    if (n != q->head) {
        char *ret = n->data;
        q->tail->prev = n->prev;
        n->prev->next = q->tail;
        free(n);
        --q->size;
        return ret;
    }
    return NULL;
}

static char **deque_to_array(deque *q, int *size) {
    char **ret = (char **) malloc(q->size * sizeof(char *));
    node *it = q->head->next;
    for (*size = 0; *size < q->size; ++(*size)) {
        ret[*size] = it->data;
        it = it->next;
    }
    return ret;
}

static void deque_uninit(deque *q) {
    node *n = q->head->next;
    while (n != NULL) {
        q->head->next = n->next;
        free(n);
        n = q->head->next;
    }
    free(q->head);
    q->size = 0;
}

static void deque_free(deque *q) {
    deque_uninit(q);
    free(q);
}

#define HASH_MAP_SIZE 1024

typedef struct Entry {
    char *key;
    deque *value;
    struct Entry *next;
} entry;

typedef struct {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static int hashcode(char *key) {
    int code = 0;
    const size_t len = strlen(key);
    for (size_t i = 0; i < len; ++i)
        code = code * 31 + key[i];
    return abs(code);
}

static void hashmap_init(hashmap *map) {
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        (map->entries + i)->next = NULL;
}

static hashmap *hashmap_create() {
    hashmap *m = (hashmap *) malloc(sizeof(hashmap));
    hashmap_init(m);
    return m;
}

static void hashmap_put(hashmap *map, char *key, deque *val) {
    int index = hashcode(key) % HASH_MAP_SIZE;
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0) {
            e->next->value = val;
            return;
        }
        e = e->next;
    }
    entry *new = (entry *) malloc(sizeof(entry));
    new->key = key;
    new->value = val;
    new->next = NULL;
    e->next = new;
}

static void hashmap_put_key(hashmap *map, char *key) {
    hashmap_put(map, key, NULL);
}

static deque *hashmap_get(hashmap *map, char *key) {
    int index = hashcode(key) % HASH_MAP_SIZE;
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0)
            return e->next->value;
        e = e->next;
    }
    return NULL;
}

static char *hashmap_get_key(hashmap *map, char *key) {
    int index = hashcode(key) % HASH_MAP_SIZE;
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0)
            return e->next->key;
        e = e->next;
    }
    return NULL;
}

static bool hashmap_contains(hashmap *map, char *key) {
    int index = hashcode(key) % HASH_MAP_SIZE;
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0)
            return true;
        e = e->next;
    }
    return false;
}

static char *hashmap_remove(hashmap *map, char *key) {
    int index = hashcode(key) % HASH_MAP_SIZE;
    entry *e = map->entries + index;
    while (e->next != NULL) {
        if (strcmp(e->next->key, key) == 0) {
            entry *n = e->next->next;
            char *ret = e->next->key;
            free(e->next);
            e->next = n;
            return ret;
        }
        e = e->next;
    }
    return NULL;
}

static void hashmap_remove_all(hashmap *map, deque *q) {
    node *it = q->head->next;
    while (it != q->tail) {
        hashmap_remove(map, it->data);
        it = it->next;
    }
}

static void hashmap_uninit(hashmap *map) {
    entry *head, *e;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        head = map->entries + i;
        e = head->next;
        while (e != NULL) {
            e = e->next;
            if (head->next->value != NULL) {
                deque_free(head->next->value);
            }
            free(head->next);
            head->next = e;
        }
    }
}

static void hashmap_free(hashmap *map) {
    hashmap_uninit(map);
    free(map);
}

static void graph_dfs(hashmap *graph, char *root, char *end,
                      char ****ladders, int *ladder_size, int *ladder_capacity, int **col_sizes, deque *path) {
    if (strcmp(root, end) == 0) {
        if (*ladder_size >= *ladder_capacity) {
            (*ladder_capacity) *= 2;
            *ladders = (char ***) realloc(*ladders, (*ladder_capacity) * sizeof(char **));
            *col_sizes = (int *) realloc(*col_sizes, (*ladder_capacity) * sizeof(int));
        }
        (*ladders)[*ladder_size] = deque_to_array(path, *col_sizes + *ladder_size);
        ++(*ladder_size);
        return;
    }
    deque *q = hashmap_get(graph, root);
    if (q != NULL) {
        int size = 0;
        char **children = deque_to_array(q, &size);
        for (int i = 0; i < size; ++i) {
            deque_add_last(path, children[i]);
            graph_dfs(graph, children[i], end, ladders, ladder_size, ladder_capacity, col_sizes, path);
            deque_remove_last(path);
        }
        free(children);
    }
}

static void graph_push(hashmap *graph, char *father, char *child, bool flip) {
    if (flip) {
        char *tmp = father;
        father = child;
        child = tmp;
    }
    deque *children = hashmap_get(graph, father);
    if (children == NULL) {
        children = deque_create();
        hashmap_put(graph, father, children);
    }
    deque_add_last(children, child);
}

static void swap(void **a, void **b) {
    void *tmp = *a;
    *a = *b;
    *b = tmp;
}

char ***findLadders_126(char *beginWord, char *endWord, char **wordList, int wordListSize,
                        int **columnSizes, int *returnSize) {
    if (beginWord == NULL || endWord == NULL || wordList == NULL || wordListSize < 0 || columnSizes == NULL ||
        returnSize == NULL)
        return 0;

    hashmap *map = hashmap_create();
    for (int i = 0; i < wordListSize; ++i) {
        hashmap_put_key(map, wordList[i]);
    }
    if (!hashmap_contains(map, endWord)) {
        hashmap_free(map);
        return NULL;
    }

    int capacity = 16;
    *returnSize = 0;
    char ***ret = (char ***) malloc(capacity * sizeof(char **));
    *columnSizes = (int *) calloc(capacity, sizeof(int));

    deque *q1 = deque_create();
    deque_add_last(q1, beginWord);
    hashmap *m1 = hashmap_create();
    hashmap_put_key(m1, beginWord);

    deque *q2 = deque_create();
    deque_add_last(q2, endWord);
    hashmap *m2 = hashmap_create();
    hashmap_put_key(m2, endWord);

    hashmap *graph = hashmap_create();

    const size_t len = strlen(beginWord);
    char *word = (char *) malloc(len + 1);
    char *father, *child;

    int shortest = 0, depth = 0;
    bool flip = false;

    while (q1->size > 0 && q2->size > 0 && shortest == 0) {
        ++depth;
        if (q1->size > q2->size) {
            swap(&q1, &q2);
            swap(&m1, &m2);
            flip = !flip;
        }
        hashmap_remove_all(map, q1);
        hashmap_remove_all(map, q2);

        for (int size = q1->size; size > 0; --size) {
            strcpy(word, deque_remove_first(q1));
            father = hashmap_remove(m1, word);
            for (int i = 0; i < len; ++i) {
                const char c = word[i];
                for (char j = 'a'; j <= 'z'; ++j) {
                    if (j == c) continue;
                    word[i] = j;
                    if (hashmap_contains(m2, word)) {
                        if (shortest == 0)
                            shortest = depth + 1;
                        child = hashmap_get_key(m2, word);
                        graph_push(graph, father, child, flip);
                    } else if (shortest == 0) {
                        child = hashmap_get_key(map, word);
                        if (child != NULL) {
                            if (!hashmap_contains(m1, child)) {
                                deque_add_last(q1, child);
                                hashmap_put_key(m1, child);
                            }
                            graph_push(graph, father, child, flip);
                        }
                    }
                }
                word[i] = c;
            }
        }
    }

    deque *path = deque_create();
    deque_add_last(path, beginWord);
    graph_dfs(graph, beginWord, endWord, &ret, returnSize, &capacity, columnSizes, path);
    deque_free(path);

    ret = (char ***) realloc(ret, (*returnSize) * sizeof(char **));
    *columnSizes = (int *) realloc(*columnSizes, (*returnSize) * sizeof(int));

    free(word);
    hashmap_free(graph);
    hashmap_free(m2);
    deque_free(q2);
    hashmap_free(m1);
    deque_free(q1);
    hashmap_free(map);

    return ret;
}
