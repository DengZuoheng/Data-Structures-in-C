#include <assert.h>
#include <stdio.h>
#include "default_setting.h"
#include "finite_stack.h"

int main(int argc, char** argv)
{
        int num = 10;
        int i = 0;
        int* tmp;
        printf("%d\n", sizeof(struct finite_stack));
        while (1)
        {          
                i = 0;
                num = 10;
                finite_stack_p stack = create_finite_stack(num);
                while(false == finite_stack_full(stack))
                {
                        finite_stack_push(stack, &i, sizeof(int));
                        assert(*(int*)finite_stack_top(stack) == i);
                        i++;
                }
                assert(finite_stack_full(stack)==true);
                assert(finite_stack_size(stack)==10);
                tmp = (int*)finite_stack_top(stack);
                assert(*tmp == 9);

                finite_stack_pop(stack);
                assert(finite_stack_size(stack)==9);

                tmp = (int*)finite_stack_top(stack);
                assert(*tmp == 8);

                finite_stack_pop(stack);    
                finite_stack_pop(stack);
                finite_stack_pop(stack);
                finite_stack_pop(stack);
                assert(finite_stack_size(stack)==5);

                tmp = (int*)finite_stack_top(stack);
                assert(*tmp == 4);

                finite_stack_pop(stack);
                finite_stack_pop(stack);
                finite_stack_pop(stack);
                finite_stack_pop(stack);
                assert(finite_stack_size(stack)==1);
                tmp = (int*)finite_stack_top(stack);
                assert(*tmp == 0);

                finite_stack_pop(stack);
                assert(finite_stack_size(stack)==0);
                assert(true == finite_stack_empty(stack));
        
                i=-1;
                finite_stack_push(stack, &i, sizeof(int));
                tmp = (int*)finite_stack_top(stack);
                assert(*tmp == -1);
                assert(finite_stack_size(stack)==1);
                assert(finite_stack_destroy(stack)==0);
        }
        return 0;
}