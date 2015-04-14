#ifndef binary_tree_h
#define binary_tree_h
#include <stdlib.h>
#include "default_setting.h"
#include "list_queue.h"
#include "list_stack.h"

struct btree_node
{
    void* data;
    size_t size;
    struct btree_node* left_child;
    struct btree_node* right_child;
    struct btree_node* parent;
};

typedef struct btree_node* binary_tree_p;
typedef binary_tree_p btree_node_p;

binary_tree_p create_binary_tree();

btree_node_p create_btree_node(void* data, size_t size);

binary_tree_p binary_tree_lchild(binary_tree_p tree);

binary_tree_p binary_tree_rchild(binary_tree_p tree);

void* binary_tree_data(binary_tree_p tree);

bool binary_tree_empty(binary_tree_p tree);

void binary_inorder(binary_tree_p tree, void (*callback)(void*));

void binary_preorder(binary_tree_p tree, void (*callback)(void*));

void binary_postorder(binary_tree_p tree, void (*callback)(void*));

void binary_iter_inorder(binary_tree_p tree, void (*callback)(void*));

void binary_iter_preorder(binary_tree_p tree, void (*callback)(void*));

void binary_iter_postorder(binary_tree_p tree, void (*callback)(void*));

void binary_level(binary_tree_p tree, void(*callback)(void*));

size_t binary_depth(binary_tree_p tree);

void binary_destroy(binary_tree_p tree);

#endif