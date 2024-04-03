/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 08:46:57 by jguacide          #+#    #+#             */
/*   Updated: 2024/04/03 16:07:45 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include "../push_swap.h"
# include "../external_lib/src/get_next_line/get_next_line.h"
# include "../external_lib/src/ft_printf/ft_printf.h"
# include <stdbool.h>
# include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	errors(t_list **stack_a, t_list **stack_b);
void	parse_commands(t_list **stack_a, t_list **stack_b, char *command);
void	check_sort_bonus(t_list **stack_a, int len_a);
char	**check_input(int argc, char *argv[], t_list **stack_a);
void	ft_free_argv(char **argv);

#endif
