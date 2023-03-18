/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:08:57 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/18 13:39:54 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//put char on stderr
void	ft_putcharerr(char c)
{
	write(2, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

//putstr on stderr
void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putcharerr(str[i++]);
}

//receives stack and checks if its array contains duplicated digits
bool	checkifdouble(t_stack_a *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->inilen)
	{
		j = i + 1;
		while (j < stack_a->inilen)
		{
			if (stack_a->array[i] == stack_a->array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
