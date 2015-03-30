#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
void quick_sort (void* base, size_t num, size_t size,
            int (*compar)(const void*,const void*));

size_t _quick_sort_partition(void* base, size_t num, size_t size,
    int (*compar)(const void*,const void*));

void shell_sort(void* base, size_t num, size_t size,
            int (*compar)(const void*,const void*));   


#endif