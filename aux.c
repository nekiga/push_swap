#include "push_swap.h"

//checks if char is a digit
bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}
//iterates over a 2d array of chars to check if all of them represent digits
bool onlydigit(int argc, char **argv)
{
	int	i;
	int	j;


	i = 1;
	while (i != argc)
	{
		j = 0;
		while (j != ft_strlen(argv[i] - 1))
		{
			
			 if (j = 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++; 
			if (ft_isdigit(argv[i][j]) == false)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	ft_putChar(char c)
{
	write(1, &c, 1);
}
//put char on stderr
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
//putstr on stderr 
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
//receives stack and checks if its array contains duplicated digits
bool	checkIfDouble(t_stack_a *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i <= stack_a->inilen)
	{
		j = i + 1;
		while (j <= stack_a->inilen)
		{
			if (stack_a->array[i] == stack_a->array[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
//Checks if all array members are in the limits of int and calls check double
bool checkArgs(t_stack_a *stack_a)
{
	int	i;

	i = 0;
	if (checkIfDouble(stack_a) == false )
			return (false);
	while (i != stack_a->inilen)
	{
		if (stack_a->array[i] > INT_MAX)
			return (false);
		if (stack_a->array[i] < INT_MIN)
			return(false);
		i++;
	}
	return (true);
}
//Prints the word Error and a new line on stderr and frees memory in case of abnormal shut down
int	error(t_stack_a *stack_a, t_stack_b *stack_b)
{
	ft_putError("Error");
	ft_putCharE('\n');
	free(stack_b->array);
    free(stack_a->array);
	return(1);
}

bool checkSorted(t_stack_a *stack_a)
{
	  int i;
	  i = 0;
    while (i < stack_a->inilen - 1)
	 {
        if (stack_a->array[i] > stack_a->array[i + 1])
            return false;
        i++;
    }
    return true;
}
