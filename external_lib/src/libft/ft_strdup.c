/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguacide <jguacide@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:48:53 by jguacide          #+#    #+#             */
/*   Updated: 2023/10/25 10:49:50 by jguacide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*s_copy;

	i = 0;
	len = ft_strlen(s);
	s_copy = malloc(len + 1);
	if (!s_copy)
		return (NULL);
	else
	{
		while (s[i])
		{
			s_copy[i] = s[i];
			i++;
		}
	}
	s_copy[i] = '\0';
	return (s_copy);
}
