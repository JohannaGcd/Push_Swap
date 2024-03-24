#include "external_lib/src/ft_printf/ft_printf.h"
#include "external_lib/src/libft/libft.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
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
		{
			printf("before: \n");
			print_all(&stack_a);
			sa(&stack_a, true);
			printf("after: \n");
			print_all(&stack_a);
		}
		else if (ft_lstsize(stack_a) == 3)
		{
			printf("before: \n");
			print_all(&stack_a);
			sort_three(&stack_a);
			printf("before: \n");
			print_all(&stack_a);

		}
		else if (ft_lstsize(stack_a) == 4)
			sort_four(&stack_a, &stack_b);
		else if (ft_lstsize(stack_a) == 5)
			sort_five(&stack_a, &stack_b);
		else
		{
			printf("before: \n");
			print_all(&stack_a);
			big_sort(&stack_a, &stack_b);	
			printf("after: \n");
			print_all(&stack_a);
		}
	if (stack_sorted(stack_a))
		ft_printf("It works!");
	else
	 	ft_printf("It didn't. Good luck!");
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

//TO DO
// 3. code commands
// do stack sorted in main
