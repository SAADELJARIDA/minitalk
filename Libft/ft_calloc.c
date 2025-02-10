/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <sel-jari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:21:49 by sel-jari          #+#    #+#             */
/*   Updated: 2024/10/27 13:23:34 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t ne, size_t size)
{
	void	*ptr;

	ptr = malloc(ne * size);
	if (ptr)
		ft_bzero(ptr, size * ne);
	return (ptr);
}
