/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 08:46:57 by jguacide          #+#    #+#             */
/*   Updated: 2024/04/02 11:29:38 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include "../push_swap.h"
# include <stdbool.h>
# include <unistd.h>

#define BUFFER_SIZE 10

/*typedef struct b_list
{
	char			str_buf;
	struct s_list	*next;
}					c_list;*/


int		ft_strcmp(char *s1, char *s2);
void	errors(t_list **stack_a, t_list **stack_b);
void	parse_commands(t_list **stack_a, t_list **stack_b, char *command);
void	*ft_free(char **s);
char	*get_next_line(int fd);

#endif
