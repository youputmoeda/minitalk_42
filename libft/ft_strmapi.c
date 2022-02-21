/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:58:15 by joteixei          #+#    #+#             */
/*   Updated: 2021/10/18 17:58:23 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s || !f)
		return (0);
	sub = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!sub)
		return (0);
	while (s[i] != '\0')
	{
		sub[i] = f(i, s[i]);
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
