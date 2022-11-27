#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tree.h"

int tree_streq(const char *s1, const char *s2) {
    if (strlen(s1) == strlen(s2)) {
        return strncmp(s1, s2, strlen(s1));
    } else {
        return 1;
    }
}

#define streq(s1, s2) (tree_streq(s1, s2) == 0)

tree_t *tree_new() {
    tree_t *tree = malloc(sizeof(tree_t));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}
int tree_add_node(tree_t *tree, const char *label, void *value) {
    if (streq(label, ".")) {
        if (tree->root) {
            tree_node_set_value(tree->root, value);
        } else {
            tree->root = tree_node_new(label, value);
            tree->size++;
        }
        return 0;
    } else {
        if (!tree->root) {
            tree->root = tree_node_new(".", NULL);
            tree->size++;
        }
        if (label[0] == '.') return 1;
        char *buf = malloc(strlen(label)+1);
        memset(buf, '\0', strlen(label)+1);
        tree_node_t *cur_node = tree->root;
        for (int i=0;i<strlen(label);i++) {
            if (label[i] == '.') {
                tree_node_t *child = NULL;
                for (int j=0;j<cur_node->numchildren;j++) {
                    if (streq(cur_node->children[j]->label, buf)) {
                        child = cur_node->children[j];
                        break;
                    }
                }
                if (!child) {
                    child = tree_node_new(buf, NULL);
                    tree_node_add_child(cur_node, child);
                    tree->size++;
                }
                cur_node = child;
            }
            buf[i] = label[i];
        }
        free(buf);
        if (!cur_node) return -1;
        tree_node_t *node = tree_node_new(label, value);
        tree_node_add_child(cur_node, node);
        tree->size++;
        return 0;
    }
}
tree_node_t *tree_get_node(tree_t *tree, const char *label) {
    // tree has no nodes
    if (!tree->root) return NULL;
    // label has invalid format
    if (label[0] == '.') return NULL;
    char *buf = malloc(strlen(label)+1);
    memset(buf, '\0', strlen(label)+1);
    tree_node_t *curnode = tree->root;
    for (int i=0;i<strlen(label);i++) {
        if (label[i] == '.') {
            tree_node_t *child = NULL;
            for (int j=0;j<curnode->numchildren;j++) {
                if(streq(curnode->children[j]->label, buf)) {
                    child = curnode->children[j];
                    break;
                }
            }
            if (!child) return NULL;
            else curnode = child;
        }
        buf[i] = label[i];
    }
    tree_node_t *node = NULL;
    for (int i=0;i<curnode->numchildren;i++) {
        if (streq(curnode->children[i]->label, buf)) {
            node = curnode->children[i];
            break;
        }
    }
    free(buf);
    return node;
}
void tree_destroy(tree_t *tree) {
    if (tree->root) tree_node_destroy(tree->root);
    free(tree);
}
