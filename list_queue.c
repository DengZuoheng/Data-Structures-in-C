#include <stdlib.h>
#include "default_setting.h"
#include "list.h"
#include "list_queue.h"

list_queue_p create_list_queue()
{
        list_queue_p queue = (list_queue_p)malloc(sizeof(struct list_queue));
        queue->list = create_list();
        return queue;
}

bool list_queue_push(list_queue_p queue, void* data, size_t n)
{
        list_push_back(queue->list, data, n);
        return true;
}

bool list_queue_pop(list_queue_p queue)
{
        list_pop_front(queue->list);
        return true;
}

void* list_queue_front(list_queue_p queue)
{
        return list_front(queue->list);
}

void* list_queue_back(list_queue_p queue)
{
        return list_back(queue->list);
}

size_t list_queue_size(list_queue_p queue)
{
        return list_size(queue->list);
}

bool list_queue_empty(list_queue_p queue)
{
        return list_empty(queue->list);
}

void* list_queue_destroy(list_queue_p queue)
{
        list_destroy(queue->list);
        free(queue);
        return NULL;
}
