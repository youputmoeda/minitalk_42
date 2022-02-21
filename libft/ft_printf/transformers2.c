/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:07:35 by joteixei          #+#    #+#             */
/*   Updated: 2022/02/10 12:47:32 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_printf_fd(char *str, int fd)
{
	int	count;

	if (!str)
		return (write(fd, "(null)", 6));
	count = 0;
	while (str[count])
		count += ft_putchar_printf_fd(str[count], fd);
	return (count);
}

int	ft_is_equal(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_put_adress_fd(unsigned long addr, int fd)
{
	if (!addr)
		return (write(fd, "0x0", 3));
	return (write(fd, "0x", 2) + ft_putnbr_aux(addr, 16, fd, 1));
}

void	ft_strlcpy_printf(char *dest, const char *src, size_t size)
{
	while (size)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
}
