/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:12:28 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/18 14:52:10 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//pb (push b): Take the first element at the top of a 
//and put it at the top of b->
//Do nothing if a is empty->

int	pb(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	temp;

	if (stack_a->curlen == 0)
		return (0);
	stack_b->curlen++;
	temp = stack_a->array[0];
	shiftdownb(stack_a, stack_b);
	stack_b->array[0] = temp;
	if (stack_a->curlen != 0)
	{
		stack_a->array[stack_a->curlen - 1] = 0;
		stack_a->curlen--;
	}
	else
		stack_a->array[stack_a->curlen] = 0;
	write(1, "pb\n", 3);
	return (0);
}

//ra (rotate a): Shift up all elements of stack a by 1->
//The first element becomes the laist one-> :d
int	ra(t_stack_a *stack_a)
{
	long	temp;
	long	i;

	if (stack_a->curlen <= 0)
		return (-1);
	temp = stack_a->array[0];
	i = 0;
	while (i < stack_a->curlen - 1)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->array[stack_a->curlen - 1] = temp;
	write(1, "ra\n", 3);
	return (0);
}

//rb (rotate b): Shift up all elements of stack b by 1->
//The first element becomes the last one-> :d
int	rb(t_stack_b *stack_b)
{
	long	temp;
	long	i;

	if (stack_b->curlen <= 0)
	{
		return (-1);
	}
	temp = stack_b->array[0];
	i = 0;
	while (i < stack_b->curlen - 1)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
	stack_b->array[stack_b->curlen - 1] = temp;
	write(1, "rb\n", 3);
	return (0);
}

//rra (reverse rotate a): Shift down all elements of stack a by 1->
//The last element becomes the first one->
int	rra(t_stack_a *stack_a)
{
	long	temp;
	long	templast;
	long	i;

	templast = stack_a->array[stack_a->curlen - 1];
	i = stack_a->curlen - 1;
	while (i > 0)
	{
		temp = stack_a->array[i];
		stack_a->array[i] = stack_a->array[i - 1];
		stack_a->array[i - 1] = temp;
		i--;
	}
	stack_a->array[0] = templast;
	write(1, "rra\n", 4);
	return (0);
}

//rrb (reverse rotate b): Shift down all elements of stack b by 1->
//The last element becomes the first one-> !!
int	rrb(t_stack_b *stack_b)
{
	long	temp;
	long	templast;
	long	i;

	templast = stack_b->array[stack_b->curlen - 1];
	i = stack_b->curlen - 1;
	while (i > 0)
	{
		temp = stack_b->array[i];
		stack_b->array[i] = stack_b->array[i - 1];
		stack_b->array[i - 1] = temp;
		i--;
	}
	stack_b->array[0] = templast;
	write(1, "rrb\n", 4);
	return (0);
}
