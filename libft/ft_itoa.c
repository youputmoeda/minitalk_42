/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:24:54 by joteixei          #+#    #+#             */
/*   Updated: 2021/10/18 17:25:35 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static int	get_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*sub;
	size_t	len;

	len = get_len(n);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (0);
	sub[len] = '\0';
	if (n < 0)
		sub[0] = '-';
	else if (n == 0)
		sub[0] = '0';
	while (n != 0)
	{
		--len;
		sub[len] = absolute_value(n % 10) + '0';
		n /= 10;
	}
	return (sub);
}
