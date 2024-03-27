#include "push_swap.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if ((argc == 1) || (argc == 2 && !argv[1][0]))
	{
		write(STDERR_FILENO, "Error\n", 6);
		//free_errors(&stack_a);
		//free_errors(&stack_b);
		return (1);

	}
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
		int i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}	
		free(argv);
	}
	ft_lstclear(&stack_a);	
	ft_lstclear(&stack_b); // clear only stack_a?
	return (0);
}
