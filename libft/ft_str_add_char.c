/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:31:00 by joteixei          #+#    #+#             */
/*   Updated: 2022/02/19 23:57:20 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_add_char(char *str, char c)
{
	char	*tmp;
	size_t	index;

	if (!c)
		return (NULL);
	if (!str)
		return (ft_char_to_str(c));
	tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!tmp)
	{
		free(str);
		return (NULL);
	}
	index = 0;
	while (str[index] != '\0')
	{
		tmp[index] = str[index];
		index++;
	}
	free(str);
	tmp[index++] = c;
	tmp[index] = '\0';
	return (tmp);
}
