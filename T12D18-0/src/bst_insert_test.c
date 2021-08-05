#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    t_btree *tNode;
    tNode = bstree_create_node(21);
    printf("21 == %d\n", tNode->item);
    bstree_insert(&tNode, 42, intCmp);
    printf("42 == %d\n", tNode->right->item);
    bstree_insert(&tNode, 2, intCmp);
    printf("2 == %d\n", tNode->left->item);
    free(tNode);
    return 0;
}