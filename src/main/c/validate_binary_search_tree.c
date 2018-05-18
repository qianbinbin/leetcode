#include <validate_binary_search_tree.h>
#include <stdlib.h>

static bool is_valid_bst_inorder(struct TreeNode *root, struct TreeNode **pre) {
    if (root == NULL) return true;
    if (!is_valid_bst_inorder(root->left, pre)) return false;
    if (*pre != NULL && (*pre)->val >= root->val) return false;
    *pre = root;
    return is_valid_bst_inorder(root->right, pre);
}

bool isValidBST_98(struct TreeNode *root) {
    struct TreeNode *pre = NULL;
    return is_valid_bst_inorder(root, &pre);
}
