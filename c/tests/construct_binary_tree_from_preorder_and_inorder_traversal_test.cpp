#include <gtest/gtest.h>

extern "C" {
#include "construct_binary_tree_from_preorder_and_inorder_traversal.h"
}

#define ARR_SIZE(a) ((sizeof(a) / sizeof((a)[0])))

TEST(construct_binary_tree_from_preorder_and_inorder_traversal_test,
     buildTree_105_1) {
    int preorder1[] = {3, 9, 20, 15, 7};
    int inorder1[] = {9, 3, 15, 20, 7};
    struct TreeNode *actual1 = buildTree_105_1(preorder1, ARR_SIZE(preorder1),
                                               inorder1, ARR_SIZE(inorder1));
    tree_preorder_print(actual1);
    tree_inorder_print(actual1);
    tree_free(actual1);

    int preorder2[] = {-1};
    int inorder2[] = {-1};
    struct TreeNode *actual2 = buildTree_105_1(preorder2, ARR_SIZE(preorder2),
                                               inorder2, ARR_SIZE(inorder2));
    tree_preorder_print(actual2);
    tree_inorder_print(actual2);
    tree_free(actual2);
}
