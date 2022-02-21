/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformers1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:06:42 by joteixei          #+#    #+#             */
/*   Updated: 2022/02/10 12:48:45 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putnbr_base_printf(ssize_t nbr, char *base)
{
	ssize_t		size_base;
	static int	count;

	count = 0;
	size_base = 0;
	size_base = ft_strlen(base);
	if (nbr == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (nbr < 0)
	{
		count += ft_putchar_printf_fd('-', 1);
		nbr = -nbr;
	}
	return (count + ft_putnbr_aux(nbr, size_base, 1, 1));
}

int	ft_putnbr_aux(size_t nbr, size_t size_base, int fd, int type)
{
	char			base[17];
	static int		tmp;

	tmp = 0;
	if (size_base == 16)
	{
		if (type == 1)
			ft_strlcpy_printf(base, "0123456789abcdef", 16);
		else
			ft_strlcpy_printf(base, "0123456789ABCDEF", 16);
	}
	else
		ft_strlcpy_printf(base, "0123456789", 10);
	if (nbr < size_base)
		tmp += ft_putchar_printf_fd(base[nbr], 1);
	else
	{
		ft_putnbr_aux(nbr / size_base, size_base, fd, type);
		nbr = nbr % size_base;
		tmp += ft_putchar_printf_fd(base[nbr], 1);
	}
	return (tmp);
}
