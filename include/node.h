#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__
#include <stdlib.h>

typedef struct TreeNode {
    struct TreeNode **children;
    char *label;
    void *value;
    size_t numchildren;
} tree_node_t;

tree_node_t *tree_node_new(const char *label, void *value);
void tree_node_set_label(tree_node_t *node, const char *label);
void tree_node_set_value(tree_node_t *node, void *value);
void tree_node_add_child(tree_node_t *node, tree_node_t *child);
void tree_node_destroy(tree_node_t *node);

#endif
