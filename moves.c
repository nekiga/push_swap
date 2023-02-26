/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:12:28 by garibeir          #+#    #+#             */
/*   Updated: 2023/02/26 17:24:27 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa (swap a): Swap the first 2 elements at the top of stack a->
//Do nothing if there is only one or no elements-> :D
int	sa(t_stack_a *stack_a)
{
	long	temp;

	if (stack_a->curlen < 2)
		return (1);
	temp = stack_a->array[0];
	stack_a->array[0] = stack_a->array[1];
	stack_a->array[1] = temp;
	write(1, "sa\n", 3);
	return (0);
}

//sb (swap b): Swap the first 2 elements at the top of stack b->
//Do nothing if ther is only one or no elements-> :d
int	sb(t_stack_b *stack_b)
{
	long	temp;

	if (stack_b->curlen < 2)
		return (1);
	temp = stack_b->array[0];
	stack_b->array[0] = stack_b->array[1];
	stack_b->array[1] = temp;
	write(1, "sb\n", 3);
	return (0);
}

//ss : sa and sb at the same time->
int	ss(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	temp;

	temp = stack_a->array[0];
	stack_a->array[0] = stack_a->array[1];
	stack_a->array[1] = temp;
	temp = stack_b->array[0];
	stack_b->array[0] = stack_b->array[1];
	stack_b->array[1] = temp;
	write(1, "ss\n", 3);
	return (0);
}

//pa (push a): Take the first element at the top of b 
//and put it at the top of a->
//Do nothing if b is empty
int	pa(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	temp;
	long	i;

	stack_a->curlen++;
	i = stack_a->curlen - 1;
	temp = stack_b->array[0];
	while (i > 0)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		//printf("in func pa i = %ld\n in func pa stack_a->array[i] = %ld\n", i , stack_a->array[i]);
		i--;
	}
	stack_a->array[0] = temp;
	i = 0;
	while (i < stack_b->curlen - 1)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
	stack_b->array[stack_b->curlen - 1] = 0;
	stack_b->curlen--;
	write(1, "pa\n", 3);
	return (0);
}
//pb (push b): Take the first element at the top of a 
//and put it at the top of b->
//Do nothing if a is empty->

int	pb(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	temp;
	long	i;

	stack_b->curlen++;
	i = stack_b->curlen - 1;
	if (!checkIfArray(stack_a->array))
		return (1);
	temp = stack_a->array[0];
	while (i >= 0)
	{
		stack_b->array[i + 1] = stack_b->array[i];
		i--;
	}
	stack_b->array[0] = temp;
	i = 0;
	while (i < stack_a->curlen - 1)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->array[stack_a->curlen - 1] = 0;
	stack_a->curlen--;
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

//rr : ra and rb at the same time->
int	rr(t_stack_a *stack_a, t_stack_b *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
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
//rrr : rra and rrb at the same time->
int	rrr(t_stack_a *stack_a, t_stack_b *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
	return (0);
}