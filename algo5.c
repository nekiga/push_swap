#include "push_swap.h"

 void	sort5(t_stack_a *stack_a, t_stack_b *stack_b)
{
	smartpush5(stack_a, stack_b, stack_a->curlen);
	smartpush5(stack_a, stack_b, stack_a->curlen);
    if (!checksorted(stack_a))
        sort3(stack_a, stack_b);
    smartpush(stack_a, stack_b, stack_b->curlen);

}

char	findsmartpush5(t_stack_a *stack_a, t_stack_b *stack_b, long chunk)
{
	long	paths;
	long	pathb;
	char	flag;

	findsmallest(stack_a, stack_b, 'a', chunk);
	findbiggest(stack_a, stack_b, 'a');
	if (stack_a->curlen - stack_a->smallest > stack_a->smallest)
		paths = stack_a->smallest;
	else
		paths = (stack_a->curlen - stack_a->smallest) * -1;
	if (stack_a->curlen - stack_a->biggest > stack_a->biggest)
		pathb = stack_a->biggest;
	else
		pathb = (stack_a->curlen - stack_a->biggest) * -1;
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


void	smarttop5(t_stack_a *stack_a, t_stack_b *stack_b, long tar)
{
	long	hold;

	hold = stack_a->array[tar];
	if (tar < m_abs(stack_a->curlen - tar) + 1)
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

void	smartpush5(t_stack_a *stack_a, t_stack_b *stack_b, long chunk)
{
	char	flag;

	flag = findsmartpush5(stack_a, stack_b, chunk);
	findsmallest(stack_a, stack_b, 'a', stack_a->curlen);
    findbiggest(stack_a, stack_b, 'a');
	if (flag == 's' || flag == 'S')
	{
		smarttop(stack_a, stack_b, stack_b->smallest);
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	else
	{
		smarttop(stack_a, stack_b, stack_b->biggest);
		pb(stack_a, stack_b);
	}
}


last = findlast();
penultimo = findpenultimo();

last.next = *stack,
penultimo. next = null