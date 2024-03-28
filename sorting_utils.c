#include "push_swap.h"

// Returns false if a value is bigger than the following one.
bool	stack_sorted(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// Returns the length of the stack
int	length_stack(t_list *stack)
{
	t_list	*temp;
	int		len;

	if (!stack)
		return (0);
	temp = stack;
	len = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

// Returns the last node
t_list	*find_last_node(t_list *stack)
{
	t_list	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

// Returns the node with the maximum number
t_list	*find_max_node(t_list *stack)
{
	long	max;
	t_list	*max_node;
	t_list	*temp;

	if (!stack)
		return (NULL);
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

// Returns the node with the minimum number
t_list	*find_min_node(t_list *stack)
{
	t_list	*temp;
	t_list	*min_node;
	long	min;

	if (!stack)
		return (NULL);
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
