#include "push_swap.h"

int push_swap( stack_a stack_a, stack_b stack_b)
{
    return (0);
}
int main(int argc, char **argv)
{
    long i;
    long len;
    stack_a stack_a;
    stack_b stack_b;
    long *tArr;

    i = 1;
    len = 0;
    if (argc == 1)
        return(1);
    while (i != argc)
	{
		len += ft_strlen(argv[i]);
		i++;
	}
    stack_a.array = (long *)malloc(sizeof(long) *  len);
    if (!stack_a.array)
        return (1);
    stack_a.array = mArray(argc, argv);

    return (0);
}