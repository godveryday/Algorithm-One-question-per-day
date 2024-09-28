#include<stdio.h>
#include "queue_array_mutual.h"

int main()
{
    queue_t *ptr = create_queue(3);
    for(int i=0; i<5; i++)
    {
        enqueue(ptr, 3);
    }


    return 0;
}