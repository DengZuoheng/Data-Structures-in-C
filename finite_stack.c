#include <string.h>
#include "default_setting.h"
#include "finite_stack.h"

finite_stack_p create_finite_stack(int length)
{
        finite_stack_p stack = 0;
        stack = (finite_stack_p)malloc(sizeof(struct finite_stack));
        
        stack->data = (void**)malloc(sizeof(void*)*length);
        if(!stack->data)
        {
                free(stack);
                return 0;
        }
        stack->max_length = length;
        stack->size = 0;
        return stack;
}

bool finite_stack_push(finite_stack_p stack, void* data, size_t n)
{
        if(stack->size < stack->max_length)
        {
                void* tmp = malloc(n);
                if(tmp)
                {
                        stack->data[stack->size] = tmp;
                        memcpy(stack->data[stack->size], data, n);
                        stack->size++;
                        return true;
                }
        }
        return false;
}

void* finite_stack_top(finite_stack_p stack)
{
        return stack->size>0 ? stack->data[stack->size-1]:0;    
}

bool finite_stack_pop(finite_stack_p stack)
{
        if(stack->size > 0)
        {
                free(finite_stack_top(stack));
                stack->size--;     
        }
        return true;
}

bool finite_stack_empty(finite_stack_p stack)
{
        return stack->size == 0? true:false;
}

bool finite_stack_full(finite_stack_p stack)
{
        return stack->size == stack->max_length ? true:false;
}

int finite_stack_size(finite_stack_p stack)
{
        return stack->size;
}

void* finite_stack_destory(finite_stack_p stack)
{
        int i;
        for(i=0;i<stack->size;++i)
        {
                free(stack->data[i]);
        }
        free(stack->data);
        free(stack);
        stack=0;
        return 0;
}