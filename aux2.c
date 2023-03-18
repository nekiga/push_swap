/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:09:10 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/18 14:52:45 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Checks if all array members are in the limits of int and calls check double
bool	checkargs(t_stack_a *stack_a)
{
	int	i;

	i = 0;
	if (checkifdouble(stack_a) == true)
		return (false);
	while (i != stack_a->inilen)
	{
		if (stack_a->array[i] > INT_MAX)
			return (false);
		if (stack_a->array[i] < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

void	*xmalloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
		exit(1);
	return (result);
}

void	shiftdownb(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	i;

	i = stack_b->curlen - 1;
	while (i >= 0)
	{
		stack_b->array[i + 1] = stack_b->array[i];
		i--;
	}
	i = 0;
	while (i < stack_a->curlen - 1)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
}
