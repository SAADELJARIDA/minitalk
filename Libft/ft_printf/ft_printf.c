/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:22:38 by sel-jari          #+#    #+#             */
/*   Updated: 2025/02/15 19:08:11 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += ft_conversion(*format, arg);
			format++;
		}
		else
		{
			write(1, format, 1);
			format++;
			len++;
		}
	}
	va_end(arg);
	return (len);
}
