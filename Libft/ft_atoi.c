/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <sel-jari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:07:20 by sel-jari          #+#    #+#             */
/*   Updated: 2025/02/15 20:01:10 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_two(char *a, int i, int dec)
{
	while (ft_isdigit(*a))
	{
		i++;
		if (i > 10)
		{
			write(1, "Pid is not valid", 16);
			exit(1);
		}
		dec *= 10;
		dec += *(a++) - '0';
	}
	if (*a)
	{
		write(1, "Pid is not valid", 16);
		exit(1);
	}
	return (dec);
}

int	ft_atoi(char *a)
{
	int	dec;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	dec = 0;
	while (*a == ' ' || (*a >= 9 && *a <= 13))
		a++;
	if (*a == '-')
	{
		write(1, "Pid is not valid", 16);
		exit(-1);
	}
	else if (*a == '+')
		a++;
	dec = atoi_two(a, i, dec);
	return (sign * dec);
}
