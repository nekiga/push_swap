/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir <garibeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:38:27 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/08 17:18:13 by garibeir         ###   ########.fr       */
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
	long	i;
	long	j;
	long	temp;

	//	int	test = 0;
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
	/* while(test++ < 100)
		printf("[%ld]", array[test]); */
}
void	sort100(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	i;
	long	j;
	long	*array;
	long	chunk;

	i = 0;
	j = 0;
	chunk = 50;
	array = malloc(sizeof(long) * stack_a->inilen);
	 if (!array)
		error(stack_a, stack_b);
	while (i < stack_a->inilen - 1)
	{
		array[i] = stack_a->array[i];
		i++;
	}
	bubblesort(stack_a, array);
	stack_b->call = true;
	while (chunk < 101)
	{
		i = 0;
		pushchunk(stack_a, stack_b, chunk, array);
		while (i++ <= chunk)
			smartpush(stack_a, stack_b);
		chunk += 50;
	}
	while (stack_a->array[0] != findsmallest(stack_a, stack_b, 'a', 50))
		ra(stack_a);  
	free(array);
}
//Finds most otimized path to push either the biggest or smallest number to the top
char	findsmartpush(t_stack_a *stack_a, t_stack_b *stack_b)
{
	long	msmall;
	long	mbig;
	long	smallnum;
	long	bignum;
	char	flag;


	smallnum = findsmallest(stack_a, stack_b, 'b', 50);
	bignum = findbiggest(stack_a, stack_b, 'b');
	msmall = m_abs(stack_b->smallest - stack_b->curlen + 1);
	mbig = m_abs(stack_b->biggest - stack_b->curlen + 1);
	if (stack_b->smallest < msmall)
	{
		if (stack_b->smallest < stack_b->biggest)
		{
			flag = 's';
		}
		else
			flag = 'b';
		return (flag);
	}
	else if (stack_b->smallest > msmall)
	{
		if (msmall < mbig)
		{
			flag = 'S';
		}
		else
		{
			flag = 'B';
		}
	}
	else
	{
		flag = 's';
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
	smallest = findsmallest(stack_a, stack_b, 'b', 50);
	biggest = findbiggest(stack_a, stack_b, 'b');
	if (flag == 's')
	{
		smartTop(stack_a, stack_b, stack_b->smallest, 'b');
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (flag == 'b')
	{
		smartTop(stack_a, stack_b, stack_b->biggest, 'b');
		pa(stack_a, stack_b);
	}
	else if (flag == 'S')
	{
		smartTop(stack_a, stack_b, stack_b->smallest, 'b');
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (flag == 'B')
	{
		smartTop(stack_a, stack_b, stack_b->biggest, 'b');
		pa(stack_a, stack_b);
	}
}
//pushes all members of chunk to stack_b
void	pushchunk(t_stack_a *stack_a, t_stack_b *stack_b, long chunk,
		long *array)
{
	long		hold;
	long		oldhold;
	static long	i;

	hold = array[chunk - 1];
	 if (stack_b->call == false)
		oldhold = array[49]; 
	if (stack_b->call == true)
	{
		i = 0;
		oldhold = 0;
		stack_b->call = false;
	}

	while (i <= chunk * 2)
	{
	
		if (stack_a->array[0] <= hold  && stack_a->array[0] >= oldhold )
		{
			pb(stack_a, stack_b);
		}
		else
		{
			findsmallest(stack_a, stack_b, 'a', chunk);
			smartTop(stack_a, stack_b, stack_a->smallest, 'a');
		}
		i++;
	}
}
//findsmallest will find 
long	findsmallest(t_stack_a *stack_a, t_stack_b *stack_b, char flag, long chunk)
{
	long	i;
	long	min;

	i = 0;
	chunk -= 50;
	if (flag == 'a')
	{
		min = stack_a->array[0];
		stack_a->smallest = 0;
		while (i < stack_a->curlen)
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

	findsmallest(stack_a, stack_b, 'a', 50);
	pos = stack_a->smallest;
	temp = stack_a->array[pos];
	if (stack_a->curlen - pos < stack_a->curlen / 2)
		while (stack_a->array[0] != temp)
			ra(stack_a);
	else
		while (stack_a->array[0] != temp)
			rra(stack_a);
}



void	smartTop(t_stack_a *stack_a, t_stack_b *stack_b, long tar, char flag)
{
	long	hold;


	if (flag == 'a')
	{
		hold = stack_a->array[tar];
		if (m_abs(tar < stack_a->curlen - tar))
		{
			while (stack_a->array[0] != hold)
				ra(stack_a);
		}
		else
		{
			while (stack_a->array[0] != hold)
				rra(stack_a);
		}
		
	}
	else if (flag == 'b')
	{
		hold = stack_b->array[tar];
		if (m_abs(tar < stack_b->curlen - tar))
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
	else
	{
		error(stack_a, stack_b);
	}
}