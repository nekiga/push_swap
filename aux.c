#include "push_swap.h"

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}
//calculates lenght of array
long getArrayLen(long *array)
{
	long len;
	
	len = sizeof(array) / sizeof(long);
	//printf(" INFUC lenght of array is %ld \n", len);
	return (len);
	
}
// takes in a string and turns it into longs
long	ft_atol(const char *str)
{
	long	    i;
	long	res;
	int	    sign;

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
long 	*mArray(int argc, char **argv)
{
	long	i;
	long	j;
	long 	*array;
	long 	len;

	i = 1;
	j = 0;
	len = 0;
	while (i != argc)
	{
		len += ft_strlen(argv[i]);
		i++;
	}
	i = 1;
	array = malloc(sizeof(long) * len);
	if (!array)
		return (NULL);
	while (i != argc)
	{
		array[j] = atol(argv[i]);
		//printf("The i is : %ld and the arrj is: %ld \n", i, array[j]);
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

//check if array is empty
bool	checkIfArray (long *array)
{
	int	len;

	len = getArrayLen(array);
	while (len)
	{
		if (array[len] != 0)
			return (true);
		len--;
	}
	return (false);
}

int	push