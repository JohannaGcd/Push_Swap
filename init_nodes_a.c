#include "push_swap.h"

// This function finds the a target_node in b:
// it should be the closest smaller number
// to sort in ascending order.
// if min value, target_node should be max.
void	set_target_a(t_list *stack_src, t_list *stack_dest)
{
	t_list	*current_dest;
	t_list	*target_node;
	long	best_match_index;

	while (stack_src)
	{
		best_match_index = LONG_MIN;
		current_dest = stack_dest;
		while (current_dest)
		{
			if (current_dest->content < stack_src->content
				&& current_dest->content > best_match_index)
			{
				best_match_index = current_dest->content;
				target_node = current_dest;
			}
			current_dest = current_dest->next;
		}
		if (best_match_index == LONG_MIN)
			stack_src->target_node = find_max_node(stack_dest);
		else
			stack_src->target_node = target_node;
		stack_src = stack_src->next;
	}
}

// Determines a node's push cost
// relative to its own & it's target node's position
void	set_push_cost(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		if (a->above_middle)
			a->push_cost = a->index;
		else
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_middle)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

// Determines the cheapest node to push.
// Methode: iterates through the push_costs of each
void	set_cheapest(t_list *stack)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		stack->cheapest = false;
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

// This function sets the index value (position in the stack)
// and determines if the node is below or above the middle of the stack
// (this helps to calculate the push cost)
void	set_index(t_list *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (!stack)
		return ;
	middle = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->above_middle = true;
		else
			stack->above_middle = false;
		stack = stack->next;
		i++;
	}
}

// This function initializes all the nodes with the relevant information:
// (index, above/below middle, target, push_cost & sets boolean for cheapest.
void	init_nodes_a(t_list *a, t_list *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	set_push_cost(a, b);
	set_cheapest(a);
}
