#ifndef PRINT_BTS_H
#define PRINT_BTS_H

typedef struct s_btree {
    struct s_btree* left;
    struct s_btree* right;
    int item;
} t_btree;

t_btree* bstree_create_node(int item);
void bstree_insert(t_btree **root, int item, int (*cmpf) (int, int));
int intCmp(int a, int b);
void bstree_apply_infix(t_btree *root, void (*applyf) (int));
void bstree_apply_prefix(t_btree *root, void (*applyf) (int));
void bstree_apply_postfix(t_btree *root, void (*applyf) (int));
void bstree_free(t_btree *root);
void print(int a);

#endif // PRINT_BTS_H