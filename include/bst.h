#ifndef __TREE_BST_H__
#define __TREE_BST_H__
#include <stdlib.h>
// TODO: make thread safe

typedef struct{
    size_t key;
    char *val;
    void *left;
    void *right;
} tree_bst_node_t;

typedef struct {
    tree_bst_node_t *root;
    size_t siz;
} tree_bst_t;

tree_bst_node_t *tree_bst_node_new(const char *val);
void tree_bst_node_set_left(tree_bst_node_t *node, tree_bst_node_t *left);
void tree_bst_node_set_right(tree_bst_node_t *node, tree_bst_node_t *right);
void tree_bst_node_destroy(tree_bst_node_t *node);

tree_bst_t *tree_bst_new();
void tree_bst_add_node(tree_bst_t *bst, const char *val);
void tree_bst_destroy(tree_bst_t *bst);
#endif