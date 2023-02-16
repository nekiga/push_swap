/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir <garibeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:38:27 by garibeir          #+#    #+#             */
/*   Updated: 2023/02/16 12:07:15 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int sort2(stack_a *stack_a, stack_b *stack_b)
{
    if (stack_a->array[0] > stack_a->array[1])
        sa(stack_a);
    free(stack_a->array);
    free(stack_b->array);
     exit(0);
}
// sorts numbers if given 3 :D
int sort3(stack_a *stack_a, stack_b *stack_b)
{
   // make func that chekcsi fi tis already sorted
    if (stack_a->array[0] > stack_a->array[1] && stack_a->array[1] < stack_a->array[2]
     && stack_a->array[0] < stack_a->array[2])
        return (sa(stack_a));
    if (stack_a->array[0] > stack_a->array[1] && stack_a->array[1] < stack_a->array[2] && stack_a->array[0] > stack_a->array[2])
        return (ra(stack_a));
    if (stack_a->array[0] > stack_a->array[1] && stack_a->array[1] > stack_a->array[2])
        {
            sa(stack_a);
            rra(stack_a);
            return(0);
        }
     if (stack_a->array[0] < stack_a->array[1] && stack_a->array[1] > stack_a->array[2] && stack_a->array[0] > stack_a->array[2])
    {
        rra(stack_a);
         return(0);
    }
     if (stack_a->array[0] < stack_a->array[1] && stack_a->array[1] > stack_a->array[2])
     {
        sa(stack_a);
        ra(stack_a);
        return(0);
     }
    
    return (1);
}

//sorts nubers if given 5

int sort5(stack_a *stack_a, stack_b *stack_b)
{

    
    toTop(stack_a);
    pb(stack_a, stack_b);
    toTop(stack_a);
    pb(stack_a, stack_b);
    sort3(stack_a, stack_b);
    pa(stack_a, stack_b);
    stack_a->curLen = stack_a->curLen + 2;
    toTop(stack_a);
    stack_a->array[0] = stack_b->array[0];
   stack_a->curLen++;
    return (1);

}
int sort5((stack_a *stack_a, stack_b *stack_b))

long findSmallest(stack_a *stack_a)
{
    if (stack_a->curLen == 0)
    {
        return 0;
    }

    long i = 1;
    long min = stack_a->array[0];
    stack_a->smallest = 0;

    while (i < stack_a->curLen)
    {
        if(stack_a->array[i] < min)
        {
            min = stack_a->array[i];
            stack_a->smallest = i;
        }
        i++;
    }
    return min;
}

int toTop(stack_a *stack_a)
{
    long pos;
    long temp; 
    int i = 10;

    findSmallest(stack_a);
    pos = stack_a->smallest;
    temp = stack_a->array[pos]; 
     if (stack_a->curLen - pos < stack_a->curLen / 2)
    {
         while (stack_a->array[0] != temp && i--) 
        {
           ra(stack_a);
          
        } 
        return (0);
    }
    else
    {
        while (stack_a->array[0] != temp)
        {
            rra(stack_a);
        }
        return (0);
    } 
    return (0);
}
