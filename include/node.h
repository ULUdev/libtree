#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__
#include <stdlib.h>

/*
 * A node that is part of a tree. Every node has a unique label and possibly a
 * value.
 */
typedef struct TreeNode {
    struct TreeNode **children;
    char *label;
    void *value;
    size_t numchildren;
} tree_node_t;

// create a new node
tree_node_t *tree_node_new(const char *label, void *value);

// set the label of a node
void tree_node_set_label(tree_node_t *node, const char *label);

// set the value of a node
void tree_node_set_value(tree_node_t *node, void *value);

// add a child to a node
void tree_node_add_child(tree_node_t *node, tree_node_t *child);

// destroy a node
void tree_node_destroy(tree_node_t *node);

#endif
