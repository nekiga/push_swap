/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir <garibeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:12:16 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/15 13:17:07 by garibeir         ###   ########.fr       */
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
	 else if(stack_a->inilen < 201)
		sort100(stack_a, stack_b);  
	else
		sort500(stack_a, stack_b);

}

// The function main initializes the stacks and sends them to push swap,
//while also protecting the different allocaitons,
//freeing them and checking if all arguments are valid
int	main(int argc, char **argv)
{
	t_stack_a	*stack_a;
	t_stack_b	*stack_b;

	stack_a = malloc(sizeof(t_stack_a));
	stack_b = malloc(sizeof(t_stack_b));
	init(stack_a, stack_b, argc, argv);
	push_swap(stack_a, stack_b);
	printArray(stack_a);
	printArrayb(stack_b);
	free(stack_b->array);
	free(stack_a->auxarray);
	free(stack_a->array);
	free(stack_a);
	free(stack_b);
	return (0);
}

int init(t_stack_a *stack_a, t_stack_b *stack_b, int argc, char **argv)
{
	stack_a->array = mArray(argc, argv);
	if (!stack_a->array)
		return (error(stack_a, stack_b));
	stack_b->array = malloc(sizeof(long) * argc - 1);
	if (argc == 1)
		return (error(stack_a, stack_b));
	if (!stack_b->array)
		return (error(stack_a, stack_b));
	if (onlydigit(argc, argv) == false)
		return (error(stack_a, stack_b));
	if (!checkArgs(stack_a))
		return (error(stack_a, stack_b));
	stack_a->inilen = argc - 1;
	stack_a->curlen = stack_a->inilen;
	stack_b->inilen = stack_a->inilen;
	stack_b->curlen = 0;
	makeauxarray(stack_a, stack_b);
	zero(stack_a, stack_b);
	return (0);
}

