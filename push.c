/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:58:25 by jguacide          #+#    #+#             */
/*   Updated: 2024/03/29 10:00:05 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PUSH OPERATIONS
/* 
 * pa = pushes the top node of b on top of stack a
 * pb = pushes the top node of a on top of stack b
*/

void	push(t_list **src, t_list **dest)
{
	t_list	*push_node;
	t_list	*temp_src_head;
	t_list	*temp_dest_head;

	if (!*src)
		return ;
	temp_src_head = *src;
	*src = (*src)->next;
	push_node = temp_src_head;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		temp_dest_head = *dest;
		*dest = push_node;
		(*dest)->next = temp_dest_head;
	}
}

void	pa(t_list **b, t_list **a, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pb\n");
}
