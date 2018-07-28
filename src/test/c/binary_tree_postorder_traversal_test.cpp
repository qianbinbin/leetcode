#include <gtest/gtest.h>

extern "C" {
#include "binary_tree_postorder_traversal.h"
}

#define ARR_SIZE(a) (sizeof(a) / sizeof((a)[0]))

TEST(binary_tree_postorder_traversal_test, postorderTraversal_145_1) {
    int nums[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *root = tree_create(nums, ARR_SIZE(nums));
    int size = 0;
    int *ret = postorderTraversal_145_1(root, &size);
    array_print(ret, size);
    free(ret);
    tree_free(root);
}

TEST(binary_tree_postorder_traversal_test, postorderTraversal_145_2) {
    int nums[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *root = tree_create(nums, ARR_SIZE(nums));
    int size = 0;
    int *ret = postorderTraversal_145_2(root, &size);
    array_print(ret, size);
    free(ret);
    tree_free(root);
}

TEST(binary_tree_postorder_traversal_test, postorderTraversal_145_3) {
    int nums[] = {1, NTNODE, 2, NTNODE, NTNODE, 3};
    struct TreeNode *root = tree_create(nums, ARR_SIZE(nums));
    int size = 0;
    int *ret = postorderTraversal_145_3(root, &size);
    array_print(ret, size);
    free(ret);
    tree_free(root);
}
