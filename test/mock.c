#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>
#include <string.h>
#include "node.h"
#include "tree.h"

static void node_create(void **state) {
    tree_node_t *node = tree_node_new("Hello, World", NULL);
    assert_non_null(node);
    tree_node_destroy(node);
}

// test whether or not the label is actually copied
static void node_label_cpy(void **state) {
    char *label = malloc(4);
    strcpy(label, "abc");
    tree_node_t *node = tree_node_new(label, NULL);
    assert_non_null(node);
    free(label);
    assert_string_equal(node->label, "abc");
}

static void tree_create(void **state) {
    tree_t *tree = tree_new();
    assert_non_null(tree);
    tree_destroy(tree);
}

static void tree_add_and_find_node(void **state) {
    tree_t *tree = tree_new();
    int res = tree_add_node(tree, "x.y.z", (void *) "Hello, World");
    assert_int_equal(res, 0);
    // the four nodes should be '.', 'x', 'x.y' and 'x.y.z'
    assert_int_equal(tree->size, 4);
    tree_node_t *node = tree_get_node(tree, "x.y.z");
    assert_non_null(node);
    assert_string_equal(node->value, (void *) "Hello, World");
    tree_destroy(tree);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(node_create),
        cmocka_unit_test(node_label_cpy),
        cmocka_unit_test(tree_create),
        cmocka_unit_test(tree_add_and_find_node),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
