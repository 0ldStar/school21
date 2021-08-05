#include "bst.h"
#include "stdlib.h"
#include <stdio.h>

t_btree* bstree_create_node(int item) {
    t_btree* tNode = (t_btree*)malloc(sizeof(t_btree));
    tNode->item = item;
    tNode->left = NULL;
    tNode->right = NULL;
    return tNode;
}
void bstree_insert(t_btree** root, int item, int (*cmpf) (int, int)) {
    if ((*root) == NULL) *root = bstree_create_node(item);
    if (cmpf((*root)->item, item) == 1) {
        bstree_insert(&(*root)->left, item, cmpf);
    }
    if (cmpf((*root)->item, item) == -1) {
        bstree_insert(&(*root)->right, item, cmpf);
    }
}

int intCmp(int a, int b) {
    int status;
    if (a > b) {
        status = 1;
    } else if (a < b) {
        status = -1;
    } else {
        status = 0;
    }
    return status;
}

void print(int a) {
    printf("%d ", a);
}

void bstree_apply_infix(t_btree *root, void (*applyf) (int)) {
    if (root == NULL) return;
    bstree_apply_infix(root->left, applyf);
 
    applyf(root->item);

    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree *root, void (*applyf) (int)) {
    if (root == NULL) return;
    applyf(root->item);
 
    bstree_apply_prefix(root->left, applyf);

    bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree *root, void (*applyf) (int)) {
    if (root == NULL) return;
    bstree_apply_postfix(root->right, applyf);
 
    applyf(root->item);

    bstree_apply_postfix(root->left, applyf);
}
void bstree_free(t_btree *root) {
    if (root == NULL) return;
 
    bstree_free(root->left);

    bstree_free(root->right);
    free(root);
}