/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:45:12 by sel-jari          #+#    #+#             */
/*   Updated: 2025/02/06 07:02:39 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"
void main(int ac,const char **av)
{
	int	pid;
	if (*av[2] == '0')
	{
		pid = ft_atoi(av[1]);
		kill(pid, SIGUSR1);
	}
}
