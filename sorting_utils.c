#include "external_lib/src/libft/libft.h"
#include "push_swap.h"
#include <limits.h>

bool	stack_sorted(t_list *stack)
{
	if (!stack)
		return (NULL);
	// goes through the stack and returns false if a value is bigger than the following one.
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// Function which returns the length of the stack
int		length_stack(t_list *stack)
{
	if (!stack)
		return (0);
	t_list *temp;
	int len = 0;	

	temp = stack;
	while (temp != NULL) // counts untill the stack becomes NULL.
	{
		temp = temp->next;	
		len++;
	}
	return (len);
}

// Function which finds & returns last node 
t_list	*find_last_node(t_list *stack)
{
	if (!stack)
		return (NULL);
	
	t_list	*temp;
	temp = stack;
	while (temp->next != NULL) // finds the last node in the stack (the one which points to NULL).
		temp = temp->next;
	return (temp);
}

// Function which finds & returns the node with the maximum number.
t_list	*find_max_node(t_list *stack)
{
	if (!stack)
		return (NULL);

	long	max;
	t_list	*max_node;
	t_list	*temp;
	
	temp = stack;
	max_node = stack;
	max = LONG_MIN; 
	while (temp)
	{
		if (temp->content > max)
		{
			max = temp->content;
			max_node = temp;
		}
		temp = temp->next;
	}
	return (max_node);
}

// Function which finds & returns the node with the minimum number.
t_list	*find_min_node(t_list *stack)
{
	if (!stack)
		return (NULL);
	
	t_list	*temp;
	t_list	*min_node;
	long	min;

	temp = stack;
	min = LONG_MAX;
	while (temp)
	{
		if (temp->content < min)
		{
			min = temp->content;
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

t_list	*get_cheapest(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
