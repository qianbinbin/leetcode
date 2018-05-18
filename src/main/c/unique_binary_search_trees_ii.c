#include <unique_binary_search_trees_ii.h>
#include <stdlib.h>
#include <string.h>

static int num_trees(int n) {
    if (n < 0) return 0;

    int *dp = (int *) malloc((n + 1) * sizeof(int));
    memset(dp, 0, (n + 1) * sizeof(int));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
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

static struct TreeNode **generate_trees(int start, int end, int *size) {
    int capacity = num_trees(end - start + 1);
    if (capacity < 1) return NULL;
    struct TreeNode **ret = (struct TreeNode **) malloc(capacity * sizeof(struct TreeNode *));
    *size = 0;
    if (start > end) {
        ret[(*size)++] = NULL;
        return ret;
    }
    for (int val = start; val <= end; ++val) {
        int left_size = 0;
        struct TreeNode **left_trees = generate_trees(start, val - 1, &left_size);
        int right_size = 0;
        struct TreeNode **right_trees = generate_trees(val + 1, end, &right_size);
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

struct TreeNode **generateTrees_95(int n, int *returnSize) {
    if (n < 1 || returnSize == NULL) return NULL;
    return generate_trees(1, n, returnSize);
}
