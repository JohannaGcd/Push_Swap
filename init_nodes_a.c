# include "push_swap.h"

// This functions finds the a target_node in b: it should be the closest smaller number
void set_target_a(t_list *stack_src, t_list *stack_dest)
{
	t_list	*current_dest;
	t_list	*target_node;
	long	best_match_index;

	while (stack_src)
	{
		best_match_index = LONG_MAX;
		current_dest = stack_dest;
		while (current_dest)
		{
			if (current_dest->content > stack_src->content 
				&& current_dest->content < best_match_index)
			{
				best_match_index = current_dest->content;
				target_node = current_dest;
			}
			current_dest = current_dest->next;
		}
		if (best_match_index == LONG_MAX)
			stack_src->target_node = find_min_node(stack_dest);
		else
		 	stack_src->target_node = target_node;
		stack_src = stack_src->next;
	}
}

// Determines a nodes' push cost relative to its own and it's target node's position in the stacks:
// a push_cost is initially get to its index value 
// if a is below the middle, it is stack's length minus the index (essentially how far is it from the top)
// if its target node is above median, add the index of the target node. 
// if it is below the median, add the length of stack b minus the index of the target node in b
 
void	set_push_cost(t_list *a, t_list *b) // modify to include if a is above and b below
{
	int len_a;
	int len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_middle))
			a->push_cost += len_a - (a->index);
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

	cheapest_value = LONG_MAX;
	while (stack)
	{
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
// and determines if the node is below or above the middle of the stack (this helps to calculate the push cost)
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
// This function initializes all the nodes with index number, target node, push_cost and then sets boolean value cheapest.
void	init_nodes_a(t_list *a, t_list *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b); 
	set_push_cost(a, b);
	set_cheapest(a);
}
