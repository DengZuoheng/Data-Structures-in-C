#include "sort.h"
#include <assert.h>
#include <stdio.h>
#include <time.h>
#define MAX_SIZE 5000000
int cmp(const void* lhs,const void* rhs)
{
        const double* l=(double*)lhs;
        const double* r=(double*)rhs;
        if(*l>*r)
        {
                return 1;
        }
        else if(*l<*r)
        {
                return -1;
        }
        else 
        {
                return 0;
        }
}

double arr1[MAX_SIZE];
double arr2[MAX_SIZE];

int main()
{
        int i=0;
        clock_t t1;
        clock_t t2;
        srand((unsigned int)time(NULL));
        for(i=0;i<MAX_SIZE;++i)
        {
                arr1[i]=rand();
                arr2[i]=arr1[i];
        }
        t1=clock();
        shell_sort(arr1,MAX_SIZE,sizeof(double),cmp);
        t2=clock();
        printf("shell_sort:%d\n",t2-t1);
        t1 = clock();
        qsort(arr2,MAX_SIZE,sizeof(double),cmp);
        t2=clock();
        printf("qsort:%d\n",t2-t1);
        for(i=0;i<MAX_SIZE;++i)
        {
            assert(arr1[i]==arr2[i]);
        }
        
        return 0;
}