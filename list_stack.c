#include <stdlib.h>
#include "list_stack.h"
#include "default_setting.h"
#include "list.h"

list_stack_p create_list_stack()
{
        list_stack_p stack = (list_stack_p)malloc(sizeof(struct list_stack));
        stack->list = create_list();
        return stack;
}

bool list_stack_push(list_stack_p stack, void* data, size_t n)
{
        list_push_back(stack->list, data, n);
        return true;
}

bool list_stack_pop(list_stack_p stack)
{
        list_pop_back(stack->list);
        return true;
}
/*Get the top item of the stack. */
void* list_stack_top(list_stack_p stack)
{
        return list_back(stack->list);
}
/*Test whether the stack is empty or not. */
bool list_stack_empty(list_stack_p stack)
{
        return list_empty(stack->list);
}
/*Test whether the stack is full or not. */
size_t list_stack_size(list_stack_p stack)
{
        return list_size(stack->list);
}
/*Destory the stack and free all the memory associated with it. */
void* list_stack_destroy(list_stack_p stack)
{
        list_destroy(stack->list);
        free(stack);
        return NULL;
}