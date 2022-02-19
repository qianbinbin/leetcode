#include <gtest/gtest.h>

extern "C" {
#include "construct_binary_tree_from_inorder_and_postorder_traversal.h"
}

#define ARR_SIZE(a) ((sizeof(a)/sizeof((a)[0])))

TEST(construct_binary_tree_from_inorder_and_postorder_traversal_test,
     buildTree_106_1) {
    int inorder1[] = {9, 3, 15, 20, 7};
    int postorder1[] = {9, 15, 7, 20, 3};
    struct TreeNode *actual1 = buildTree_106_1(inorder1, ARR_SIZE(inorder1),
                                               postorder1,
                                               ARR_SIZE(postorder1));
    tree_inorder_print(actual1);
    tree_postorder_print(actual1);
    tree_free(actual1);

    int inorder2[] = {-1};
    int postorder2[] = {-1};
    struct TreeNode *actual2 = buildTree_106_1(inorder2, ARR_SIZE(inorder2),
                                               postorder2,
                                               ARR_SIZE(postorder2));
    tree_inorder_print(actual2);
    tree_postorder_print(actual2);
    tree_free(actual2);
}
