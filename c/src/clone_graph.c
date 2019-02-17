#include "clone_graph.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define HASH_MAP_SIZE 256

typedef struct Entry {
    void *key;
    void *value;
    struct Entry *next;
} entry;

typedef struct HashMap {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static int hashcode(void *key) {
    return (int) (intptr_t) key;
}

static hashmap *hashmap_create() {
    hashmap *map = (hashmap *) malloc(sizeof(hashmap));
    entry *entries = map->entries;
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        (entries + i)->next = NULL;
    return map;
}

static void hashmap_put(hashmap *map, void *key, void *value) {
    entry *e = map->entries + (hashcode(key) & (HASH_MAP_SIZE - 1));
    while (e->next != NULL) {
        if (e->next->key == key) {
            e->next->value = value;
            return;
        }
        e = e->next;
    }
    entry *new = (entry *) malloc(sizeof(entry));
    new->next = NULL;
    new->key = key;
    new->value = value;
    e->next = new;
}

static void *hashmap_get(hashmap *map, void *key) {
    entry *e = map->entries + (hashcode(key) & (HASH_MAP_SIZE - 1));
    while (e->next != NULL) {
        if (e->next->key == key)
            return e->next->value;
        e = e->next;
    }
    return NULL;
}

static void hashmap_free(hashmap *map) {
    entry *entries = map->entries;
    entry *head, *tmp;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        head = entries + i;
        while (head->next != NULL) {
            tmp = head->next;
            head->next = tmp->next;
            free(tmp);
        }
    }
    free(map);
}

static struct UndirectedGraphNode *clone_graph_dfs(struct UndirectedGraphNode *node, hashmap *visited) {
    struct UndirectedGraphNode *clone = hashmap_get(visited, node);
    if (clone != NULL) return clone;

    clone = (struct UndirectedGraphNode *) malloc(sizeof(struct UndirectedGraphNode));
    clone->label = node->label;
    hashmap_put(visited, node, clone);
    for (clone->neighborsCount = 0; clone->neighborsCount < node->neighborsCount; ++clone->neighborsCount) {
        clone->neighbors[clone->neighborsCount] = clone_graph_dfs(node->neighbors[clone->neighborsCount], visited);
    }
    return clone;
}

struct UndirectedGraphNode *cloneGraph_133_1(struct UndirectedGraphNode *graph) {
    if (graph == NULL) return NULL;

    hashmap *visited = hashmap_create();
    struct UndirectedGraphNode *clone = clone_graph_dfs(graph, visited);
    hashmap_free(visited);
    return clone;
}

typedef struct Queue {
    void **elements;
    int head;
    int tail;
    int capacity;
    int size;
} queue;

static queue *queue_create() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->elements = (void **) calloc(16, sizeof(void *));
    q->head = 0;
    q->tail = 0;
    q->capacity = 16;
    q->size = 0;
    return q;
}

static void queue_offer(queue *q, void *e) {
    void **elements = q->elements;
    int t = q->tail;
    elements[t++] = e;
    q->tail = t & (q->capacity - 1);
    ++q->size;
    if (q->head == q->tail) {
        int new_cap = q->capacity << 1;
        void **new_e = (void **) calloc(new_cap, sizeof(void *));
        int left = q->head, right = q->size - q->head;
        memcpy(new_e, elements + left, right * sizeof(void *));
        memcpy(new_e + right, elements, left * sizeof(void *));
        free(elements);
        q->elements = new_e;
        q->capacity = new_cap;
        q->head = 0;
        q->tail = q->size;
    }
}

static void *queue_poll(queue *q) {
    if (q->size == 0) return NULL;
    int h = q->head;
    void *ret = q->elements[h];
    q->elements[h++] = NULL;
    q->head = h & (q->capacity - 1);
    --q->size;
    return ret;
}

static bool queue_empty(queue *q) {
    return q->size == 0;
}

static void queue_free(queue *q) {
    free(q->elements);
    free(q);
}

struct UndirectedGraphNode *cloneGraph_133_2(struct UndirectedGraphNode *graph) {
    if (graph == NULL) return NULL;

    queue *q = queue_create();
    queue_offer(q, graph);
    struct UndirectedGraphNode *clone = (struct UndirectedGraphNode *) malloc(sizeof(struct UndirectedGraphNode));
    clone->label = graph->label;
    clone->neighborsCount = 0;
    hashmap *visited = hashmap_create();
    hashmap_put(visited, graph, clone);

    struct UndirectedGraphNode *node, *neighbor, *cloned_neighbor;
    while (!queue_empty(q)) {
        graph = queue_poll(q);
        node = hashmap_get(visited, graph);
        for (int i = 0; i < graph->neighborsCount; ++i) {
            neighbor = graph->neighbors[i];
            cloned_neighbor = hashmap_get(visited, neighbor);
            if (cloned_neighbor == NULL) {
                cloned_neighbor = (struct UndirectedGraphNode *) malloc(sizeof(struct UndirectedGraphNode));
                cloned_neighbor->label = neighbor->label;
                cloned_neighbor->neighborsCount = 0;
                hashmap_put(visited, neighbor, cloned_neighbor);
                queue_offer(q, neighbor);
            }
            node->neighbors[node->neighborsCount++] = cloned_neighbor;
        }
    }
    hashmap_free(visited);
    queue_free(q);
    return clone;
}
