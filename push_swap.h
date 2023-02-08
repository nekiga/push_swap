#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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
bool    checkArgs(stack_a stack_a);
int	    error(stack_a stack_a, stack_b stack_b);
bool	ft_isdigit(char c);
bool    onlydigit(int argc, char **argv);
// push swap moves
int sa(stack_a stack_a);
int ra( stack_a stack_a);
int pb( stack_a stack_a,  stack_b stack_b);
int pa( stack_a stack_a,  stack_b stack_b);
int ra(stack_a stack_a);
int rb(stack_b stack_b);
int rr( stack_a stack_a,  stack_b stack_b);
int rra( stack_a stack_a);
int rrb( stack_b stack_b);
int rrr( stack_a stack_a,  stack_b stack_b);
// algorithm
int sort3(stack_a stack_a, stack_b stack_b);
// tester functions
void    printArray(stack_a stack_a);
void    printArrayb(stack_b stack_b);

#endif