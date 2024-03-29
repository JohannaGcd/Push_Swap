#include "push_swap.h"

int	main(int argc, char **argv)
{
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

	// HOW TO WAIT FOR INSTRUCTIONS TO PRINT?
	
	// get_next_line (stdin)
	// if X != all commands, display error, free and exit 
	// then execute. while (*X) if X == ra execute ra 
	if (!stack_sorted(stack_a) // or stack_b is not empty
		write(1, "KO\n", 3);
	else
	 	write(1, "OK\n", 3);
	ft_lstclear(&stack_a);
	return (0);
}

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
