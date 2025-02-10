/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <sel-jari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:45:48 by sel-jari          #+#    #+#             */
/*   Updated: 2024/11/01 08:42:19 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_it(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && is_it(s1[start], set))
		start++;
	while (end > start && is_it(s1[end], set))
		end--;
	return (ft_substr(s1, start, end + 1 - start));
}
