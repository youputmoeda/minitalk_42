/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:04:49 by joteixei          #+#    #+#             */
/*   Updated: 2022/02/10 18:37:42 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	ft_decider(char *flag, va_list *ap)
{
	if (*flag == 'c' || *flag == 'C')
		return (ft_putchar_printf_fd(va_arg(*ap, int), 1));
	if (*flag == 's')
		return (ft_putstr_printf_fd(va_arg(*ap, char *), 1));
	if (*flag == 'p')
		return (ft_put_adress_fd(va_arg(*ap, unsigned long), 1));
	if (*flag == 'd' || *flag == 'D' || *flag == 'i')
		return (ft_putnbr_base_printf(va_arg(*ap, int), "0123456789"));
	if (*flag == 'u' || *flag == 'U')
		return (ft_putnbr_aux(va_arg(*ap, unsigned int), 10, 1, 1));
	if (*flag == 'x')
		return (ft_putnbr_aux(va_arg(*ap, unsigned int), 16, 1, 1));
	if (*flag == 'X')
		return (ft_putnbr_aux(va_arg(*ap, unsigned int), 16, 1, 0));
	if (*flag == '%')
		ft_putchar_printf_fd(*flag, 1);
	return (1);
}

static int	ft_printf_main(va_list *ap, char *flag)
{
	int	size_str;

	size_str = 0;
	while (*flag)
	{
		if (*flag == '%')
		{
			flag++;
			if (ft_is_equal(*flag, "cCspdDiuUxX%"))
			{
				size_str += ft_decider(flag, ap);
			}
			else
				return (size_str);
		}
		else
			size_str += write(1, flag, 1);
		flag++;
	}
	return (size_str);
}

int	ft_printf(const char *flag, ...)
{
	int		size_str;
	va_list	ap;

	if (!flag)
		return (-1);
	size_str = 0;
	va_start(ap, flag);
	size_str = ft_printf_main(&ap, (char *)flag);
	va_end(ap);
	return (size_str);
}
