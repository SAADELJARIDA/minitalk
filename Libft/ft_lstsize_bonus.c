/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <sel-jari@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:43:16 by sel-jari          #+#    #+#             */
/*   Updated: 2024/10/30 13:48:18 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	list_length;

	list_length = 0;
	while (lst)
	{
		list_length++;
		lst = lst->next;
	}
	return (list_length);
}
