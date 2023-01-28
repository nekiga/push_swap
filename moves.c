#include "push_swap.h"
//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements. :D
int sa(stack_a stack_a)
{
    long temp;

   temp =  stack_a.array[0];
   stack_a.array[0] = stack_a.array[1];
   stack_a.array[1] = temp;
   return (0);
}

//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if ther is only one or no elements.
int sb(stack_b stack_b)
{
    long temp;

   temp =  stack_b.array[0];
   stack_b.array[0] = stack_b.array[1];
   stack_b.array[1] = temp;
   return (0);
}

//ss : sa and sb at the same time.
int ss(stack_a stack_a,stack_b stack_b)
{
    long temp;

   temp =  stack_a.array[0];
   stack_a.array[0] = stack_a.array[1];
   stack_a.array[1] = temp;
   temp =  stack_b.array[0];
   stack_b.array[0] = stack_b.array[1];
   stack_b.array[1] = temp;
   return (0);
}

//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
int pa( stack_a stack_a,  stack_b stack_b)
{
    long   i;

    i = 0;
    if (!checkIfArray(stack_a.array))
        return (1);
    stack_b.array[0] = 0;
    return (0);
}

//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.
int pb( stack_a stack_a,  stack_b stack_b)
{
    long    temp;

    if (!checkIfArray(stack_a.array))
        return (1);
    temp = stack_b.array[0];

    stack_b.array[0] = stack_a.array[0];
    
}

//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one. :d 
int ra(stack_a stack_a)
{
    long temp;
    long i;

    if (stack_a.curLen <= 0)
    {
        return -1;
    }

    temp = stack_a.array[0];
    i = 0;
    while(i < stack_a.curLen - 1)
    {
        stack_a.array[i] = stack_a.array[i+1];
        i++;
    }
    stack_a.array[stack_a.curLen - 1] = temp;
    return (0);
}


//rb (rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one. :d
int rb (stack_b stack_b)
{
     long temp;
    long i;
    long j;

    j = stack_b.curLen - 1;
    i = 0;
    temp = stack_b.array[0];
    if (stack_b.curLen <= 0)
    {
        return -1;
    }
    while(i < stack_b.curLen)
    {
        temp = stack_b.array[j];
        stack_b.array[j] = stack_b.array[j];
        stack_b.array[j] = temp;
        i++;
        j--;
    }
    return (0);
}

//rr : ra and rb at the same time.
int rr( stack_a stack_a,  stack_b stack_b)
{ 

}

//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
int rra( stack_a stack_a)
{
    long temp;
    long    tempLast;
    long i;
    long j;

    j = stack_a.curLen;
    i = 0;
    tempLast = stack_a.array[stack_a.curLen];
    while(i != stack_a.curLen)
    {
        temp = stack_a.array[i];
        stack_a.array[i] = stack_a.array[i + 1];
        stack_a.array[i] = temp;
        i++;
        j--;
    }
    return (0);
}

//rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one. !!
int rrb(  stack_b stack_b)
{
     long temp;
    long i;
    long j;

    j = stack_b.curLen;
    while(i != stack_b.curLen)
    {
        temp = stack_b.array[j];
        stack_b.array[j] = stack_b.array[j - 1];
        stack_b.array[j] = temp;
        i++;
        j--;
    }
}
//rrr : rra and rrb at the same time.
int rrr( stack_a stack_a,  stack_b stack_b)
{

}