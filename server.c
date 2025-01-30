#include "libft.h"
#include "minitalk.h"

void handle_signal (int signum)
{
    static int bit_counter = 0;
    static char ch = 0;

    if (signum == SIGUSR1)
    ch << 1;
    else if (signum == SIGUSR2)
    ch = ch | 1;

    if (bit_counter == 7)
    {
        write(1, &ch, 1);
        static int bit_counter = 0;
        static int ch = 0;
    }
    else
    {
        bit_counter++;
    }
    
}

int main()
{
    pid_t servers_pid = getpid();
    ft_printf("PID: %d\n", servers_pid);

    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
    {
        //wait for signals from client
        pause();

    }    
}