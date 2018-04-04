#include <convert-sorted-array-to-binary-search-tree.h>
#include <stdlib.h>

static struct TreeNode *sorted_array_to_bst(int *nums, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = sorted_array_to_bst(nums, start, mid - 1);
    root->right = sorted_array_to_bst(nums, mid + 1, end);
    return root;
}

struct TreeNode *sortedArrayToBST_108(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return NULL;
    return sorted_array_to_bst(nums, 0, numsSize - 1);
}
