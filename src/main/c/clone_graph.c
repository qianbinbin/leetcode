#include <clone_graph.h>
#include <stdlib.h>

#define HASH_MAP_SIZE 1024

typedef struct Entry {
    void *key;
    void *value;
    struct Entry *next;
} entry;

typedef struct HashMap {
    entry entries[HASH_MAP_SIZE];
} hashmap;

static hashmap *hashmap_create() {
    hashmap *map = (hashmap *) malloc(sizeof(hashmap));
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        (map->entries + i)->next = NULL;
    return map;
}

static int hashcode(void *key) {
    return (int) (intptr_t) key;
}

static void hashmap_put(hashmap *map, void *key, void *value) {
    int hash = hashcode(key);
    entry *e = map->entries + ((HASH_MAP_SIZE - 1) & hash);
    while (e->next != NULL) e = e->next;
    entry *new = (entry *) malloc(sizeof(entry));
    new->next = NULL;
    new->key = key;
    new->value = value;
    e->next = new;
}

static void *hashmap_get(hashmap *map, void *key) {
    int hash = hashcode(key);
    entry *e = map->entries + ((HASH_MAP_SIZE - 1) & hash);
    while (e->next != NULL) {
        if (e->next->key == key) return e->next->value;
        e = e->next;
    }
    return NULL;
}

static void hashmap_free(hashmap *map) {
    entry *e, *tmp;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        e = map->entries + i;
        while (e->next != NULL) {
            tmp = e->next;
            e->next = tmp->next;
            free(tmp);
        }
    }
    free(map);
}

static struct UndirectedGraphNode *clone_graph_dfs(struct UndirectedGraphNode *graph, hashmap *visited) {
    struct UndirectedGraphNode *node = hashmap_get(visited, graph);
    if (node != NULL) return node;

    struct UndirectedGraphNode *clone = (struct UndirectedGraphNode *) malloc(sizeof(struct UndirectedGraphNode));
    hashmap_put(visited, graph, clone);
    clone->label = graph->label;
    for (clone->neighborsCount = 0; clone->neighborsCount < graph->neighborsCount; ++clone->neighborsCount) {
        clone->neighbors[clone->neighborsCount] = clone_graph_dfs(graph->neighbors[clone->neighborsCount], visited);
    }
    return clone;
}

struct UndirectedGraphNode *cloneGraph_133(struct UndirectedGraphNode *graph) {
    if (graph == NULL) return NULL;

    hashmap *visited = hashmap_create();
    struct UndirectedGraphNode *clone = clone_graph_dfs(graph, visited);
    hashmap_free(visited);
    return clone;
}
