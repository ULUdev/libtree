#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>
#include "node.h"
#include "tree.h"

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
        cmocka_unit_test(tree_create),
        cmocka_unit_test(tree_add_and_find_node),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
