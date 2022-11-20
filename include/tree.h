#ifndef __TREE_TREE_H__
#define __TREE_TREE_H__
#include <stdlib.h>
#include "node.h"

typedef struct {
    tree_node_t *root;
    size_t size;
} tree_t;

tree_t *tree_new();
// `label` is a string of the form "x.y.z" and will recursively add all nodes
// required to make z a child of y a child of x. The individual nodes will have
// the label "x", "x.y" and "x.y.z". To add a root node add a new node with the
// label "." If a node with label `label` already exists we only overwrite it's
// value. on success this function returns 0. It returns 1 for an invalid
// expression and -1 for other failures
int tree_add_node(tree_t *tree, const char *label, void *value);
// returns a pointer to the node with label `label`. If no such node was found
// NULL is returned
tree_node_t *tree_get_node(tree_t *tree, const char *label);
void tree_destroy(tree_t *tree);

#endif
