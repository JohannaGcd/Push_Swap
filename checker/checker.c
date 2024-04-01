#include "push_swap.h"
#include <stdbool.h>
#include <unistd.h>



void	parse_commands(t_list **stack_a, t_list **stack_b, char *command)
{
	if (ft_strcmp(command, "sa\n") == 0)
		sa(stack_a, stack_b, true);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(stack_a, stack_b, true);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(stack_a, stack_b, true);
	else if (ft_strcmp(command, "pa\n") == 0)
		pa(stack_a, stack_b, true);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(stack_a, stack_b, true);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(stack_a, stack_b, true);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(stack_a, stack_b, true);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(stack_a, stack_b, true);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(stack_a, stack_b, true);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(stack_a, stack_b, true);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(stack_a, stack_b, true);
	else
	{
		free_errors(stack_a);
		free_errors(stack_b);
	}
}

int	main(int argc, char **argv)
{
	int		len;
	char	*next_line
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		stack_init(&stack_a, argv);
	}
	else
		stack_init(&stack_a, argv + 1);
	len = ft_lstsize(stack_a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_commands(&stack_a, &stack_b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (!stack_sorted(stack_a) || stack_len(stack_a) != len)
		write(1, "KO\n", 3);
	else
	 	write(1, "OK\n", 3);
	ft_lstclear(&stack_a);
	return (0);
}

// TASK:
// Create a checker that takes as an argument the stack a, formatted as a list of integers 
// if no argument, it stops and displays nothing
// Then it waits and reads te instructions on the standard input. Each instruction will be followed by \n 
// Once all the instructions have been read, the program execytes them on the stck received as an argyment.
// if after executing those instructions, the stack is sorted and b is empty, the program must display OK followd by \n 
// Otherwise, KO\n
// In case of error, display "Error\n"on the standard error. 
// 	Example of errors: some arguments are not integers, bigger than integers, duplicates, an instruction doesn't exist or is not formatted correctly.

// PSEUDO CODE MAIN.c: 
// initiate stack a and b. 
// Check if stdin is empty. if yes, exit. 
// stack a is initialized with a list of integers read from stdin.
// while initialized, check for wrong input. Free and display Error if it is the case.
// Once initialized, wait for the instructions to print.
// then read from stdin ALL the instructions (and check for error. if error, display error free and exit), THEN execute the commands there.
// once all commands are executed, check if list is sorted. 
// if yes, display OK\n
// if not, display KO\n
// free stack a and b 

// PSEUDO CODE MAKEFILE
// I need get next line 
// Modify my push_swap Makefile so that it compiles with rule bonus
// rule bonus should compile my bonus_main along with the helper libraries
// Modify my push_swap Makefile so that target fclean reaches bonus as well.
