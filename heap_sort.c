#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "memory.h"

int heap_sort_left_child(int i)
{
        return 2*i+1;
}

void heap_prec_down(void* base, int begin, size_t num, size_t size,
            int (*compar)(const void*,const void*))
{
        int child;
        char* arr = (char*)base;
        void* tmp = malloc(size);
        memcpy(tmp,&arr[(begin)*size],size);
        for(;heap_sort_left_child(begin)<num;begin=child)
        {
                child = heap_sort_left_child(begin);
                if(child != num-1 &&
                        compar(&arr[child*size],&arr[child*size+size])<0)
                {
                        child++;
                }
                if(compar(tmp, &arr[child*size])<0)
                {
                        memcpy(&arr[begin*size], &arr[child*size], size);
                }
                else
                {
                        break;
                }
        }
        memcpy(&arr[begin*size], tmp, size);
        free(tmp);
}

void heap_sort(void* base, size_t num, size_t size,
        int (*compar)(const void* , const void*))
{
        char* arr = base;
        for(int i= num/2;i>=0;i--)
        {
                heap_prec_down(base,i,num,size,compar);
        }
        for (size_t j = num - 1; j>0; j--)
        {
                mem_swap(base,&arr[j*size],size);
                heap_prec_down(base,0,j,size,compar);
        }
}
