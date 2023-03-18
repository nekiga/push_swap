/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxalgo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:24:40 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/18 13:54:44 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dosmartpush(t_stack_a *stack_a, t_stack_b *stack_b, long chunk)
{
	long	i;

	i = 0;
	while (i++ <= chunk)
		smartpush(stack_a, stack_b, chunk);
}

long	findsmallestb(t_stack_b *stack_b, long chunk)
{
	long	min;
	long	i;

	i = 0;
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

long	findbiggestb(t_stack_b *stack_b)
{
	long	i;
	long	max;

	max = stack_b->array[0];
	stack_b->biggest = 0;
	i = 0;
	while (i < stack_b->curlen)
	{
		if (stack_b->array[i] > max)
		{
			max = stack_b->array[i];
			stack_b->biggest = i;
		}
		i++;
	}
	return (max);
}

void	dofind(t_stack_a *stack_a, t_stack_b *stack_b, long chunk)
{
	findsmallest(stack_a, stack_b, 'b', chunk);
	findbiggest(stack_a, stack_b, 'b');
}

