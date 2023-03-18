/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir <garibeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:38:27 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/17 12:33:36 by garibeir         ###   ########.fr       */
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
bool	last;
	long	i;
	long	stdchunk;
	long	chunk;
	long	nchunk;
	char tar;

	i = 0;
	stack_b->multiplier = 2;
	stdchunk = stack_a->inilen / stack_b->multiplier;
	chunk = stdchunk;
	nchunk = calchunk(stack_a, stdchunk, chunk);
	last = false;
	while (	!last &&  chunk <= stack_a->inilen )
	{
		i = 0;
		if (nchunk != stdchunk)
		{
			last = true;
			npushchunk(stack_a, stack_b, stack_a->inilen, chunk - stdchunk);
			while (i++ <= chunk )
				smartpush(stack_a, stack_b, nchunk);
		}
		else
		{
			npushchunk(stack_a, stack_b, chunk, chunk - stdchunk);
			while (i++ <= chunk)
				smartpush(stack_a, stack_b, chunk);
			chunk += stdchunk;
			nchunk = calchunk(stack_a, stdchunk, chunk);
		}
	}
		while (stack_a->array[0] != stack_a->auxarray[0])
				ra(stack_a); 
		
}
void	sort500(t_stack_a *stack_a, t_stack_b *stack_b)
{
	bool	last;
	long	i;
	long	stdchunk;
	long	chunk;
	long	nchunk;

	i = 0;
	stack_b->multiplier = 7;
	stdchunk = stack_a->inilen / stack_b->multiplier;
	chunk = stdchunk;
	nchunk = calchunk(stack_a, stdchunk, chunk);
	last = false;
	
	while (	!last &&  chunk <= stack_a->inilen )
	{
		i = 0;
		if (nchunk != stdchunk)
		{
			last = true;
			npushchunk(stack_a, stack_b, stack_a->inilen, chunk - stdchunk);
			while (i++ <= chunk )
				smartpush(stack_a, stack_b, nchunk);
		}
		else
		{
			npushchunk(stack_a, stack_b, chunk, chunk - stdchunk);
			while (i++ <= chunk) 
				smartpush(stack_a, stack_b, chunk);
			chunk += stdchunk;
			nchunk = calchunk(stack_a, stdchunk, chunk);
		}
			while (stack_a->array[0] != stack_a->auxarray[0])
				ra(stack_a);  
	}
			while (stack_a->array[0] != stack_a->auxarray[0])
				ra(stack_a); 
}


char	findsmartpush(t_stack_a *stack_a, t_stack_b *stack_b, long chunk)
{
	long	sdown;
	long	bdown;
	long 	paths;
	long pathb;
	char	flag;


	findsmallest(stack_a, stack_b, 'b', chunk);
	findbiggest(stack_a, stack_b, 'b');
	sdown = stack_b->curlen - stack_b->smallest; // +1
	bdown = stack_b->curlen - stack_b->biggest;
	
	if (sdown > stack_b->smallest)
		paths = stack_b->smallest;
	else
		paths = sdown * -1;
	if (bdown > stack_b->biggest)
		pathb= stack_b->biggest;
	else
		pathb = bdown * -1;
	
	if (m_abs(paths) < m_abs(pathb))
	{
		if (paths)
			flag = 's';
		else
			flag = 'S';
	}
	else if (pathb)
		flag = 'b';
	else
		flag = 'B';
	
	return (flag);
	
	
}

// vai receber uma flag que lhe vai dizer que numero mandar com ra ou rra para o top
// vai buscar o numero
// vai fazer ra ou rra
void	smartpush(t_stack_a *stack_a, t_stack_b *stack_b, long chunk)
{
	char	flag;
	long	smallest;
	long	biggest;

	flag = findsmartpush(stack_a, stack_b, chunk);
	smallest = findsmallest(stack_a, stack_b, 'b', chunk);
	biggest = findbiggest(stack_a, stack_b, 'b');
	if (flag == 's')
	{
		smartTop(stack_a, stack_b, stack_b->smallest);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (flag == 'b')
	{
		smartTop(stack_a, stack_b, stack_b->biggest);
		pa(stack_a, stack_b);
	}
	else if (flag == 'S')
	{
		smartTop(stack_a, stack_b, stack_b->smallest);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (flag == 'B')
	{
		smartTop(stack_a, stack_b, stack_b->biggest);
		pa(stack_a, stack_b);
	}
}

//findsmallest will find 
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
long	findsmallest(t_stack_a *stack_a, t_stack_b *stack_b, char flag, long chunk)
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


void	smartTop(t_stack_a *stack_a, t_stack_b *stack_b, long tar)
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

void	npushchunk(t_stack_a *stack_a, t_stack_b *stack_b, long chunk, long oldchunk)
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