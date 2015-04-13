#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include <stdlib.h>
#include "default_setting.h"
#include "list.h"

struct list_queue
{
        list_p list;
};

typedef struct list_queue* list_queue_p;

list_queue_p create_list_queue();

bool list_queue_push(list_queue_p queue, void* data, size_t n);

bool list_queue_pop(list_queue_p queue);

void* list_queue_front(list_queue_p queue);

void* list_queue_back(list_queue_p queue);

size_t list_queue_size(list_queue_p queue);

bool list_queue_empty(list_queue_p queue);

void* list_queue_destroy(list_queue_p queue);

#endif

