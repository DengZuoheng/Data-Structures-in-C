#ifndef FINITE_QUEUE_H
#define FINITE_QUEUE_H

#include <stdlib.h>
#include "default_setting.h"

struct finite_queue_node
{
        void* pointer;
};

typedef struct finite_queue_node finite_queue_node;

struct finite_queue
{
        void** data;
        size_t front;
        size_t back;
        size_t max_length;
        size_t size;
};

typedef struct finite_queue* finite_queue_p;

finite_queue_p create_finite_queue(size_t length);

bool finite_queue_push(finite_queue_p queue, void* data, size_t n);

bool finite_queue_pop(finite_queue_p queue);

void* finite_queue_front(finite_queue_p queue);

void* finite_queue_back(finite_queue_p queue);

size_t finite_queue_size(finite_queue_p queue);

bool finite_queue_full(finite_queue_p queue);

bool finite_queue_empty(finite_queue_p queue);

void* finite_queue_destory(finite_queue_p queue);


#endif