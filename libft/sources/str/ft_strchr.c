/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:12:44 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:14:33 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			*ft_strchr(const char *s, int c)
{
	size_t		index;

	if (s)
	{
		index = 0;
		while (s[index] != '\0')
		{
			if (s[index] == (char)c)
				return ((char *)s + index);
			index++;
		}
		if (s[index] == (char)c)
			return ((char *)s + index);
	}
	return (NULL);
}
