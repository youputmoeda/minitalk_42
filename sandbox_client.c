/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox_client.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:26:59 by joteixei          #+#    #+#             */
/*   Updated: 2022/02/21 10:36:33 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	check_pid(const char *str)
{
	while (*str && ft_isdigit(*str))
		str++;
	return (!*str);
}

void	signal_handler(int sig)
{
	static int	flag = 1;

	if (sig == SIGUSR1 && flag)
	{
		ft_putstr_fd("\nMessage sent ", 1);
		flag = 0;
	}
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("-> Message recieved \n", 1);
		flag = 1;
		exit(EXIT_SUCCESS);
	}
}

void	send_bites(char *message, int pid)
{
	int	char_message;
	int	bit;

	char_message = 0;
	bit = -1;
	if (!message)
		exit(EXIT_FAILURE);
	while (1)
	{
		bit = -1;
		while (++bit < 8)
		{
			if (message[char_message] & (0x80 >> bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else if (kill(pid, SIGUSR2) == -1)
				exit(1);
			usleep(100);
		}
		if (!message[char_message])
			break ;
		char_message++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("Número de argumentos errados\n");
		exit(EXIT_FAILURE);
	}
	if (!check_pid(argv[1]))
	{
		ft_printf("No PID não se encontra apenas números\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	ft_printf("Sending message to %d", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	send_bites(argv[2], pid);
}
