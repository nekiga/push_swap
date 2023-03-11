/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:59 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/11 13:57:08 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack_a
{
	long	*array;
	long	inilen;
	long	curlen;
	long	smallest;
	long	biggest;

}			t_stack_a;

typedef struct stack_b
{
	long	*array;
	long	inilen;
	long	curlen;
	long	smallest;
	long	biggest;
	bool	call;

}			t_stack_b;

//base functions
long		*mArray(int argc, char **argv);
long		ft_atol(const char *str);
long		ft_strlen(char *str);
long		getArrayLen(long *array);
bool		checkIfArray(long *array);
bool		checkArgs(t_stack_a *stack_a);
int			error(t_stack_a *stack_a, t_stack_b *stack_b);
bool		ft_isdigit(char c);
bool		onlydigit(int argc, char **argv);
bool		checkSorted(t_stack_a *stack_a);
void 		zero(t_stack_a *stack_a, t_stack_b *stack_b);
long 		m_abs(long x);
// push swap moves
int			sa(t_stack_a *stack_a);
int			sb(t_stack_b *stack_b);
int			ra(t_stack_a *stack_a);
int			pb(t_stack_a *stack_a, t_stack_b *stack_b);
int			pa(t_stack_a *stack_a, t_stack_b *stack_b);
int			rb(t_stack_b *stack_b);
int			rr(t_stack_a *stack_a, t_stack_b *stack_b);
int			rra(t_stack_a *stack_a);
int			rrb(t_stack_b *stack_b);
int			rrr(t_stack_a *stack_a, t_stack_b *stack_b);
// algorithm
void		sort2(t_stack_a *stack_a, t_stack_b *stack_b);
void		sort3(t_stack_a *stack_a, t_stack_b *stack_b);
void		sort5(t_stack_a *stack_a, t_stack_b *stack_b);
void		sort100(t_stack_a *stack_a, t_stack_b *stack_b);
void		totop(t_stack_a *stack_a, t_stack_b *stack_b);
char		findsmartpush(t_stack_a *stack_a, t_stack_b *stack_b);
void		pushchunk(t_stack_a *stack_a, t_stack_b *stack_b, long chunk,
				long *array);
void		smartpush(t_stack_a *stack_a, t_stack_b *stack_b);
long		findbiggest(t_stack_a *stack_a, t_stack_b *stack_b, char flag);
long		findsmallest(t_stack_a *stack_a, t_stack_b *stack_b, char flag, long chunk);
void		pushtop(t_stack_a *stack_a, long i);
void		smartTop(t_stack_a *stack_a, t_stack_b *stack_b, long tar, char flag);
// tester functions
void		printArray(t_stack_a *stack_a);
void		printArrayb(t_stack_b *stack_b);
bool 		checklenght(t_stack_a *stack_a,t_stack_b *stack_b);

#endif