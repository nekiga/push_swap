/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxalgo1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:03:02 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/18 12:24:26 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smarttop(t_stack_a *stack_a, t_stack_b *stack_b, long tar)
{
	long	hold;

	hold = stack_b->array[tar];
	if (tar < m_abs(stack_b->curlen - tar) + 1)
	{
		while (stack_b->array[0] != hold)
			rb(stack_b);
	}
	else
	{
		while (stack_b->array[0] != hold)
			rrb(stack_b);
	}
}

void	afindsmallest(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	i;
	long	min;

	i = 0;
	min = stack_a->array[0];
	while (i < stack_a->curlen)
	{
		if (stack_a->array[i] < min)
		{
			min = stack_a->array[i];
			stack_a->smallest = i;
		}
		i++;
	}
}

void	npushchunk(t_stack_a *stack_a, t_stack_b *stack_b, long chunk,
		long oldchunk)
{
	long	bottom;
	long	top;
	long	i;
	char	flag;

	if (oldchunk == 0)
		oldchunk++;
	bottom = stack_a->auxarray[oldchunk - 1];
	top = stack_a->auxarray[chunk - 1];
	i = 0;
	while (i < stack_a->inilen)
	{
		if (stack_a->array[0] <= top && stack_a->array[0] >= bottom)
		{
			pb(stack_a, stack_b);
		}
		else if (stack_a->curlen >= stack_a->inilen / stack_b->multiplier)
		{
			ra(stack_a);
		}
		i++;
	}
}

void	bubblesort(t_stack_a *stack_a, long *array)
{
	long	i;
	long	j;
	long	temp;

	i = stack_a->inilen;
	temp = 0;
	while (i >= 0)
	{
		j = 0;
		while (j < i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
}

void	matchtop(t_stack_a *stack_a)
{
	while (stack_a->array[0] != stack_a->auxarray[0])
		ra(stack_a);
}
