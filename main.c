#include "push_swap.h"

/***METHOD***
* initialize two stacks and an index
* check if number of arguments is 1 (only program name)
* 	or 2 (but empty string), return 0
* if argc is 2, then input is a string. 
* 	send it to ft_split before initializing the stack.
* otherwise, send argv+1 (ignore program name) to stack_init, 
* 	stack_init contains the checkers for input erros
* if the stack is not already sorted, 
* 	proceed with sorting (depending on the number of arguments)
* if input was a string, don't forget to free.
* free both stacks at the end.
* **/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

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
	if (!stack_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a, true);
		else if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else if (ft_lstsize(stack_a) == 4)
			sort_four(&stack_a, &stack_b);
		else if (ft_lstsize(stack_a) == 5)
			sort_five(&stack_a, &stack_b);
		else
			big_sort(&stack_a, &stack_b);
	}
	if (argc == 2)
	{
		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
