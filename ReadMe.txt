V.1 The rules
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.

V.3 The "push_swap" program
Program name push_swap
Turn in files Makefile, *.h, *.c
Makefile NAME, all, clean, fclean, re
Arguments stack a: A list of integers
External functs.
• read, write, malloc, free,
exit
• ft_printf and any equivalent
YOU coded
Libft authorized Yes
Description Sort stacks

Your project must comply with the following rules:
• You have to turn in a Makefile which will compile your source files. It must not
relink.
• Global variables are forbidden.
• You have to write a program named push_swap that takes as an argument the stack
a formatted as a list of integers. The first argument should be at the top of the
stack (be careful about the order).
• The program must display the smallest list of instructions possible to sort the stack
a, the smallest number being at the top.
• Instructions must be separated by a ’\n’ and nothing else.
• The goal is to sort the stack with the lowest possible number of operations. During
the evaluation process, the number of instructions found by your program will be
compared against a limit: the maximum number of operations tolerated. If your
program either displays a longer list or if the numbers aren’t sorted properly, your
grade will be 0.
• If no parameters are specified, the program must not display anything and give the
prompt back.
• In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates.

Project functions:

Take argument
Convert into arrays
Find the best algorithm
Do the algorithm
Print the moves


int pb(stack_a stack_a,  stack_b stack_b)
{
    long    temp;
    long    i;

    i = stack_b.curLen;
   if (!checkIfArray(stack_a.array))
        return (1);
    temp = stack_a.array[0];
     while (i)
     {
        stack_b.array[i] = stack_b.array[i - 1];
        i--;
    } 
    stack_b.array[0] = temp;
    while (i != stack_a.curLen)
    {
        stack_a.array[i] = stack_a.array[i + 1];
        i++;
    }
    stack_a.array[stack_a.iniLen] = 0;
    return (0);


    20 55 34 91 78 42 23 25 56 77 92 31 17 13 68 30 79 11 65 38 7 2 33 61 24 81 35 8 97 14 5 58 10 66 50 44 93 73 96 90 21 70 83 76 99 36 74 67 69 85 29 52 88 87 59 47 100 72 75 41 86 12 62 43 80 45 60 1 64 54 82 71 22 4 57 63 9 27 94 32 49 18 39 48 40 53 26 15 37 95 28 46 89 16 84 6 98 3 19 51 
    
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
