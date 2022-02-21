/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:10:47 by joteixei          #+#    #+#             */
/*   Updated: 2022/02/10 12:48:56 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *flag, ...);
int		ft_putchar_printf_fd(char c, int fd);
int		ft_putnbr_base_printf(ssize_t nbr, char *base);
int		ft_putnbr_aux(size_t nbr, size_t size_base, int fd, int type);
int		ft_putstr_printf_fd(char *s, int fd);
int		ft_is_equal(char c, char *str);
int		ft_put_adress_fd(unsigned long addr, int fd);
void	ft_strlcpy_printf(char *dest, const char *src, size_t size);

#endif