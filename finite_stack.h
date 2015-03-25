#ifndef FINITE_STACK_H
#define FINITE_STACK_H

#include <stdlib.h>
#include "default_setting.h"

struct finite_stack
{
        void** data;
        int max_length;
        int size;
};

typedef struct finite_stack* finite_stack_p;

finite_stack_p create_finite_stack(int length);

bool finite_stack_push(finite_stack_p stack, void* data, size_t n);

bool finite_stack_pop(finite_stack_p stack);

void* finite_stack_top(finite_stack_p stack);

bool finite_stack_empty(finite_stack_p stack);

bool finite_stack_full(finite_stack_p stack);

int finite_stack_size(finite_stack_p stack);

void* finite_stack_destory(finite_stack_p stack);

#endif