/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:26:53 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/30 19:27:04 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

void	encode_and_send_bits(char ch, pid_t servers_pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (ch & (1 << i))
			kill(servers_pid, SIGUSR2);
		else
			kill(servers_pid, SIGUSR1);
		i--;
		usleep(500);
	}
}

void	response_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	ft_printf("Received!");
	exit(0);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				servers_pid;
	const char			*message = av[2];
	int					letter;

	if (ac != 3)
		return (1);
	if (atoi(av[1]) < 0)
		exit(-1);
	servers_pid = (pid_t)ft_atoi(av[1]);
	sa.sa_sigaction = response_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	letter = 0;
	while (message[letter] != '\0')
	{
		encode_and_send_bits(message[letter], servers_pid);
		letter++;
	}
	encode_and_send_bits('\0', servers_pid);
	while (1)
		pause();
	return (0);
}
