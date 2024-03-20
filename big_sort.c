#include "push_swap.h"

/* METHOD
*	Push 2 nodes from a to b 
*	Then send a nodes to b while sorting them in descending order (target node should be the closest smallest node value).
*		Special case: if min value, then target node should be smallest value.
*	Once there are only 3 nodes left in a, sort them
*	Then send b nodes to a while sorting them in ascending order (target node should be the closest biggest)
*	Check that the minimum is on top, if not rotate.
*/

//This function checks whether the top node is indeed on top of the stack. 
//If not, it moves the node on top.
void    check_for_push(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_middle)
				ra(stack, true);
			else
			 	rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_middle)
				rb(stack, true);
			else
			 	rrb(stack, true);
		}
	}
		
}
void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b , true);
	set_index(*a);
	set_index(*b);
}

// Pushes the cheapest node to be pushed and its target node to the top of the stack 
void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, true);
	set_index(*a);
	set_index(*b);
}

// Pushes a to be, by first pushing the cheapest node & its target  to the top of the stack  
// double_checking that both nodes are on top
// and then pushing.
void	push_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_middle
		&& cheapest_node->target_node->above_middle)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_middle)
			&& !(cheapest_node->target_node->above_middle))
			rev_rotate_both(a, b, cheapest_node);
	check_for_push(a, cheapest_node, 'a');
	check_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, true);
}

void	min_on_top(t_list **stack)
{
	t_list	*min_node = find_min_node(*stack);
	while (*stack != min_node)
	{
		if (min_node->above_middle)
			ra(stack, true);
		else
		 	rra(stack, true);
	}
	
}
void	push_b_to_a(t_list **b, t_list **a)
{
	check_for_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

void	big_sort(t_list **a, t_list **b)
{
	int len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, true);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, true);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		push_a_to_b(a, b);
	}
	sort_three(a);	
	while (*b)
	{
		init_nodes_b(*b, *a);
		push_b_to_a(b, a);
	}
	min_on_top(a);
	

}

