#include "sort.h"
#include "memory.h"
#include <stdlib.h>
#include <stddef.h>

size_t _quick_sort_partition(void* base, size_t num, size_t size,
        int (*compar)(const void*, const void*))
{
        char* arr = (char*)base;
        size_t i;
        size_t small_len = 0;
        size_t begin_i = 0;
        size_t pivot_i = 0;
       
        mem_swap(&arr[pivot_i], &arr[pivot_i+(num-1)*size], size);
        pivot_i = pivot_i + (num - 1)*size;
        for(i=0; i<num; i++)
        {
               
                if( compar(&arr[begin_i+i*size], &arr[pivot_i]) < 0 )
                {
                        mem_swap(&arr[begin_i+i*size], &arr[small_len*size], size);             
                        ++small_len;
                }
        }
        
        mem_swap(&arr[pivot_i], &arr[small_len*size], size);
        return small_len;

}

void quick_sort (void* base, size_t num, size_t size,
            int (*compar)(const void*, const void*))
{
        char* arr = (char*)base;
        if(num <= 1) return;
        int small_len = _quick_sort_partition(arr, num, size, compar);
        quick_sort(arr, small_len, size, compar);
        quick_sort(&arr[(small_len+1)*size], num-small_len-1, size, compar);
}

