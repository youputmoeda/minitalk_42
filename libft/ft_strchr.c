/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:50:03 by joteixei          #+#    #+#             */
/*   Updated: 2021/10/18 17:50:05 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	index;

	if (str)
	{
		index = 0;
		if (str[index] == (char)c)
			return ((char *)str);
		while (str[index++])
			if (str[index] == (char)c)
				return ((char *)str + index);
	}
	return (NULL);
}
