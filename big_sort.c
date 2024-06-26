/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:49:40 by jguacide          #+#    #+#             */
/*   Updated: 2024/03/29 14:31:17 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_push(t_list **stack, t_list *top_node, char stack_name)
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

/*** METHOD **
* find the cheapest_node 
* check its relative position to the target node 
* depending on whether above or below middle, execute a particular command
* the command will stop once one of the two nodes is a the top of the stack
* so we use check_for_push to perform the last operations 
* 	to bring both nodes at the top, if necessary
* finally, push cheapest node to stack b
*/
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
	else if ((cheapest_node->above_middle)
		&& !(cheapest_node->target_node->above_middle))
		rotate_a_and_rev_b(a, b, cheapest_node);
	else if (!(cheapest_node->above_middle)
		&& (cheapest_node->target_node->above_middle))
		rotate_b_and_rev_a(a, b, cheapest_node);
	check_for_push(a, cheapest_node, 'a');
	check_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b, true);
}

void	push_b_to_a(t_list **b, t_list **a)
{
	check_for_push(a, (*b)->target_node, 'a');
	pa(b, a, true);
}

/*** METHOD ***
* Push the two first nodes from a to b 
* while the stack length is over 3, push nodes from a to b 
* 	while sorting them in descending order
* 	init_nodes_a initializes the nodes (index, target node, push cost)
* 	push a to b prepares the cheapest node found to be pushed to b
* then sort 3 nodes
* Perform the same from b to a, except now the nodes are already sorted
* 	we send them in ascending order this time
* 	Finally, ensure that the minimum node is on top.
***/

void	big_sort(t_list **a, t_list **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	pb(a, b, true);
	pb(a, b, true);
	len_a -= 2;
	while (len_a-- > 3)
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
	set_index(*a);
	min_on_top(a);
}
