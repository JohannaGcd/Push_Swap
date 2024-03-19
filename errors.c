#include "push_swap.h"

int error_syntax(char *s)
{
	int i;
	i = 0;
	// if not '+' or '-' or number, return error (1).
	if (!(s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9')))
		return (1);
	// if '+' or '-' but next character is not a number, return error (1).
	if ((s[i] == '+' || s[i] == '-') && (!(s[i + 1] >= '0' && s[i + 1] <= '9')))
 		return (1);
  	// check the rest of the string, return error if not a digit.
	while (s[++i])
  	{
		if (!(s[i] >= '0' && s[i] <= '9'))
  			return (1);
	}
	return (0);
}

int	error_duplicate(t_list *a, int n)
{
	// check for empty stack
	if (!a)
		return (0);
	// go through stack a, if n is encountered, return error (1);
	while (a)
	{
		if (a->content == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_errors(t_list **a)
{
	// this function goes through the stack, frees each node & sets the head to NULL and exits the program.
	ft_lstclear(a);
	ft_printf("Error\n");
	exit (1);
}
	
