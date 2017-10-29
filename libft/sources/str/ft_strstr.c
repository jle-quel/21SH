/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 18:41:05 by jle-quel          #+#    #+#             */
/*   Updated: 2017/10/28 23:10:36 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
*************** PUBLIC *********************************************************
*/

char			*ft_strstr(const char *big, const char *little)
{
	int		index;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		index = 0;
		while (*big == *little)
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
