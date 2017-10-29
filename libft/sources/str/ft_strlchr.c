/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 23:12:06 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:14:20 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			*ft_strlchr(const char *s, int c)
{
	size_t		index;

	if (s)
	{
		index = ft_strlen(s) - 1;
		while (s[index])
		{
			if (s[index] == (char)c)
				return ((char *)s + index);
			index--;
		}
		if (s[index] == (char)c)
			return ((char *)s + index);
	}
	return (NULL);
}
