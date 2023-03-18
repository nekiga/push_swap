/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:38:27 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/18 16:44:57 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->array[0] > stack_a->array[1])
		sa(stack_a);
}
void	sort2b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_b->array[0] > stack_b->array[1])
		sb(stack_b);
}
// sorts numbers if given 3 :D

void	sort3(t_stack_a *stack_a, t_stack_b *stack_b)
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
	else
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
	if (!checksorted(stack_a))
		sort3(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (stack_a->inilen == 5)
		pa(stack_a, stack_b);
}
 


//4 1 5 2 3    4 1 3 2 5
void	sort100(t_stack_a *stack_a, t_stack_b *stack_b)
{
	bool	last;
	long	chunk;
	long	nchunk;

	chunk = stack_a->stdchunk;
	nchunk = calchunk(stack_a, stack_a->stdchunk, chunk);
	last = false;
	while (!last && chunk <= stack_a->inilen)
	{
		if (nchunk != stack_a->stdchunk)
		{
			last = true;
			npushchunk(stack_a, stack_b, stack_a->inilen, chunk
				- stack_a->stdchunk);
			dosmartpush(stack_a, stack_b, chunk);
		}
		else
		{
			npushchunk(stack_a, stack_b, chunk, chunk - stack_a->stdchunk);
			dosmartpush(stack_a, stack_b, chunk);
			chunk += stack_a->stdchunk;
			nchunk = calchunk(stack_a, stack_a->stdchunk, chunk);
		}
	}
	matchtop(stack_a);
}

void	sort500(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	chunk;
	long	nchunk;

	chunk = stack_a->stdchunk;
	nchunk = calchunk(stack_a, stack_a->stdchunk, chunk);
	while (!stack_b->last && chunk <= stack_a->inilen)
	{
		if (nchunk != stack_a->stdchunk)
		{
			stack_b->last = true;
			npushchunk(stack_a, stack_b, stack_a->inilen, chunk
				- stack_a->stdchunk);
			dosmartpush(stack_a, stack_b, chunk);
		}
		else
		{
			npushchunk(stack_a, stack_b, chunk, chunk - stack_a->stdchunk);
			dosmartpush(stack_a, stack_b, chunk);
			chunk += stack_a->stdchunk;
			nchunk = calchunk(stack_a, stack_a->stdchunk, chunk);
		}
		matchtop(stack_a);
	}
	matchtop(stack_a);
}