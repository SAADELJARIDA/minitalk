/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:25:03 by sel-jari          #+#    #+#             */
/*   Updated: 2025/02/15 00:28:24 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_reseived;

static void	handler(int signum)
{
	static int	i;

	if (signum == SIGUSR1)
	{
		printf("Signal %d has been reseived\n", ++i);
		g_reseived = 1;
	}
}

static void	server_responding(void)
{
	int	i;

	i = 0;
	while (g_reseived == 0)
	{
		i++;
		usleep(100);
		if (i == 1000)
		{
			printf("Error : Server not responding, check the Server PID !\n");
			exit(1);
		}
	}
}

static void	send_char_per_bit(char byte, int pid)
{
	int			bit;

	bit = 8;
	while (--bit >= 0)
	{
		g_reseived = 0;
		if ((byte >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		server_responding();
	}
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	if (ac != 3)
		return (printf("./<file.exe> <PID> <string> !!!!!!\n"));
	pid = ft_atoi(av[1]);
	if (!pid)
		return (printf("PID not valid"));
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (printf("Error!\n"));
	i = 0;
	while (av[2][i])
		send_char_per_bit(av[2][i++], pid);
}
