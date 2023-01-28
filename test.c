#include "push_swap.h"

void    printArray(stack_a stack_a)
{
    int i;

    i = 0;
    while (i != stack_a.iniLen)
    {
        printf("[%ld]",stack_a.array[i]);
        i++;
    }
    printf("\n");
}