/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxalgo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:59:41 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/18 14:09:11 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	findsmartpush(t_stack_a *stack_a, t_stack_b *stack_b, long chunk)
{
	long	paths;
	long	pathb;
	char	flag;

	findsmallest(stack_a, stack_b, 'b', chunk);
	findbiggest(stack_a, stack_b, 'b');
	if (stack_b->curlen - stack_b->smallest > stack_b->smallest)
		paths = stack_b->smallest;
	else
		paths = (stack_b->curlen - stack_b->smallest) * -1;
	if (stack_b->curlen - stack_b->biggest > stack_b->biggest)
		pathb = stack_b->biggest;
	else
		pathb = (stack_b->curlen - stack_b->biggest) * -1;
	if (m_abs(paths) < m_abs(pathb))
	{
		if (paths)
			flag = 's';
		else
			flag = 'S';
	}
	else
		flag = 'B';
	return (flag);
}

long	findsmallest(t_stack_a *stack_a, t_stack_b *stack_b, char flag,
		long chunk)
{
	long	i;
	long	min;

	i = 0;
	if (flag == 'a')
	{
		min = stack_a->array[0];
		stack_a->smallest = 0;
		while (i < stack_a->curlen && chunk <= stack_a->curlen)
		{
			if (stack_a->array[chunk] < min)
			{
				min = stack_a->array[chunk];
				stack_a->smallest = i;
			}
			chunk++;
			i++;
		}
		return (min);
	}
	min = findsmallestb(stack_b, chunk);
	return (min);
}

long	findbiggest(t_stack_a *stack_a, t_stack_b *stack_b, char flag)
{
	long	i;
	long	max;

	i = 0;
	if (flag == 'a')
	{
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
	max = findbiggestb(stack_b);
	return (max);
}

void	totop(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	pos;
	long	temp;

	findsmallest(stack_a, stack_b, 'a', stack_a->inilen);
	pos = stack_a->smallest;
	temp = stack_a->array[pos];
	if (pos < m_abs(stack_a->curlen - pos))
		while (stack_a->array[0] != temp)
			ra(stack_a);
	else
		while (stack_a->array[0] != temp)
			rra(stack_a);
}

void	smartpush(t_stack_a *stack_a, t_stack_b *stack_b, long chunk)
{
	char	flag;

	flag = findsmartpush(stack_a, stack_b, chunk);
	dofind(stack_a, stack_b, chunk);
	if (flag == 's' || flag == 'S')
	{
		smarttop(stack_a, stack_b, stack_b->smallest);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else
	{
		smarttop(stack_a, stack_b, stack_b->biggest);
		pa(stack_a, stack_b);
	}
}
