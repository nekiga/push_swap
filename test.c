#include "push_swap.h"

void    printArray(t_stack_a *stack_a)
{
    int i;

    i = 0;
    printf("\nstack a: ");
    while (i != stack_a->inilen)
    {
        printf("[%ld]",stack_a->array[i]);
        i++;
    }
    printf("\n");
}

void    printArrayb(t_stack_b *stack_b)
{
    int i;

    i = 0;
    printf("\nstack b: ");
    while (i != stack_b->inilen - 1)
    {
        printf("[%ld]", stack_b->array[i]);
        i++;
    }
    printf("\n");
}