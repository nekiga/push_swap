#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
 typedef struct stack_a
{
    long *array;
    size_t iniLen;
    size_t curLen;

}stack_a;

 typedef struct stack_b
{
    long *array;
    size_t iniLen;
    size_t curLen;

}stack_b;

long 	*mArray(int argc, char **argv);
long	ft_atol(const char *str);
long	ft_strlen(char *str);
long    arrayLen(long *array);
bool	checkIfArray (long *array);

#endif