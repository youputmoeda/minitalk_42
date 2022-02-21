/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:50:29 by joteixei          #+#    #+#             */
/*   Updated: 2021/11/05 17:51:16 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		len;
	int		index;

	if (src)
	{
		index = 0;
		len = ft_strlen(src);
		str = malloc((len + 1) * sizeof(char));
		if (!str)
			return (NULL);
		while (src[index])
		{
			str[index] = src[index];
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}
