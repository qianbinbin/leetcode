#include "clone_graph.h"

#include "uthash.h"

#include <stdlib.h>

static struct Node *clone_graph_dfs(struct Node *node, struct Node **visited) {
    if (visited[node->val] != NULL)
        return visited[node->val];

    struct Node *clone = (struct Node *) malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = 0;
    clone->neighbors = (struct Node **) malloc(sizeof(struct Node *) * 100);
    visited[clone->val] = clone;
    while (clone->numNeighbors < node->numNeighbors) {
        clone->neighbors[clone->numNeighbors] = clone_graph_dfs(
                node->neighbors[clone->numNeighbors], visited);
        ++clone->numNeighbors;
    }
    return clone;
}

struct Node *cloneGraph_133_1(struct Node *s) {
    if (s == NULL) return NULL;

    struct Node **visited = (struct Node **) calloc(101, sizeof(struct Node *));
    struct Node *clone = clone_graph_dfs(s, visited);
    free(visited);
    return clone;
}

struct Node *cloneGraph_133_2(struct Node *s) {
    if (s == NULL) return NULL;

    struct Node **stack = (struct Node **) malloc(100 * sizeof(struct Node *));
    int top = -1;
    stack[++top] = s;
    struct Node **visited = (struct Node **) calloc(101, sizeof(struct Node *));
    struct Node *clone = (struct Node *) malloc(sizeof(struct Node));
    clone->val = s->val;
    clone->numNeighbors = 0;
    clone->neighbors = (struct Node **) malloc(sizeof(struct Node *) * 100);
    visited[clone->val] = clone;
    while (top >= 0) {
        struct Node *node = stack[top--];
        struct Node *cloned_node = visited[node->val];
        for (int i = 0; i < node->numNeighbors; ++i) {
            struct Node *neighbor = node->neighbors[i];
            struct Node *cloned_neighbor = visited[neighbor->val];
            if (cloned_neighbor == NULL) {
                cloned_neighbor = (struct Node *) malloc(sizeof(struct Node));
                cloned_neighbor->val = neighbor->val;
                cloned_neighbor->numNeighbors = 0;
                cloned_neighbor->neighbors = (struct Node **) malloc(
                        sizeof(struct Node *) * 100);
                visited[cloned_neighbor->val] = cloned_neighbor;
                stack[++top] = neighbor;
            }
            cloned_node->neighbors[cloned_node->numNeighbors++] = cloned_neighbor;
        }
    }
    free(stack);
    free(visited);
    return clone;
}
