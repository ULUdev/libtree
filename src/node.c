#include <stdlib.h>
#include <string.h>
#include "node.h"

tree_node_t *tree_node_new(const char *label, void *value) {
    tree_node_t *node = malloc(sizeof(tree_node_t));
    node->label = malloc(strlen(label) + 1);
    strncpy(node->label, label, strlen(label) + 1);
    node->value = value;
    node->children = malloc(1 * sizeof(tree_node_t));
    node->numchildren = 0;
    return node;
}
void tree_node_set_label(tree_node_t *node, const char *label) {
    node->label = realloc(node->label, strlen(label) + 1);
    strcpy(node->label, label);
}
void tree_node_set_value(tree_node_t *node, void *value) {
    node->value = value;
}
void tree_node_add_child(tree_node_t *node, tree_node_t *child) {
    node->children = 
        realloc(node->children, (node->numchildren + 1) * sizeof(tree_node_t));
    node->children[node->numchildren] = child;
    node->numchildren++;
}
void tree_node_destroy(tree_node_t *node) {
    free(node->label);
    for (int i = 0;i<node->numchildren;i++) {
        free(node->children[i]);
    }
    free(node->children);
    free(node);
}
