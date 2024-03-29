/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:58:45 by jguacide          #+#    #+#             */
/*   Updated: 2024/03/29 10:00:05 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ROTATE OPERATIONS
/* 
 * ra = rotates top a node to the bottom and shifts the remaining nodes upwords
 * rb = idem, with b
 * rr = rotates top nodes of both stacks to the bottom 
 * 	and shifts the remaining nodes upwords
 *
 * rra = brings bottom node to the top of stack a 
 * 	and shifts rets of the nodes downwards
 * rrb = idem, with b
 * rrr = simultaneously reverse rotating both stacks at the same time.
*/

void	rotate(t_list **stack)
{
	t_list	*last_node;

	last_node = ft_lstlast(*stack);
	if (!*stack || !(*stack)->next)
		return ;
	last_node->next = *stack;
	*stack = (*stack)->next;
	last_node->next->next = NULL;
	last_node = ft_lstlast(*stack);
}

void	ra(t_list **a, bool print)
{
	rotate(a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_list **b, bool print)
{
	rotate(b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_printf("rr\n");
}

void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b, true);
	set_index(*a);
	set_index(*b);
}
