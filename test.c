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

void    printArrayb(stack_b stack_b)
{
    int i;

    i = 0;
    while (i != stack_b.iniLen)
    {
        printf("[%ld]", stack_b.array[i]);
        i++;
    }
    printf("\n");
}