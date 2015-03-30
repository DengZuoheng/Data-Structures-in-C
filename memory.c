#include "memory.h"

void mem_swap (void * lhs, void * rhs, size_t size)
{
        register char * byte1 = (char *)(lhs);
        register char * byte2 = (char *)(rhs);
        register char temp;
        if (lhs != rhs)
        {
            while (size--)
            {
                    temp = *byte1;
                    *byte1++ = *byte2;
                    *byte2++ = temp;
            }
        } 
        return;
}