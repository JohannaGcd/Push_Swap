/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:51:39 by jguacide          #+#    #+#             */
/*   Updated: 2024/04/03 16:13:03 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	errors(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

void	parse_commands(t_list **stack_a, t_list **stack_b, char *command)
{
	if (ft_strcmp(command, "sa\n") == 0)
		sa(stack_a, false);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(stack_b, false);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(stack_a, stack_b, false);
	else if (ft_strcmp(command, "pa\n") == 0)
		pa(stack_b, stack_a, false);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(stack_a, stack_b, false);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(stack_a, false);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(stack_b, false);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(stack_a, stack_b, false);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(stack_a, false);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(stack_b, false);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(stack_a, stack_b, false);
	else
		errors(stack_a, stack_b);
}

void	ft_free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
