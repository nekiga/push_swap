/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:36:47 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/18 14:47:42 by garibeir         ###   ########.fr       */
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

	if (stack_b->curlen == 0)
		return (0);
	stack_a->curlen++;
	temp = stack_b->array[0];
	shiftdown(stack_a, stack_b);
	stack_a->array[0] = temp;
	if (stack_b->curlen != 0)
	{
		stack_b->array[stack_b->curlen - 1] = 0;
		stack_b->curlen--;
	}
	else
		stack_b->array[stack_b->curlen] = 0;
	write(1, "pa\n", 3);
	return (0);
}

void	shiftdown(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	i;

	i = stack_a->curlen - 1;
	while (i > 0)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		i--;
	}
	i = 0;
	while (i < stack_b->curlen - 1)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
}

