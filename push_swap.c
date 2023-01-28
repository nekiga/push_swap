#include "push_swap.h"

/* int push_swap( stack_a stack_a, stack_b stack_b)
{
    return (0);
}
 */
int main(int argc, char **argv)
{
    long i;
    long len;
    stack_a stack_a;
    stack_b stack_b;
    long *tArr;

    i = 1;
    len = 0;
    if (argc == 1)
        return(1);
    stack_a.array = mArray(argc, argv);
    if (!stack_a.array)
        return (1);
    stack_a.iniLen = argc - 1; 
    stack_a.curLen = stack_a.iniLen; // Really need a function that calculates the current size of the array
    ra(stack_a);

    printArray(stack_a);
    return (0);
}