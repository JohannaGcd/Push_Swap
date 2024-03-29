/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:58:50 by jguacide          #+#    #+#             */
/*   Updated: 2024/03/29 11:05:21 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*** METHOD ***
* Find the biggest node,
* if biggest node is at the top -> ra (rotate to the bottom)
* if it's second position -> rra (reverse rotate the bottom to the top)
* once bottomnode is the biggest, check if top node is bigger than second
* if so, complete the sorting by swapping the top and second nodes
*/

void	sort_three(t_list **a)
{
	t_list	*max_node;

	max_node = find_max_node(*a);
	if (*a == max_node)
		ra(a, true);
	else if ((*a)->next == max_node)
		rra(a, true);
	if ((*a)->content > (*a)->next->content)
		sa(a, true);
}
