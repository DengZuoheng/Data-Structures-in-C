#ifndef FINITE_STACK_H
#define FINITE_STACK_H

/* A C implementation of a finite_stack, or static stack */

#include <stdlib.h>
#include "default_setting.h"

struct finite_stack
{
        void** data;
        size_t max_length;
        size_t size;
};

typedef struct finite_stack* finite_stack_p;

/*Create a finite_stack object. It's max size is length and it be
    destoryed by calling finite_stack_destory to avoid memory leaks. */
finite_stack_p create_finite_stack(size_t length);
/*Push a new item to the top of stack. */
bool finite_stack_push(finite_stack_p stack, void* data, size_t n);
/*Pop the top item of the stack and free its memory.*/
bool finite_stack_pop(finite_stack_p stack);
/*Get the top item of the stack. */
void* finite_stack_top(finite_stack_p stack);
/*Test whether the stack is empty or not. */
bool finite_stack_empty(finite_stack_p stack);
/*Test whether the stack is full or not. */
bool finite_stack_full(finite_stack_p stack);
/*Get the size of the stack. */
size_t finite_stack_size(finite_stack_p stack);
/*Destory the stack and free all the memory associated with it. */
void* finite_stack_destory(finite_stack_p stack);

#endif