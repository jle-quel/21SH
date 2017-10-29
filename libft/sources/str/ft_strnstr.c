/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:47:15 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/16 14:50:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			*ft_strnstr(const char *big, const char *little, size_t n)
{
	int			index;
	const char	*len;

	len = big + n;
	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0' && big < len)
	{
		index = 0;
		while (*big == *little && big < len)
		{
			little++;
			big++;
			index++;
			if (*little == '\0')
				return ((char*)(big - index));
		}
		big = big - index;
		little = little - index;
		big++;
	}
	return (NULL);
}
