/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_idu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:23:13 by sel-jari          #+#    #+#             */
/*   Updated: 2024/11/02 12:23:14 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printf_id(int n)
{
	int		i;
	long	l;

	i = 0;
	l = n;
	if (l < 0)
	{
		write(1, "-", 1);
		l = -l;
	}
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	if (l / 10)
		ft_printf_id(l / 10);
	l = l % 10 + '0';
	write(1, &l, 1);
	return (++i);
}

int	ft_printf_u(unsigned int n)
{
	unsigned int	l;
	int				i;

	i = 0;
	l = n;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	if (l / 10)
		ft_printf_id(l / 10);
	l = l % 10 + '0';
	write(1, &l, 1);
	return (++i);
}
