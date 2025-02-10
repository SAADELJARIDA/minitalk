/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <sel-jari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:41:51 by sel-jari          #+#    #+#             */
/*   Updated: 2024/11/08 00:19:17 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	count_words(const char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			continue ;
		}
		words++;
		while (!(str[i] == c) && str[i])
			i++;
	}
	return (words);
}

static void	ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	find_and_count(char const *str, char c, int *i)
{
	int	chars;

	if (str[*i] == c)
	{
		(*i)++;
		return (-1);
	}
	chars = 0;
	while (!(str[*i] == c) && str[*i])
	{
		chars++;
		(*i)++;
	}
	return (chars);
}

static int	malloc_fill(char **arr, char const *str, char c)
{
	int	i;
	int	chars;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		chars = find_and_count(str, c, &i);
		if (chars == -1)
			continue ;
		arr[k] = malloc(chars + 1);
		if (arr[k] == 0)
		{
			i = 0;
			while (i < k)
				free(arr[i++]);
			free(arr);
			return (0);
		}
		ft_strncpy(arr[k], str + i - chars, chars);
		k++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!malloc_fill(arr, s, c))
		return (NULL);
	arr[count_words(s, c)] = 0;
	return (arr);
}
