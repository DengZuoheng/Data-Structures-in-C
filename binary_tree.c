#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "default_setting.h"
#include "list_stack.h"
#include "list_queue.h"
#include "binary_tree.h"

binary_tree_p create_binary_tree()
{
        binary_tree_p tree = (binary_tree_p)malloc(sizeof(struct btree_node));
        tree->data = NULL;
        tree->parent = NULL;
        tree->left_child = NULL;
        tree->right_child = NULL;
        return tree;
}

btree_node_p create_btree_node(void* data, size_t size)
{
        btree_node_p ret= create_binary_tree();
        ret->data = malloc(size);
        memcpy(ret->data, data, size);
        return ret;
}

binary_tree_p binary_tree_lchild(binary_tree_p tree)
{
        if(tree) return tree->left_child;
        return NULL;
}

binary_tree_p binary_tree_rchild(binary_tree_p tree)
{
        if(tree) return tree->left_child;
        return NULL;
}

void* binary_tree_data(binary_tree_p tree)
{
        return tree->data;
}

bool binary_tree_empty(binary_tree_p tree)
{
        return tree? false:true;
}

void binary_inorder(binary_tree_p tree, void (*callback)(void*))
{
        if(tree&&callback)
        {
                binary_inorder(tree->left_child, callback);
                callback(tree->data);
                binary_inorder(tree->right_child, callback);
        }
}

void binary_preorder(binary_tree_p tree, void (*callback)(void*))
{
        if(tree&&callback)
        {
                callback(tree->data);
                binary_preorder(tree->left_child,callback);
                binary_preorder(tree->right_child,callback);
        }
}

void binary_postorder(binary_tree_p tree, void (*callback)(void*))
{
        if(tree&&callback)
        {
                binary_postorder(tree->left_child,callback);
                binary_postorder(tree->right_child,callback);
                callback(tree->data);
        }
}

void binary_iter_inorder(binary_tree_p tree, void (*callback)(void*))
{
        if (!tree) { return; }
        struct btree_node* node = tree;
        list_stack_p stack = create_list_stack();
        while(true)
        {
                for( ; node; node = node->left_child)
                {
                        list_stack_push(stack, 
                                node, 
                                sizeof(struct btree_node));
                }
                node = list_stack_top(stack);
                if (list_stack_empty(stack) == true) break;
                if (node) callback(node->data);
                node = node->right_child;

                list_stack_pop(stack);
        }
        list_stack_destroy(stack);
}

void binary_iter_preorder(binary_tree_p tree, void (*callback)(void*))
{
        if (!tree) { return; }
        struct btree_node* node = 
            (struct btree_node*)malloc(sizeof(struct btree_node));
        memcpy(node, tree, sizeof(struct btree_node));
        list_stack_p stack = create_list_stack();
        list_stack_push(stack, node, sizeof(struct btree_node));
        while(false==list_stack_empty(stack))
        {
                memcpy(node, list_stack_top(stack), sizeof(struct btree_node));
                list_stack_pop(stack);
                callback(node->data);
                if(node->right_child)
                {
                        list_stack_push(stack,
                                node->right_child,
                                sizeof(struct btree_node));
                }
                if(node->left_child)
                {
                        list_stack_push(stack,
                                node->left_child,
                                sizeof(struct btree_node));
                }  
        }
        free(node);
        list_stack_destroy(stack);
}

void binary_iter_postorder(binary_tree_p tree, void (*callback)(void*))
{
        if (!tree) { return; }
        btree_node_p* cur =
            (btree_node_p*)malloc(sizeof(btree_node_p)); 
        btree_node_p* pre =
            (btree_node_p*)malloc(sizeof(btree_node_p));

        list_stack_p stack = create_list_stack();
        list_stack_push(stack, &tree, sizeof(btree_node_p));
        while(false==list_stack_empty(stack))
        {
                memcpy(cur, list_stack_top(stack), sizeof(btree_node_p));
            
                if ((!(*cur)->left_child && !(*cur)->right_child) ||
                    (*pre == (*cur)->left_child || *pre == (*cur)->right_child))
                {
                        callback((*cur)->data);
                        memcpy(pre, cur, sizeof(btree_node_p));
                        list_stack_pop(stack);
                }
                else
                {
                    if ((*cur)->right_child)
                        {
                                list_stack_push(stack,
                                        &(*cur)->right_child,
                                        sizeof(struct btree_node));
                        }
                    if ((*cur)->left_child)
                        {
                                list_stack_push(stack,
                                        &(*cur)->left_child,
                                        sizeof(struct btree_node));
                        }
                }
        }
        free(cur);
        free(pre);
        list_stack_destroy(stack);
}

void binary_level(binary_tree_p tree, void(*callback)(void*))
{
        if (NULL==tree)
        {
            return;
        }
        list_queue_p queue = create_list_queue();
        
        list_queue_push(queue, tree, sizeof(struct btree_node));
        while(false == list_queue_empty(queue))
        {
                binary_tree_p node = list_queue_front(queue);
                callback(node->data);
                if (node->left_child)
                {
                    list_queue_push(queue,
                        node->left_child,
                        sizeof(struct btree_node));
                }
                if(node->right_child)
                {
                        list_queue_push(queue,
                                node->right_child,
                                sizeof(struct btree_node));
                }
                
                list_queue_pop(queue);
        }
        list_queue_destroy(queue);       
}

size_t binary_depth(binary_tree_p tree)
{
    if(!tree) return 0;
    return 1+max( 
            binary_depth(tree->left_child), 
            binary_depth(tree->right_child));  
}

void binary_destroy(binary_tree_p tree)
{
    if (!tree)
    { 
        return; 
    }
    if (tree->left_child)
    {
        binary_destroy(tree->left_child);
    }
    if (tree->right_child)
    {
        binary_destroy(tree->right_child);
    }
    free(tree->data);
    free(tree);
}
