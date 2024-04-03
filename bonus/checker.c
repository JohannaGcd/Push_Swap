/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:13:36 by jguacide          #+#    #+#             */
/*   Updated: 2024/04/03 16:13:03 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**check_input(int argc, char *argv[], t_list **stack_a)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		{
			if (argv == NULL)
				return (NULL);
		}
		stack_init(stack_a, argv);
	}
	else
		stack_init(stack_a, argv + 1);
	return (argv);
}

void	check_sort_bonus(t_list **stack_a, int len_a)
{
	if (!stack_sorted(*stack_a) || ft_lstsize(*stack_a) != len_a)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	char	*next_line;
	t_list	*stack_a;
	t_list	*stack_b;
	int		len_a;

	stack_a = NULL;
	stack_b = NULL;
	len_a = 0;
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (0);
	else
	{
		argv = check_input(argc, argv, &stack_a);
		if (argv == NULL)
			return (ft_putstr_fd("ERROR\n", 2), 1);
	}
	len_a = ft_lstsize(stack_a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_commands(&stack_a, &stack_b, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	check_sort_bonus(&stack_a, len_a);
	ft_free_argv(argv);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
