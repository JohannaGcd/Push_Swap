#include "external_lib/src/libft/libft.h"
#include "push_swap.h"

// This function initializes the stack with the command line arguments, while checking for errors. 
void	stack_init(t_list **a, char **argv)
{
	int	i;
	long n = 0;

	i = 0;
	while (argv[i] != NULL)
	{
		if (error_syntax(argv[i]))
		{
			free_errors(a);
			exit (1);
		}
		n = ft_atol(argv[i]); // use ft_atol to avoid overflow while checking for MAX/MIN values.
		if (n > INT_MAX || n < INT_MIN)
		{
			free_errors(a);
			exit (1);
		}
		if (error_duplicate(*a, (int)n)) // cast to an int to convert the value obtained fromt ft_atol
		{
			free_errors(a);
			exit (1);
		}
		append_node(a, (int)n);
		i++;
	}
	//swap(a);
	//rotate(a);
	//reverse_rotate(a);
}

// variation of ft_atol: instead of an int, we use a long to protect against overflow.
long	ft_atol(const char *s)
{
	long	n;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	n = 0;
	while (s[i] && ((s[i] >= 8 && s[i] <= 13) || s[i] == ' '))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = (n * 10) + (s[i] - '0');
		i++;
	}
	return (n * sign);
}

// This function appends n as a new node at the end of the stack.
void	append_node(t_list **stack, int n)
{
	t_list	*new_node;

	if (!stack)
		return ;
	new_node = ft_lstnew(n);
	ft_lstadd_back(stack, new_node);	
}
