#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    t_btree *tNode;
    tNode = bstree_create_node(21);
    printf("%d\n", tNode->item);
    free(tNode);
    tNode = bstree_create_node(42);
    printf("%d\n", tNode->item);
    free(tNode);
    return 0;
}