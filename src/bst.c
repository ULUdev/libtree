#include "bst.h"
#include <stdlib.h>
#include <string.h>

size_t tree_bst_hash(const char *val) {
    size_t hash = 5381;
    int c;

    while (c = *val++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
tree_bst_node_t *tree_bst_node_new(const char *val) {
    tree_bst_node_t *node = malloc(sizeof(tree_bst_node_t));
    node->val = malloc(strlen(val)+1);
    strncpy(node->val, val, strlen(val));
    node->left = NULL;
    node->right = NULL;
}
void tree_bst_node_set_left(tree_bst_node_t *node, tree_bst_node_t *left);
void tree_bst_node_set_right(tree_bst_node_t *node, tree_bst_node_t *right);
void tree_bst_node_destroy(tree_bst_node_t *node) {
    free(node->val);
    tree_bst_node_destroy(node->left);
    tree_bst_node_destroy(node->right);
    free(node);
}

tree_bst_t *tree_bst_new();
void tree_bst_add_node(tree_bst_t *bst, const char *val);
void tree_bst_destroy(tree_bst_t *bst);