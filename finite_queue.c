#include <string.h>
#include "default_setting.h"
#include "finite_queue.h"

finite_queue_p create_finite_queue(size_t length)
{
        finite_queue_p queue = 0;
        queue = (finite_queue_p)malloc(sizeof(struct finite_queue));
        if(!queue)
        {
                return queue;
        }
        queue->data = (void**)malloc(sizeof(void*)*length);
        if(!queue->data)
        {
                free(queue);
                return 0;
        }
        queue->max_length = length;
        queue->size = 0;
        queue->front = 0;
        queue->back = -1;
        return queue;
}

bool finite_queue_push(finite_queue_p queue, void* data, size_t n)
{
        if(queue->size < queue->max_length)
        {
                void* tmp = malloc(n);
                if(tmp)
                {
                        size_t diff = queue->back + 1;
                        queue->back = diff % queue->max_length;
                        queue->data[queue->back] = tmp;
                        memcpy(tmp, data, n);
                        queue->size++;
                        return true;

                }
        }
        return false;
}

bool finite_queue_pop(finite_queue_p queue)
{
        if(queue->size > 0)
        {
                size_t bp = queue->front;
                queue->front = (queue->front + 1) % queue->max_length;
                queue->size--;
                free(queue->data[bp]);
        }
        return true;
}

void* finite_queue_front(finite_queue_p queue)
{
        return queue->size > 0 ? queue->data[queue->front] : 0;
}

void* finite_queue_back(finite_queue_p queue)
{
        return queue->size > 0 ? queue->data[queue->back] : 0;
}

size_t finite_queue_size(finite_queue_p queue)
{
        return queue->size;
}

bool finite_queue_full(finite_queue_p queue)
{
        return queue->size==queue->max_length? true:false;
}

bool finite_queue_empty(finite_queue_p queue)
{
        return queue->size==0? true:false;
}

void* finite_queue_destory(finite_queue_p queue)
{
        size_t begin=queue->front;
        while(begin != queue->back)
        {
                free(queue->data[begin]);
                begin = (begin + 1)%queue->max_length;
        }
        free(queue->data[queue->back]);
        free(queue->data);
        free(queue);
        return 0;
}