#include "push_swap.h"

// sorts numbers if given 3 
int sort3(stack_a stack_a, stack_b stack_b)
{
    if (stack_a.array[0] < stack_a.array[1] && stack_a.array[1] < stack_a.array[2])
         return(0);
    if (stack_a.array[0] > stack_a.array[1] && stack_a.array[1] < stack_a.array[2])
        return (sa(stack_a));
    if (stack_a.array[0] > stack_a.array[1] && stack_a.array[1] > stack_a.array[2])
        {
            sa(stack_a);
            rra(stack_a);
            return(0);
        }
     if (stack_a.array[0] < stack_a.array[1] && stack_a.array[1] > stack_a.array[2])
    {
        rra(stack_a);
         return(0);
    }
     if (stack_a.array[0] < stack_a.array[1] && stack_a.array[1] > stack_a.array[2])
     {
        sa(stack_a);
        ra(stack_a);
        return(0);
     }
    
    return (1);
}