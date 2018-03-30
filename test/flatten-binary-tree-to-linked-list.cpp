#include <gtest/gtest.h>

extern "C" {
#include <flatten-binary-tree-to-linked-list.h>
}

TEST(leetcode_114_1, normal) {
    int nums[] = {1, 2, 5, 3, 4, INT_NULL_TREE_NODE, 6};
    struct TreeNode *tree = tree_create(nums, 7);
    printf("before flattening\npreorder:\n");
    tree_preorder_print(tree);
    printf("inorder:\n");
    tree_inorder_print(tree);
    flatten_114_1(tree);
    printf("after flattening\npreorder:\n");
    tree_preorder_print(tree);
    printf("inorder:\n");
    tree_inorder_print(tree);
}

TEST(leetcode_114_2, normal) {
    int nums[] = {1, 2, 5, 3, 4, INT_NULL_TREE_NODE, 6};
    struct TreeNode *tree = tree_create(nums, 7);
    printf("before flattening\npreorder:\n");
    tree_preorder_print(tree);
    printf("inorder:\n");
    tree_inorder_print(tree);
    flatten_114_2(tree);
    printf("after flattening\npreorder:\n");
    tree_preorder_print(tree);
    printf("inorder:\n");
    tree_inorder_print(tree);
}
