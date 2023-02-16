/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:38:27 by garibeir          #+#    #+#             */
/*   Updated: 2023/02/16 13:14:01 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort2(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->array[0] > stack_a->array[1])
		sa(stack_a);
	free(stack_a->array);
	free(stack_b->array);
	exit(0);
}
// sorts numbers if given 3 :D
void sort3(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->array[0] > stack_a->array[1]
		&& stack_a->array[1] < stack_a->array[2]
		&& stack_a->array[0] < stack_a->array[2])
		return (sa(stack_a));
	if (stack_a->array[0] > stack_a->array[1]
		&& stack_a->array[1] < stack_a->array[2]
		&& stack_a->array[0] > stack_a->array[2])
		return (ra(stack_a));
	if (stack_a->array[0] > stack_a->array[1]
		&& stack_a->array[1] > stack_a->array[2])
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (stack_a->array[0] < stack_a->array[1]
		&& stack_a->array[1] > stack_a->array[2]
		&& stack_a->array[0] > stack_a->array[2])
	{
		rra(stack_a);
	}
	if (stack_a->array[0] < stack_a->array[1]
		&& stack_a->array[1] > stack_a->array[2])
	{
		sa(stack_a);
		ra(stack_a);
    }
}

//sorts nubers if given 5

int	sort5(t_stack_a *stack_a, t_stack_b *stack_b)
{
	toTop(stack_a);
	pb(stack_a, stack_b);
	toTop(stack_a);
	pb(stack_a, stack_b);
	sort3(stack_a, stack_b);
	pa(stack_a, stack_b);
	stack_a->curlen = stack_a->curlen + 2;
	toTop(stack_a);
	stack_a->array[0] = stack_b->array[0];
	stack_a->curlen++;
	return (1);
}

long	findsmallest(t_stack_a *stack_a)
{
	long	i;
	long	min;

	if (stack_a->curlen == 0)
	{
		return (0);
	}
	i = 1;
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

int	totop(t_stack_a *stack_a)
{
	long	pos;
	long	temp;
	int		i;

	i = 10;
	findSmallest(stack_a);
	pos = stack_a->smallest;
	temp = stack_a->array[pos];
	if (stack_a->curlen - pos < stack_a->curlen / 2)
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
