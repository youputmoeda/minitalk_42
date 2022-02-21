/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:15:55 by joteixei          #+#    #+#             */
/*   Updated: 2021/10/19 18:16:12 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strcounter(const char *str, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] != c && str[i] != '\0')
			i++;
		while (str[i] == c && str[i] != '\0')
			i++;
		counter++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		start;

	new = malloc(sizeof(char *) * (strcounter(s, c) + 1));
	if (!s || !new)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		new[j] = ft_substr(s, start, i - start);
		j++;
	}
	new[j] = NULL;
	return (new);
}
