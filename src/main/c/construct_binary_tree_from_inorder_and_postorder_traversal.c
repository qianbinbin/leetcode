#include <construct_binary_tree_from_inorder_and_postorder_traversal.h>
#include <stdlib.h>

static struct TreeNode *build_tree_from_inorder_postorder(int *inorder, int in_start, int in_end,
                                                          int *postorder, int post_start, int post_end) {
    if (in_start > in_end) return NULL;
    int root_val = postorder[post_end];
    int idx = in_start;
    while (idx <= in_end && inorder[idx] != root_val) ++idx;
    if (idx > in_end) return NULL;
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = root_val;
    root->left = build_tree_from_inorder_postorder(inorder, in_start, idx - 1, postorder, post_start,
                                                   post_start + idx - in_start - 1);
    root->right = build_tree_from_inorder_postorder(inorder, idx + 1, in_end, postorder, post_start + idx - in_start,
                                                    post_end - 1);
    return root;
}

struct TreeNode *buildTree_106(int *inorder, int inorderSize, int *postorder, int postorderSize) {
    if (inorder == NULL || inorderSize < 1 || postorder == NULL || postorderSize < 1 || inorderSize != postorderSize)
        return NULL;
    return build_tree_from_inorder_postorder(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}
