#include <gtest/gtest.h>

extern "C" {
#include <clone-graph.h>
}

static struct UndirectedGraphNode *node_create(int label) {
    struct UndirectedGraphNode *node = (struct UndirectedGraphNode *) malloc(sizeof(struct UndirectedGraphNode));
    node->label = label;
    node->neighborsCount = 0;
    return node;
}

TEST(leetcode_133, normal) {
    struct UndirectedGraphNode *node0 = node_create(0);
    struct UndirectedGraphNode *node1 = node_create(1);
    struct UndirectedGraphNode *node2 = node_create(2);
    node0->neighbors[node0->neighborsCount++] = node1;
    node0->neighbors[node0->neighborsCount++] = node2;
    node1->neighbors[node1->neighborsCount++] = node0;
    node1->neighbors[node1->neighborsCount++] = node2;
    node2->neighbors[node2->neighborsCount++] = node0;
    node2->neighbors[node2->neighborsCount++] = node1;
    node2->neighbors[node2->neighborsCount++] = node2;
    struct UndirectedGraphNode *clone = cloneGraph_133(node0);
    free(node0);
    free(node1);
    free(node2);
    free(clone->neighbors[0]);
    free(clone->neighbors[1]);
    free(clone);
}