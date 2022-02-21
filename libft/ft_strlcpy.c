/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:51:46 by joteixei          #+#    #+#             */
/*   Updated: 2021/11/05 13:59:57 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	srcsize;

	if (!dest || !src)
		return (0);
	srcsize = ft_strlen(src);
	index = 0;
	if (size != 0)
	{
		while (src[index] != '\0' && index + 1 < size)
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (srcsize);
}
