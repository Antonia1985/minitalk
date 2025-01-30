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

void encode_and_send_bits(char ch, pid_t servers_pid)
{
    int i = 0;
    while (i < 8)
    {
        if (ch & (1 << i))
        kill(servers_pid, SIGUSR2); //1
        else 
        kill(servers_pid, SIGUSR1); //0

        i++;
        usleep(100);
    }
}

int main(int ac, char **av)
{
    if(ac != 3)
    return (1);
   
    pid_t servers_pid = (pid_t )ft_atoi(av[1]);
    const char *message = av[2];

    int letter = 0;
    while (message[letter] != '\0')
    {
        encode_and_send_bits(message[letter], servers_pid);       
        letter++;
    }
    encode_and_send_bits('\0', servers_pid);

   return(0);    
}
