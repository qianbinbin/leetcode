#include <common.h>
#include <stdio.h>
#include <stdlib.h>

void array_print(int *nums, int numsSize) {
    if (nums == NULL) return;
    printf("{");
    for (int i = 0; i < numsSize; ++i) {
        if (i < numsSize - 1) printf("%d, ", nums[i]);
        else printf("%d", nums[numsSize - 1]);
    }
    printf("}\n");
}

void list_print(struct ListNode *head) {
    while (head != NULL) {
        if (head->next != NULL) printf("%d -> ", head->val);
        else printf("%d", head->val);
        head = head->next;
    }
    printf("\n");
}

static struct ListNode *list_append(struct ListNode *p, int val) {
    struct ListNode *tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
    tmp->val = val;
    tmp->next = NULL;
    p->next = tmp;
    return tmp;
}

struct ListNode *list_from_array(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return NULL;

    struct ListNode *list = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *p = list;
    for (int i = 0; i < numsSize; ++i) {
        p = list_append(p, nums[i]);
    }
    p = list->next;
    free(list);
    return p;
}

void list_free(struct ListNode *head) {
    struct ListNode *pre;
    while (head != NULL) {
        pre = head;
        head = pre->next;
        free(pre);
    }
}

struct TreeNode *tree_create_node(int val) {
    if (val == INT_NULL_TREE_NODE) return NULL;

    struct TreeNode *ret = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    ret->val = val;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

static struct TreeNode **tree_nodes_from_array(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return NULL;

    struct TreeNode **ret = (struct TreeNode **) malloc(numsSize * sizeof(struct TreeNode *));
    for (int i = 0; i < numsSize; ++i) {
        ret[i] = tree_create_node(nums[i]);
    }
    return ret;
}

static struct TreeNode *tree_create_from_nodes(struct TreeNode **nodes, int size) {
    if (nodes == NULL || size < 1) return NULL;

    for (int i = 0; i < size; ++i) {
        if (nodes[i] != NULL) {
            nodes[i]->left = (2 * i + 1 < size) ? nodes[2 * i + 1] : NULL;
            nodes[i]->right = (2 * i + 2 < size) ? nodes[2 * i + 2] : NULL;
        }
    }
    struct TreeNode *ret = nodes[0];
    free(nodes);
    return ret;
}

struct TreeNode *tree_create(int *nums, int numsSize) {
    if (nums == NULL || numsSize < 1) return NULL;
    struct TreeNode **nodes = tree_nodes_from_array(nums, numsSize);
    return tree_create_from_nodes(nodes, numsSize);
}

static void tree_preorder(struct TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    tree_preorder(root->left);
    tree_preorder(root->right);
}

void tree_preorder_print(struct TreeNode *root) {
    if (root == NULL) return;
    tree_preorder(root);
    printf("\n");
}

static void tree_inorder(struct TreeNode *root) {
    if (root == NULL) return;
    tree_inorder(root->left);
    printf("%d ", root->val);
    tree_inorder(root->right);
}

void tree_inorder_print(struct TreeNode *root) {
    if (root == NULL) return;
    tree_inorder(root);
    printf("\n");
}

static void tree_postorder(struct TreeNode *root) {
    if (root == NULL) return;
    tree_postorder(root->left);
    tree_postorder(root->right);
    printf("%d ", root->val);
}

void tree_postorder_print(struct TreeNode *root) {
    if (root == NULL) return;
    tree_postorder(root);
    printf("\n");
}

void tree_free(struct TreeNode *root) {
    if (root == NULL) return;

    tree_free(root->left);
    tree_free(root->right);
    free(root);
}
