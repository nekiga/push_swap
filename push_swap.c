/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:12:16 by garibeir          #+#    #+#             */
/*   Updated: 2023/02/26 17:54:46 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (checkSorted(stack_a))
		exit(0);
	else if (stack_a->inilen == 2)
		sort2(stack_a, stack_b);
	else if (stack_a->inilen == 3)
		sort3(stack_a, stack_b);
	else if (stack_a->inilen == 5 || stack_a->inilen == 4)
		sort5(stack_a, stack_b);
	else if(stack_a->inilen == 100)
		sort100(stack_a, stack_b);
	else
		printf("DID NOT MEET ANY CONDITIONS IN PUSH_SWAP FUNC\n");
}

// The function main initializes the stacks and sends them to push swap,
//while also protecting the different allocaitons,
//freeing them and checking if all arguments are valid
int	main(int argc, char **argv)
{
	t_stack_a	*stack_a;
	t_stack_b	*stack_b;
	long		i;

	i = 0;
	stack_a = malloc(sizeof(t_stack_a));
	stack_b = malloc(sizeof(t_stack_b));
	//zero(stack_a, stack_b);
	if (argc == 1)
		return (error(stack_a, stack_b));
	if (onlydigit(argc, argv) == false)
		return (error(stack_a, stack_b));
	stack_a->array = mArray(argc, argv);
	if (!stack_a->array)
		return (error(stack_a, stack_b));
	stack_b->array = malloc(sizeof(long) * argc - 1);
	if (!stack_b->array)
		return (error(stack_a, stack_b));
	stack_a->inilen = argc - 1;
	stack_a->curlen = stack_a->inilen;
	stack_b->inilen = stack_a->inilen;
	stack_b->curlen = 0;
	if (!checkArgs(stack_a))
		return (error(stack_a, stack_b));
	push_swap(stack_a, stack_b);
	/* pb(stack_a, stack_b);
	printArray(stack_a);
	printArrayb(stack_b);
	pb(stack_a, stack_b);
	printArray(stack_a);
	printArrayb(stack_b);
	sa(stack_a);
	printArray(stack_a);
	printArrayb(stack_b);
	ra(stack_a);
	 printArray(stack_a);
	printArrayb(stack_b);
	pa(stack_a, stack_b);
	printArray(stack_a);
	printArrayb(stack_b);
	ra(stack_a);
	printArray(stack_a);
	printArrayb(stack_b);
	ra(stack_a);
	printArray(stack_a);
	printArrayb(stack_b);
	ra(stack_a); */
	free(stack_b->array);
	free(stack_a->array);
	free(stack_a);
	free(stack_b);
	return (0);
}

/* pb
pb
sa
ra
pa
ra
ra
ra
ra */

