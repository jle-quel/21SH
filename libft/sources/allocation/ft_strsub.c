/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:23:13 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:24:00 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			*ft_strsub(const char *str, size_t start, size_t len)
{
	size_t		index;
	char		*new;

	new = NULL;
	if (str && len > 0)
	{
		index = 0;
		new = (char*)ft_memalloc(sizeof(char) * (len + 1));
		while (len--)
			new[index++] = str[start++];
	}
	return (new);
}
