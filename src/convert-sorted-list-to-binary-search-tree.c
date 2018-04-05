#include <convert-sorted-list-to-binary-search-tree.h>
#include <stdlib.h>

static int length_list(struct ListNode *head) {
    int ret = 0;
    while (head != NULL) {
        ++ret;
        head = head->next;
    }
    return ret;
}

static struct TreeNode *sorted_list_to_bst(struct ListNode **head, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    struct TreeNode *left = sorted_list_to_bst(head, start, mid - 1);
    struct TreeNode *root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    root->val = (*head)->val;
    *head = (*head)->next;
    root->left = left;
    root->right = sorted_list_to_bst(head, mid + 1, end);
    return root;
}

struct TreeNode *sortedListToBST_109(struct ListNode *head) {
    int length = length_list(head);
    return sorted_list_to_bst(&head, 0, length - 1);
}
