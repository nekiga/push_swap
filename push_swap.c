#include "push_swap.h"

 /* int push_swap( stack_a stack_a, stack_b stack_b)
{
    if (stack_a.iniLen == 3)
        sort3(stack_a, stack_b);
    return (0);
} */


// The function main creates the stacks and sends them to push swap
//refactor main

int main(int argc, char **argv)
{
    stack_a stack_a;
    stack_b stack_b;

    if (argc == 1)
        return(error());
    stack_a.array = mArray(argc, argv);
    if (!stack_a.array)
        return(error());
    stack_b.array = malloc(sizeof(long) * argc - 1);
    stack_a.iniLen = argc - 1; 
    stack_a.curLen = stack_a.iniLen;
    stack_b.iniLen = stack_a.iniLen;
    stack_b.curLen = stack_a.iniLen;
    if (!checkArgs(stack_a))
       return(error());
    printArray(stack_a);
    free(stack_b.array);
    free(stack_a.array);
    return (0);
}
