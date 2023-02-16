/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:59 by garibeir          #+#    #+#             */
/*   Updated: 2023/02/16 12:27:34 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SENTINEL 21474836471;

typedef struct stack_a
{
	long	*array;
	long	inilen;
	long	curlen;
	long	smallest;

}			t_stack_a;

typedef struct stack_b
{
	long	*array;
	long	inilen;
	long	curlen;
	long	smallest;

}			t_stack_b;

//base functions
long		*mArray(int argc, char **argv);
long		ft_atol(const char *str);
long		ft_strlen(char *str);
long		getArrayLen(long *array);
bool		checkIfArray(long *array);
bool		checkArgs(t_stack_a *t_stack_a);
int			error(t_stack_a *t_stack_a, t_stack_b *t_stack_b);
bool		ft_isdigit(char c);
bool		onlydigit(int argc, char **argv);
bool		checkSorted(t_stack_a *t_stack_a);
// push swap moves
int			sa(t_stack_a *t_stack_a);
int			ra(t_stack_a *t_stack_a);
int			pb(t_stack_a *t_stack_a, t_stack_b *t_stack_b);
int			pa(t_stack_a *t_stack_a, t_stack_b *t_stack_b);
int			ra(t_stack_a *t_stack_a);
int			rb(t_stack_b *t_stack_b);
int			rr(t_stack_a *t_stack_a, t_stack_b *t_stack_b);
int			rra(t_stack_a *t_stack_a);
int			rrb(t_stack_b *t_stack_b);
int			rrr(t_stack_a *t_stack_a, t_stack_b *t_stack_b);
// algorithm
int			sort2(t_stack_a *t_stack_a, t_stack_b *t_stack_b);
int			sort3(t_stack_a *t_stack_a, t_stack_b *t_stack_b);
int			sort5(t_stack_a *t_stack_a, t_stack_b *t_stack_b);
int			toTop(t_stack_a *t_stack_a);
// tester functions
void		printArray(t_stack_a *t_stack_a);
void		printArrayb(t_stack_b *t_stack_b);

#endif