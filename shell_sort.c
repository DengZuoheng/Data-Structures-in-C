#include "sort.h"
#include <string.h>
void shell_sort(void* base, size_t num, size_t size,
            int (*compar)(const void*,const void*))
{
        int gap;
        int i,j;
        void* ptmp = (void*)malloc(size);
        char* arr = (char*)base;
        for(gap=num/2;gap>0;gap/=2)
        {
                for(i=gap;i<num;++i)
                {
                        memcpy(ptmp, &arr[i*size], size);
                        for(j = i-gap;
                            j >= 0 && compar(ptmp,&arr[j*size])<0;
                            j -= gap)
                        {
                            memcpy(&arr[(j + gap)*size], &arr[j*size],
                                    size);
                        }
                        memcpy(&arr[(j + gap)*size], ptmp,
                            size);

                }
                
        }
        free(ptmp);
}