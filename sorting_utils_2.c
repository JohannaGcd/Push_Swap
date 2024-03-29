/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:59:08 by jguacide          #+#    #+#             */
/*   Updated: 2024/03/29 10:00:05 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_and_rev_b(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
	{
		ra(a, true);
		rrb(b, true);
	}
	set_index(*a);
	set_index(*b);
}

void	rotate_b_and_rev_a(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
	{
		rb(b, true);
		rra(a, true);
	}
	set_index(*a);
	set_index(*b);
}

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

void	min_on_top(t_list **stack)
{
	t_list	*min_node;

	min_node = find_min_node(*stack);
	while ((*stack)->content != min_node->content)
	{
		if (min_node->above_middle)
			ra(stack, true);
		else
			rra(stack, true);
	}
}

void	print_all(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d ", temp->content);
		temp = temp->next;
	}
	printf("\n");
}
