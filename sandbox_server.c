/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:56:05 by joteixei          #+#    #+#             */
/*   Updated: 2022/02/20 00:41:02 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*print_message(char *message)
{
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	free(message);
	return (NULL);
}

void	send_signal(int pid, int signum)
{
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	action(int sig, siginfo_t *info, void *nothing)
{
	static int	pid = 0;
	static int	bit = 0;
	static char	conv = 0xFF;
	static char	*message = 0;

	(void) nothing;
	if (info->si_pid)
		pid = info->si_pid;
	if (sig == SIGUSR1)
		conv |= 0x80 >> bit;
	else if (sig == SIGUSR2)
		conv ^= 0x80 >> bit;
	if (++bit == 8)
	{
		if (!conv)
		{
			message = print_message(message);
			send_signal(pid, SIGUSR2);
		}
		else
			message = ft_str_add_char(message, conv);
		bit = 0;
		conv = 0xFF;
	}
	send_signal(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
