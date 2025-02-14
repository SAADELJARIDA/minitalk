/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:34:34 by sel-jari          #+#    #+#             */
/*   Updated: 2025/02/15 00:34:40 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	count;

	(void)context;
	if (signum == SIGUSR1)
	{
		c = (c << 1) | 1;
	}
	else
	{
		c = (c << 1);
	}
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	printf("PID :%d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
