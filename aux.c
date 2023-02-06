#include "push_swap.h"

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

void	ft_putChar(char c)
{
	write(1, &c, 1);
}

void	ft_putCharE(char c)
{
	write (2, &c, 1);
}

void	ft_putStr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putChar(str[i++]);
}

void	ft_putError(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putCharE(str[i++]);
}

//calculates lenght of array
long getArrayLen(long *array)
{
	long len;
	
	len = sizeof(array) / sizeof(long);
	return (len);
	
}
// takes in a string and turns it into longs
//CHECK INPUTS LIKE 03 +3 -3  a
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
	long	len;

	len = getArrayLen(array);
	while (len)
	{
		if (array[len] != 0)
			return (true);
		len--;
	}
	return (false);
}

bool	checkIfDouble(stack_a stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stack_a.iniLen)
	{
		j = i + 1;
		while (j <= stack_a.iniLen)
		{
			if (stack_a.array[i] == stack_a.array[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool checkArgs(stack_a stack_a)
{
	int	i;

	i = 0;
	while(i != stack_a.iniLen)
	{
		if (checkIfDouble(stack_a) == false)
			return (false);
		i++;
	}
	i = 0;
	while (i != stack_a.iniLen)
	{
		if (stack_a.array[i] > INT_MAX)
			return (false);
		if (stack_a.array[i] < INT_MIN)
			return(false);
		i++;
	}
	return (true);
}

int	error(void)
{
	ft_putError("Error");
	ft_putCharE('\n');
	return(1);
}

int init(stack_a stack_a, stack_b stack_b, int argc, char **argv)
{
	printf("%d", argc );
    stack_a.array = mArray(argc, argv);
    stack_b.array = malloc(sizeof(long) * argc - 1);
    stack_a.iniLen = argc - 1; 
    stack_a.curLen = stack_a.iniLen;
    stack_b.iniLen = stack_a.iniLen;
    stack_b.curLen = stack_a.iniLen;
	return (1);
}