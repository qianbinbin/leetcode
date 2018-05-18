#include <construct_binary_tree_from_preorder_and_inorder_traversal.h>
#include <stdlib.h>

static struct TreeNode *build_tree_from_preorder_inorder(int *preorder, int pre_start, int pre_end,
                                                         int *inorder, int in_start, int in_end) {
    if (pre_start > pre_end) return NULL;
    int root_val = preorder[pre_start];
    int idx = in_start;
    while (idx <= in_end && inorder[idx] != root_val) ++idx;
    if (idx > in_end) return NULL;
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = root_val;
    root->left = build_tree_from_preorder_inorder(preorder, pre_start + 1, pre_start + idx - in_start,
                                                  inorder, in_start, idx - 1);
    root->right = build_tree_from_preorder_inorder(preorder, pre_start + idx - in_start + 1, pre_end,
                                                   inorder, idx + 1, in_end);
    return root;
}

struct TreeNode *buildTree_105(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    if (preorder == NULL || preorderSize < 1 || inorder == NULL || inorderSize < 1 || preorderSize != inorderSize)
        return NULL;
    return build_tree_from_preorder_inorder(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}
