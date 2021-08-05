#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    t_btree *tNode;
    tNode = bstree_create_node(21);
    bstree_insert(&tNode, 42, intCmp);
    bstree_insert(&tNode, 2, intCmp);
    for (int i = 0; i < 10; i++) {
        bstree_insert(&tNode, i, intCmp);
    }
    bstree_apply_infix(tNode, print);
    printf("\n");
    bstree_apply_postfix(tNode, print);
    printf("\n");
    bstree_apply_prefix(tNode, print);
    bstree_free(tNode);
    return 0;
}