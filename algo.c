/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir <garibeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:38:27 by garibeir          #+#    #+#             */
/*   Updated: 2023/02/25 15:40:13 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->array[0] > stack_a->array[1])
		sa(stack_a);
}
// sorts numbers if given 3 :D
void sort3(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->array[0] > stack_a->array[1]
		&& stack_a->array[1] < stack_a->array[2]
		&& stack_a->array[0] < stack_a->array[2])
		sa(stack_a);
	else if (stack_a->array[0] > stack_a->array[1]
		&& stack_a->array[1] < stack_a->array[2]
		&& stack_a->array[0] > stack_a->array[2])
		ra(stack_a);
	else if (stack_a->array[0] > stack_a->array[1]
		&& stack_a->array[1] > stack_a->array[2])
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (stack_a->array[0] < stack_a->array[1]
		&& stack_a->array[1] > stack_a->array[2]
		&& stack_a->array[0] > stack_a->array[2])
	{
		rra(stack_a);
	}
	else if (stack_a->array[0] < stack_a->array[1]
		&& stack_a->array[1] > stack_a->array[2])
	{
		sa(stack_a);
		ra(stack_a);
    }
}

//sorts nubers if given 5

void	sort5(t_stack_a *stack_a, t_stack_b *stack_b)
{
	totop(stack_a, stack_b);
	pb(stack_a, stack_b);
    if (stack_a->inilen == 5)
    {
	    totop(stack_a, stack_b);
	    pb(stack_a, stack_b);
    }
    sort3(stack_a, stack_b);
	pa(stack_a, stack_b);
    if (stack_a->inilen == 5)
    {
	    stack_a->curlen = stack_a->curlen + 2;
	    totop(stack_a, stack_b);
	    stack_a->array[0] = stack_b->array[0];
	    stack_a->curlen++;
    }
}
void bubblesort(t_stack_a *stack_a)
 {
    int i;
	i = stack_a->inilen - 1;
    while (i > 0)
	 {
        int j = 0;
        while (j < i)
		 {
            if (stack_a->array[j] > stack_a->array[j + 1])
			 {
                long temp = stack_a->array[j];
               stack_a->array[j] = stack_a->array[j + 1];
                stack_a->array[j + 1] = temp;
            }
            j++;
        }
        i--;
    }
}
void sort100(t_stack_a *stack_a, t_stack_b *stack_b)
{
    long	i;
    long	j;
	long *array;
	long	chunk;
    
    i = 0;
	j = 0;
	chunk = 20;
	//criar um array e ordenalo com os 100 numeros
	array = malloc(sizeof(long) * stack_a->inilen);
	if (!array)
		error(stack_a, stack_b);
	//sort the array
	bubblesort(stack_a);
	// send the values of the chunk to stack_b
	while (!checkSorted(stack_a))
	{
		stack_b->call = true;
		pushchunk(stack_a, stack_b, chunk, array);
		while (i-- < chunk)
			smartpush(stack_a, stack_b);
		chunk =+ 20;
	}
}
//Finds most otimized path to push either the biggest or smallest number to the top
char findsmartpush(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	smallest;
	long	biggest;
	long 	movessmall;
	long	movesbig;
	char	flag;
	// find the smallest
	smallest = findsmallest(stack_a, stack_b, 'b');
	//find biggest
	biggest = findbiggest(stack_a, stack_b, 'b');
	// Check if its faster to ra or rrra
	movessmall = stack_b->smallest - stack_b->curlen + 1;
	movesbig = stack_b->biggest - stack_b->curlen + 1;
	if (stack_b->smallest < movessmall)
		if (stack_b->smallest < stack_b->biggest)
			flag = 's';
	else if (stack_b->smallest < movessmall)
		if (stack_b->smallest > stack_b->biggest)
			flag = 'b';
	else if (stack_b->smallest > movessmall)
		if (movessmall < movesbig)
			flag = 'S';
	else
		flag = 'B';
		
	// Check for the biggest number
	// o que for mais otimizado fazer
	return (flag);
}
// vai receber uma flag que lhe vai dizer que numero mandar com ra ou rra para o top
// vai buscar o numero 
// vai fazer ra ou rra
void	smartpush(t_stack_a *stack_a, t_stack_b *stack_b)
{
	char flag;
	long smallest;
	long biggest;
	
	flag = findsmartpush(stack_a, stack_b);
	smallest = findsmallest(stack_a, stack_b, 'b');
	biggest = findbiggest(stack_a, stack_b, 'b');
	if (flag == 's')
	{
		while (stack_b->array[0] != smallest)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (flag == 'b')
	{
		while (stack_b->array[0] != biggest)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (flag == 'S')
	{
		while (stack_b->array[0] != smallest)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (flag == 'B')
	{
		while (stack_b->array[0] != biggest)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
}
//pushes all members of chunk to stack_b
void pushchunk(t_stack_a *stack_a, t_stack_b *stack_b, long chunk, long *array)
{
	long hold1;
	long hold2;
	static long i;

	if (stack_b->call == true)
	{
		i = 0;
		stack_b->call == false;	
	}
	hold1 = array[20];
	while (i < stack_a->curlen)
	{
		if (stack_a->array[i] < hold1)
			{
				pushtop(stack_a, i);
				pb(stack_a, stack_b);
			}
			i++;
	}
}
long	findsmallest(t_stack_a *stack_a, t_stack_b *stack_b, char flag)
{
	long	i;
	long	min;
	
	i = 1;
	if (flag == 'a')
	{
		if (stack_a->curlen == 0)
			return (0);
		min = stack_a->array[0];
		stack_a->smallest = 0;
		while (i < stack_a->curlen)
		{
			if (stack_a->array[i] < min)
			{
				min = stack_a->array[i];
				stack_a->smallest = i;
			}
			i++;
		}
		return (min);
	}
	if (stack_b->curlen == 0)
		return (0);
	min = stack_b->array[0];
	stack_b->smallest = 0;
	while (i < stack_b->curlen)
	{
		if (stack_b->array[i] < min)
		{
			min = stack_b->array[i];
			stack_b->smallest = i;
		}
		i++;
	}
	return (min);
}

long findbiggest(t_stack_a *stack_a, t_stack_b *stack_b, char flag)
{
    long i;
    long max;

    i = 1;
	if (flag == 'a')
	{
		if (stack_a->curlen == 0)
       		 return (0);
  	 	max = stack_a->array[0];
  	 	stack_a->biggest = 0;
   		while (i < stack_a->curlen)
    	{
       	 	if (stack_a->array[i] > max)
        		{
            		max = stack_a->array[i];
           			stack_a->biggest = i;
       			}
      	  		i++;
    	}
   		 return (max);
	}
	
    if (stack_b->curlen == 0)
        return (0);
    max = stack_b->array[0];
    stack_b->biggest = 0;
    while (i < stack_b->curlen)
    {
        if (stack_b->array[i] > max)
        {
            max = stack_a->array[i];
            stack_b->biggest = i;
        }
        i++;
    }
    return (max);
}


void totop(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	pos;
	long	temp;

	findsmallest(stack_a, stack_b, 'a');
	pos = stack_a->smallest;
	temp = stack_a->array[pos];
	if (stack_a->curlen - pos < stack_a->curlen / 2)
		while (stack_a->array[0] != temp)
			ra(stack_a);
	else
		while (stack_a->array[0] != temp)
			rra(stack_a);
}

void pushtop(t_stack_a *stack_a, long i)
{
	long	pos;
	long	temp;

	pos =  stack_a->array[i];
	temp = stack_a->array[pos];
		while (stack_a->array[0] != temp)
			ra(stack_a);
}