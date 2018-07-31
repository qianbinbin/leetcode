#include "convert_sorted_array_to_binary_search_tree.h"

#include <stdlib.h>

static struct TreeNode *sorted_array_to_bst(int *nums, int start, int end) {
    if (start == end) return NULL;
    int mid = start + (end - start) / 2;
    struct TreeNode *left = sorted_array_to_bst(nums, start, mid);
    struct TreeNode *right = sorted_array_to_bst(nums, mid + 1, end);
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = left;
    root->right = right;
    return root;
}

struct TreeNode *sortedArrayToBST_108_1(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return NULL;
    return sorted_array_to_bst(nums, 0, numsSize);
}
