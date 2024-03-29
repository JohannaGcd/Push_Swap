/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:51:50 by jguacide          #+#    #+#             */
/*   Updated: 2024/03/29 10:01:59 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*** METHOD ***
* error_syntax checks for syntax errors (not a sign or digit) 
* error_duplicate checks for duplicates
* free_errors frees each node in the stack
* 	then sets head to NULL and exits the program
*/

int	error_syntax(char *s)
{
	int	i;

	i = 0;
	if (!(s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9')))
		return (1);
	if ((s[i] == '+' || s[i] == '-') && (!(s[i + 1] >= '0' && s[i + 1] <= '9')))
		return (1);
	while (s[++i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_list *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->content == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_errors(t_list **a)
{
	ft_lstclear(a);
	write(2, "Error\n", 6);
	exit(1);
}
