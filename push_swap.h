#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
 typedef struct stack_a
{
    long *array;
    long iniLen;
    long curLen;

}stack_a;

 typedef struct stack_b
{
    long *array;
    long iniLen;
    long curLen;

}stack_b;
//base functions
long 	*mArray(int argc, char **argv);
long	ft_atol(const char *str);
long	ft_strlen(char *str);
long    getArrayLen(long *array);
bool	checkIfArray (long *array);
// push swap moves
int sa(stack_a stack_a);
int ra( stack_a stack_a);
// tester functions
void    printArray(stack_a stack_a);

#endif