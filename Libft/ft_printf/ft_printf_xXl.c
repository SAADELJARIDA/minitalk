/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xXl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:22:10 by sel-jari          #+#    #+#             */
/*   Updated: 2024/11/07 20:57:54 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(unsigned int n, char c)
{
	unsigned int			l;
	char					*x;
	char					*xx;
	int						i;

	xx = "0123456789ABCDEF";
	x = "0123456789abcdef";
	i = 0;
	l = n;
	while (n / 16)
	{
		i++;
		n /= 16;
	}
	if (l / 16)
		ft_printf_x(l / 16, c);
	if (c == 'x')
		write(1, &x[l % 16], 1);
	else
		write(1, &xx[l % 16], 1);
	return (++i);
}

int	ft_printf_xl(unsigned long n, char c)
{
	unsigned long	l;
	char			*x;
	char			*xx;
	int				i;

	xx = "0123456789ABCDEF";
	x = "0123456789abcdef";
	i = 0;
	l = n;
	while (n / 16)
	{
		i++;
		n /= 16;
	}
	if (l / 16)
		ft_printf_xl(l / 16, c);
	if (c == 'x')
		write(1, &x[l % 16], 1);
	else
		write(1, &xx[l % 16], 1);
	return (++i);
}
