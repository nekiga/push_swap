#include "push_swap.h"

  int push_swap( stack_a stack_a, stack_b stack_b)
{
    if (stack_a.iniLen == 3)
        sort3(stack_a, stack_b);
    return (0);
} 


// The function main creates the stacks and sends them to push swap
//refactor main
//!! CHECK INPUT ALPHABETICAL
int main(int argc, char **argv)
{
    stack_a stack_a;
    stack_b stack_b;
    long    i;

    i = 0;
    if (argc == 1)
        return(error(stack_a,stack_b));
    if (onlydigit(argc, argv) == false)
        return (error(stack_a, stack_b));
    stack_a.array = mArray(argc, argv);
    if (!stack_a.array)
        return(error(stack_a,stack_b));
    stack_b.array = malloc(sizeof(long) * argc - 1);
    if (!stack_b.array)
        return(error(stack_a,stack_b));
    stack_a.iniLen = argc - 1; 
    stack_a.curLen = stack_a.iniLen;
    stack_b.iniLen = stack_a.iniLen;
    stack_b.curLen = stack_a.iniLen;
    if (!checkArgs(stack_a))
       return(error(stack_a,stack_b));
    push_swap(stack_a, stack_b);
    printArray(stack_a);
    free(stack_b.array);
    free(stack_a.array);
    return (0);
}
