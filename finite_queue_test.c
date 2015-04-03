#include <assert.h>
#include <stdio.h>
#include "default_setting.h"
#include "finite_queue.h"

int main(int argc, char** argv)
{
    int num = 10;
    int i = 0;
    printf("%d\n", sizeof(struct finite_queue));
    while (1)
    {
            i = 0;
            num = 10;
            finite_queue_p queue = create_finite_queue(num);
            while (false == finite_queue_full(queue))
            {
                    finite_queue_push(queue, &i, sizeof(int));
                    assert(i == *(int*)finite_queue_back(queue));
                    assert(0 == *(int*)finite_queue_front(queue));
                    i++;
            }
            assert(finite_queue_full(queue) == true);
            assert(finite_queue_size(queue) == 10);
            finite_queue_pop(queue);
            assert(1 == *(int*)finite_queue_front(queue));
            finite_queue_pop(queue);
            assert(2 == *(int*)finite_queue_front(queue));
            finite_queue_pop(queue);
            assert(3 == *(int*)finite_queue_front(queue));
            finite_queue_pop(queue);
            assert(4 == *(int*)finite_queue_front(queue));

            assert(6 == finite_queue_size(queue));
            assert(false == finite_queue_full(queue));
            i = 99;
            while (false == finite_queue_full(queue))
            {
                finite_queue_push(queue, &i, sizeof(int));
                assert(i == *(int*)finite_queue_back(queue));
                assert(4 == *(int*)finite_queue_front(queue));
                i++;
            }
            while (3 < finite_queue_size(queue))
            {
                finite_queue_pop(queue);
            }
            assert(100 == *(int*)finite_queue_front(queue));
            assert(102 == *(int*)finite_queue_back(queue));
            i = 1024;
            finite_queue_push(queue, &i, sizeof(int));
            finite_queue_pop(queue);
            finite_queue_pop(queue);
            finite_queue_pop(queue);
            assert(1 == finite_queue_size(queue));
            assert(1024 == *(int*)finite_queue_front(queue));
            assert(1024 == *(int*)finite_queue_back(queue));
            assert(finite_queue_destroy(queue) == 0);
        
    }
    return 0;
}