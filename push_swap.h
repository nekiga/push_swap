/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir <garibeir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:59 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/20 11:14:39 by garibeir         ###   ########.fr       */
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
	long	*auxarray;
	long	inilen;
	long	curlen;
	long	smallest;
	long	biggest;
	long	stdchunk;
}			t_stack_a;

typedef struct stack_b
{
	long	*array;
	long	inilen;
	long	curlen;
	long	smallest;
	long	biggest;
	int		multiplier;
	bool	last;
}			t_stack_b;

//base functions
long		*makearray(int argc, char **argv);
void		makeauxarray(t_stack_a *stack_a, t_stack_b *stack_b);
long		ft_atol(const char *str);
long		ft_strlen(char *str);
bool		checkifarray(long *array);
bool		checkargs(t_stack_a *stack_a);
void		error(t_stack_a *stack_a, t_stack_b *stack_b);
bool		ft_isdigit(char c);
bool		onlydigit(int argc, char **argv);
void		zero(t_stack_a *stack_a, t_stack_b *stack_b);
long		m_abs(long x);
void		init(t_stack_a *stack_a, t_stack_b *stack_b, int argc, char **argv);
void		bubblesort(t_stack_a *stack_a, long *array);
long		calchunk(t_stack_a *stack_a, long nrmchunk, long chunk);
void		matchtop(t_stack_a *stack_a);
bool		checkifdouble(t_stack_a *stack_a);
int			ft_puterror(char *str);
void		ft_putcharerr(char c);
void		*xmalloc(size_t size);
bool		checksorted(t_stack_a *stack_a);

// push swap moves
int			sa(t_stack_a *stack_a);
int			sb(t_stack_b *stack_b);
int			ra(t_stack_a *stack_a);
int			pb(t_stack_a *stack_a, t_stack_b *stack_b);
int			pa(t_stack_a *stack_a, t_stack_b *stack_b);
int			rb(t_stack_b *stack_b);
int			rra(t_stack_a *stack_a);
int			rrb(t_stack_b *stack_b);
void		shiftdown(t_stack_a *stack_a, t_stack_b *stack_b);
void		shiftdownb(t_stack_a *stack_a, t_stack_b *stack_b);
// algorithm
void		sort2(t_stack_a *stack_a, t_stack_b *stack_b);
void		sort3(t_stack_a *stack_a, t_stack_b *stack_b);
void		sort5(t_stack_a *stack_a, t_stack_b *stack_b);
char		findsmartpush5(t_stack_a *stack_a, t_stack_b *stack_b, long chunk);
void		smarttop5(t_stack_a *stack_a, t_stack_b *stack_b, long tar);
void		smartpush5(t_stack_a *stack_a, t_stack_b *stack_b, long chunk);

void		sort100(t_stack_a *stack_a, t_stack_b *stack_b);
void		sort500(t_stack_a *stack_a, t_stack_b *stack_b);
void		totop(t_stack_a *stack_a, t_stack_b *stack_b);
char		findsmartpush(t_stack_a *stack_a, t_stack_b *stack_b, long chun);
void		smartpush(t_stack_a *stack_a, t_stack_b *stack_b, long chunk);
long		findbiggest(t_stack_a *stack_a, t_stack_b *stack_b, char flag);
long		findsmallest(t_stack_a *stack_a, t_stack_b *stack_b, char flag,
				long chunk);
void		dosmartpush(t_stack_a *stack_a, t_stack_b *stack_b,
				long chunk);
void		pushtop(t_stack_a *stack_a, long i);
void		smarttop(t_stack_a *stack_a, t_stack_b *stack_b, long tar);
void		npushchunk(t_stack_a *stack_a, t_stack_b *stack_b, long chunk,
				long oldchunk);
char		nfindsmartpush(t_stack_a *stack_a, t_stack_b *stack_b, long chunk,
				long stdchunk);
void		afindsmallest(t_stack_a *stack_a, t_stack_b *stack_b);
long		findsmallestb(t_stack_b *stack_b, long chunk);
long		findbiggestb(t_stack_b *stack_b);
void		dofind(t_stack_a *stack_a, t_stack_b *stack_b, long chunk);

#endif