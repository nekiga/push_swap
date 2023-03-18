/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:09:12 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/18 14:52:48 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Prints the word Error and a new line on stderr
//Frees memory in case of abnormal shut down
void	error(t_stack_a *stack_a, t_stack_b *stack_b)
{
	ft_puterror("Error");
	ft_putcharerr('\n');
	free(stack_b->array);
	free(stack_a->array);
	free(stack_a->auxarray);
	free(stack_a);
	free(stack_b);
	exit(1);
}

void	zero(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	i;

	i = 0;
	if (!stack_b->array)
		error(stack_a, stack_b);
	while (i < stack_b->inilen - 1)
	{
		stack_b->array[i] = 0;
		i++;
	}
}

long	m_abs(long x)
{
	if (x == 0)
		return (0);
	if (x < 0)
		x *= -1;
	return (x);
}

void	makeauxarray(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	i;

	i = 0;
	stack_a->auxarray = xmalloc(sizeof(long) * stack_a->inilen);
	if (!stack_a->auxarray)
		error(stack_a, stack_b);
	while (i < stack_a->inilen)
	{
		stack_a->auxarray[i] = stack_a->array[i];
		i++;
	}
	bubblesort(stack_a, stack_a->auxarray);
}

long	calchunk(t_stack_a *stack_a, long nrmchunk, long chunk)
{
	if (stack_a->inilen - chunk < nrmchunk)
		return (stack_a->inilen - chunk);
	else
		return (nrmchunk);
}
