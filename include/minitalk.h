/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:28:23 by apavlopo          #+#    #+#             */
/*   Updated: 2025/01/30 19:28:48 by apavlopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

void	encode_and_send_bits(char ch, pid_t servers_pid);
void	handle_signal(int signum, siginfo_t *info, void *context);
void	response_handler(int signum, siginfo_t *info, void *context);

#endif
