/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:59:22 by jguacide          #+#    #+#             */
/*   Updated: 2024/03/29 10:00:05 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SWAP OPERATIONS
/* 
 * sa = swaps the positions of the first two nodes in a stack
 * sb = idem, with b
 * ss = swaps simultaneously the first two nodes of both a and b.
*/

void	swap(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_list **a, bool print)
{
	swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_list **b, bool print)
{
	swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		ft_printf("ss\n");
}
