#include "unique_binary_search_trees_ii.h"

#include <stdlib.h>
#include <string.h>

static int *tree_counts(int node_count) {
    int *dp = (int *) calloc(node_count + 1, sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    for (int count = 2; count <= node_count; ++count) {
        for (int left = 0; left < count; ++left)
            dp[count] += dp[left] * dp[count - left - 1];
    }
    return dp;
}

static struct TreeNode *copy_tree(struct TreeNode *root) {
    if (root == NULL) return NULL;
    struct TreeNode *ret = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    ret->val = root->val;
    ret->left = copy_tree(root->left);
    ret->right = copy_tree(root->right);
    return ret;
}

static void free_tree(struct TreeNode *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

static struct TreeNode **generate_trees(int start, int end, int *size, int *tree_counts) {
    const int capacity = tree_counts[end - start];
    struct TreeNode **ret = (struct TreeNode **) malloc(capacity * sizeof(struct TreeNode *));
    *size = 0;
    if (start == end) {
        ret[(*size)++] = NULL;
        return ret;
    }
    for (int val = start; val < end; ++val) {
        int left_size = 0, right_size = 0;
        struct TreeNode **left_trees = generate_trees(start, val, &left_size, tree_counts),
                **right_trees = generate_trees(val + 1, end, &right_size, tree_counts);
        for (int i = 0; i < left_size; ++i) {
            for (int j = 0; j < right_size; ++j) {
                struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
                root->val = val;
                root->left = copy_tree(left_trees[i]);
                root->right = copy_tree(right_trees[j]);
                ret[(*size)++] = root;
            }
        }
        for (int i = 0; i < left_size; ++i) free_tree(left_trees[i]);
        free(left_trees);
        for (int j = 0; j < right_size; ++j) free_tree(right_trees[j]);
        free(right_trees);
    }
    return ret;
}

struct TreeNode **generateTrees_95_1(int n, int *returnSize) {
    if (n < 1 || returnSize == NULL) return NULL;
    int *counts = tree_counts(n);
    struct TreeNode **ret = generate_trees(1, n + 1, returnSize, counts);
    free(counts);
    return ret;
}
