/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:26:44 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:29:26 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			*ft_strdup(const char *str)
{
	size_t		index;
	char		*new;

	new = NULL;
	if (str)
	{
		index = 0;
		new = (char*)ft_memalloc(sizeof(char) * (ft_strlen(str) + 1));
		while (str[index])
		{
			new[index] = str[index];
			index++;
		}
	}
	return (new);
}
