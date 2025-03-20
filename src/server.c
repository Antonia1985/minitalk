/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:24 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/30 19:27:35 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	bit_counter = 0;
	static char	ch = 0;
	pid_t		client_pid;

	client_pid = info->si_pid;
	(void)context;
	ch = ch << 1;
	if (signum == SIGUSR2)
		ch |= 1;
	bit_counter++;
	if (bit_counter == 8)
	{
		if (ch == '\0')
		{
			kill(client_pid, SIGUSR1);
		}
		write(1, &ch, 1);
		bit_counter = 0;
		ch = 0;
	}
}

int	main(void)
{
	pid_t				servers_pid;
	struct sigaction	sa;

	servers_pid = getpid();
	ft_printf("PID: %d\n", servers_pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
