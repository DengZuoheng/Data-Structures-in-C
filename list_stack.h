#ifndef LIST_STACK_H
#define LIST_STACK_H

#include <stdlib.h>
#include "list.h"
#include "default_setting.h"

struct list_stack
{
        list_p list;
};

typedef struct list_stack* list_stack_p;

list_stack_p create_list_stack();

bool list_stack_push(list_stack_p stack, void* data, size_t n);

bool list_stack_pop(list_stack_p stack);
/*Get the top item of the stack. */
void* list_stack_top(list_stack_p stack);
/*Test whether the stack is empty or not. */
bool list_stack_empty(list_stack_p stack);
/*Test whether the stack is full or not. */
size_t list_stack_size(list_stack_p stack);
/*Destory the stack and free all the memory associated with it. */
void* list_stack_destroy(list_stack_p stack);

#endif