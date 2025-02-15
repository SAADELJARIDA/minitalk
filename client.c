/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:28:03 by sel-jari          #+#    #+#             */
/*   Updated: 2025/02/15 00:28:24 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_reseived;

static void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_reseived = 1;
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
			ft_printf("Error: Server not responding, PID??");
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
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		server_responding();
	}
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	if (ac != 3)
		return (ft_printf("./<file.exe> <PID> <string> !!!!!!\n"));
	pid = ft_atoi(av[1]);
	if (!pid)
		return (ft_printf("PID not valid"));
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf("Error!\n"));
	i = 0;
	while (av[2][i])
		send_char_per_bit(av[2][i++], pid);
}
