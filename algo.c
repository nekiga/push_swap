/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:38:27 by garibeir          #+#    #+#             */
/*   Updated: 2023/02/26 18:33:15 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (stack_a->array[0] > stack_a->array[1])
		sa(stack_a);
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
	else if (stack_a->array[0] < stack_a->array[1]
			&& stack_a->array[1] > stack_a->array[2])
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
	sort3(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (stack_a->inilen == 5)
		pa(stack_a, stack_b);
}
void	bubblesort(t_stack_a *stack_a, long *array)
{
	int		i;
	int		j;
	long	temp;

	i = stack_a->inilen - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
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
void	sort100(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	i;
	long	j;
	long	*array;
	long	chunk;

	i = 0;
	j = 0;
	chunk = 20;
	array = (long *)malloc(sizeof(long) * stack_a->inilen);
	if (!array)
		error(stack_a, stack_b);
	while (i < stack_a->inilen - 1)
		array[i] = stack_a->array[i++];
	i = 0;
	bubblesort(stack_a, array);
	stack_b->call = true;
	while (chunk <= 100)
	{
		pushchunk(stack_a, stack_b, chunk, array);
		while (i++ <= chunk)
			smartpush(stack_a, stack_b);
		chunk += 20;
	}
	free(array);
}
//Finds most otimized path to push either the biggest or smallest number to the top
char	findsmartpush(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	smallest;
	long	biggest;
	long	movessmall;
	long	movesbig;
	char	flag;

	smallest = findsmallest(stack_a, stack_b, 'b');
	biggest = findbiggest(stack_a, stack_b, 'b');
	movessmall = stack_b->smallest - stack_b->curlen + 1;
	movesbig = stack_b->biggest - stack_b->curlen + 1;
if (stack_b->smallest < movessmall)
	{
		if (stack_b->smallest < stack_b->biggest)
			flag = 's';
		else
			flag = 'b';
	}
	else if (stack_b->smallest > movessmall)
	{
		if (movessmall < movesbig)
			flag = 'S';
		else
			flag = 'B';
	}
	return (flag);
}
// vai receber uma flag que lhe vai dizer que numero mandar com ra ou rra para o top
// vai buscar o numero
// vai fazer ra ou rra
void	smartpush(t_stack_a *stack_a, t_stack_b *stack_b)
{
	char	flag;
	long	smallest;
	long	biggest;

	flag = findsmartpush(stack_a, stack_b);
	smallest = findsmallest(stack_a, stack_b, 'b');
	biggest = findbiggest(stack_a, stack_b, 'b');
	if (flag == 's')
	{
		while (stack_b->array[0] != smallest)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (flag == 'b')
	{
		while (stack_b->array[0] != biggest)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (flag == 'S')
	{
		while (stack_b->array[0] != smallest)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
	else if (flag == 'B')
	{
		while (stack_b->array[0] != biggest)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
}
//pushes all members of chunk to stack_b
void	pushchunk(t_stack_a *stack_a, t_stack_b *stack_b, long chunk,
		long *array)
{
	long		hold;

	static long	i;

	if (stack_b->call == true)
	{
		i = 0;
		stack_b->call== false;
	}
	hold = array[chunk - 1];
	while ( i <= chunk)
	{
		if (stack_a->array[0] < hold)
		{	
				pb(stack_a, stack_b);
		}
		else
			ra(stack_a);
		i++;
	}

}
long	findsmallest(t_stack_a *stack_a, t_stack_b *stack_b, char flag)
{
	long	i;
	long	min;
	
	i = 0;
	if (flag == 'a')
	{
		if (stack_a->curlen == 0)
			return (0);
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
	if (stack_b->curlen == 0)
		return (0);
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

long	findbiggest(t_stack_a *stack_a, t_stack_b *stack_b, char flag)
{
	long	i;
	long	max;


	i = 0;
	if (flag == 'a')
	{
		if (stack_a->curlen == 0)
			return (0);
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
	if (stack_b->curlen == 0)
		return (0);
	max = stack_b->array[0];
	stack_b->biggest = 0;
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

void	totop(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	pos;
	long	temp;

	findsmallest(stack_a, stack_b, 'a');
	pos = stack_a->smallest;
	temp = stack_a->array[pos];
	if (stack_a->curlen - pos < stack_a->curlen / 2)
		while (stack_a->array[0] != temp)
			ra(stack_a);
	else
		while (stack_a->array[0] != temp)
			rra(stack_a);
}

void	pushtop(t_stack_a *stack_a, long i)
{
	long temp;
	int	x = 100;
	temp = stack_a->array[i];
	printf("temp %ld", temp);
	if (i < i - stack_a->curlen + 1)
	{
		while (stack_a->array[0] != temp)
			ra(stack_a);
	}
	else
	{
		while (stack_a->array[0] != temp && x--)
			rra(stack_a);
	}
}