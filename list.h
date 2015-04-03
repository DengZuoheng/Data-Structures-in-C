#ifndef LIST_H
#define LIST_H
#include "default_setting.h"

struct linked_node
{
        void* data;
        size_t size;
        struct linked_node* next;
        struct linked_node* prev;
};

typedef struct linked_node* lnode_p;

struct list
{
        int size;
        lnode_p head;
        lnode_p tail;
};

typedef struct list* list_p;

struct list_iter
{
        lnode_p current;
};

typedef struct list_iter* list_iter_p;

list_p create_list();

list_iter_p list_iter_begin(list_p list);

list_iter_p list_iter_rbegin(list_p list);

bool list_iter_end(list_iter_p iter);

bool list_iter_rend(list_iter_p iter);

void list_push_back(list_p list, void* data, size_t size);

void list_push_front(list_p list, void* data, size_t size);

void list_pop_back(list_p list);

void list_pop_front(list_p list);

void list_insert(list_p list, list_iter_p iter, void* data, size_t size);

list_iter_p list_remove(list_p list, list_iter_p iter);

void* list_iter_deref(list_iter_p iter);

void* list_iter_next_deref(list_iter_p iter);

void* list_iter_prev_deref(list_iter_p iter);

bool list_iter_has_next(list_iter_p iter);

bool list_iter_has_prev(list_iter_p iter);

void list_iter_next(list_iter_p iter);

void list_iter_prev(list_iter_p iter);

void* list_front(list_p list);

void* list_back(list_p list);

size_t list_size(list_p list);

bool list_empty(list_p list);

void* list_destroy(list_p list);

void* list_iter_destroy(list_iter_p iter);

void list_sort(list_p list, int(*compar)(const void*, const void*));

list_p list_merge(list_p list1, list_p list2);

void list_merge_to(list_p listd, list_p lists);


#endif