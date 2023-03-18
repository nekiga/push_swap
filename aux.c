/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garibeir < garibeir@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:57:36 by garibeir          #+#    #+#             */
/*   Updated: 2023/03/18 14:36:27 by garibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks if char is a digit
bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

//iterates over a 2d array of chars to check if all of them represent digits
bool	onlydigit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i != argc)
	{
		j = 0;
		while (j != ft_strlen(argv[i]))
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (ft_isdigit(argv[i][j]) == false)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

// takes in a string and turns it into longs
long	ft_atol(const char *str)
{
	long	i;
	long	res;
	int		sign;

	sign = 1;
	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
		res = res * 10 + str[i++] - 48;
	return (res * sign);
}

//Takes a an array of strings and transforms them into one array of longs
long	*makearray(int argc, char **argv)
{
	long	i;
	long	j;
	long	*array;
	long	len;

	i = 1;
	j = 0;
	len = 0;
	while (i != argc)
	{
		len++;
		i++;
	}
	i = 1;
	array = xmalloc(sizeof(long) * len);
	if (!array)
		return (NULL);
	while (i != argc)
	{
		array[j] = atol(argv[i]);
		i++;
		j++;
	}
	return (array);
}

long	ft_strlen(char *str)
{
	long	j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}
