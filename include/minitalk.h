#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(int ac, char **av);
void encode_and_send_bits(char ch, pid_t servers_pid);

int main();
void handle_signal (int signum);

#endif