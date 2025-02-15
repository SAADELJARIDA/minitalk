/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:42:08 by sel-jari          #+#    #+#             */
/*   Updated: 2024/11/12 03:40:31 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'i' || c == 'd')
		len = ft_printf_id(va_arg(arg, int));
	else if (c == 'u')
		ft_printf_u(va_arg(arg, unsigned int));
	else if (c == 'c')
		len = ft_printf_c(va_arg(arg, int));
	else if (c == '%')
		len = ft_printf_c('%');
	else if (c == 's')
		len = ft_printf_s(va_arg(arg, char *));
	else if (c == 'x')
		len = ft_printf_x(va_arg(arg, unsigned int), 'x');
	else if (c == 'X')
		len = ft_printf_x(va_arg(arg, unsigned int), 'x');
	else
		len = ft_printf_p(va_arg(arg, void *));
	return (len);
}
